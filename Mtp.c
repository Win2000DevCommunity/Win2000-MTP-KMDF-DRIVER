/*
 * Mtp.c - Dynamic MTP logic with synchronized in-memory store and chunked transfers.
 */

#include <ntddk.h>

#if (_WIN32_WINNT == 0x0500)
// Only include compatibility layer for Windows 2000 DDK
#include "w2k_compat.h"
#endif
#include <wdf.h>
#include "Usb.h"
#include "Mtp.h"

typedef struct _MTP_OBJECT {
    LIST_ENTRY Link;
    ULONG Id;
    ULONG Size;       // valid data size
    ULONG AllocSize;  // allocated buffer size
    CHAR  Name[64];
    PVOID Data;
    USHORT Format;    // MTP format (0x3004=Text, 0x3001=Folder, 0x3801=JPEG, 0x3009=MP3)
    ULONG ParentId;   // parent object handle (0=root)
} MTP_OBJECT, *PMTP_OBJECT;

static LIST_ENTRY gObjectList;
static WDFSPINLOCK gObjectLock;
static ULONG gNextObjectId = 1;

PVOID MtpBuildOperationContainer(IN USHORT Opcode, IN ULONG *Params, IN ULONG ParamCount, OUT PULONG OutLen, OUT PULONG OutTid);

/* When TRUE, a real USB MTP/PTP device is connected and responding.
 * In this mode, we bypass the in-memory fake catalog for data operations
 * (GetObjectPart, GetObject, GetObjectInfo, GetObjectHandles) and relay
 * everything to the real device.  This prevents handle collisions where
 * real device handles (which start at 1) match fake catalog IDs.          */
static BOOLEAN g_bRealDevicePresent = FALSE;

/* Active download streaming context */
static ULONG     g_ActiveDownloadId = 0;
static ULONGLONG g_ActiveDownloadOffset = 0;
static ULONGLONG g_ActiveDownloadTotal = 0;
static ULONGLONG g_ActiveDownloadRemaining = 0;
static PUCHAR    g_ActiveDownloadBuf = NULL;
static ULONG     g_ActiveDownloadBufLen = 0;
static ULONG     g_ActiveDownloadBufPos = 0;

/* Active upload streaming context */
static ULONG     g_ActiveUploadId = 0;
static ULONGLONG g_ActiveUploadOffset = 0;
static ULONGLONG g_ActiveUploadTotal = 0;
static ULONG     g_ActiveUploadTid = 0;

/*
 * Upload data-phase alignment carry buffer.
 *
 * The MTP responder (and QEMU's usb-mtp in particular) detects the end of the
 * SendObject data phase from the first short USB packet (a transfer whose last
 * packet is not a full max-packet). Because the GUI streams the object in
 * several IOCTL chunks and the data phase is prefixed by a 12-byte container
 * header, a naive "one WriteBulk per chunk" would emit a short packet after the
 * very first chunk and the responder would terminate the transfer early.
 *
 * To avoid that we only ever hand the pipe max-packet-aligned writes until the
 * final bytes of the object, holding any sub-packet remainder here between
 * calls. The final flush emits the trailing short packet (or an explicit ZLP
 * when the grand total is an exact multiple of the max-packet size).
 */
#define MTP_MAX_PKT_CAP 1024
static UCHAR     g_UploadCarry[MTP_MAX_PKT_CAP];
static ULONG     g_UploadCarryLen = 0;
static ULONG     g_UploadMaxPkt = 64;

VOID
MtpResetStreaming(VOID)
{
    if (g_ActiveDownloadBuf) {
        ExFreePoolWithTag(g_ActiveDownloadBuf, 'rmtp');
        g_ActiveDownloadBuf = NULL;
    }
    g_ActiveDownloadId = 0;
    g_ActiveDownloadOffset = 0;
    g_ActiveDownloadTotal = 0;
    g_ActiveDownloadRemaining = 0;
    g_ActiveDownloadBufLen = 0;
    g_ActiveDownloadBufPos = 0;

    g_ActiveUploadId = 0;
    g_ActiveUploadOffset = 0;
    g_ActiveUploadTotal = 0;
    g_ActiveUploadTid = 0;

    g_UploadCarryLen = 0;
    g_UploadMaxPkt = 64;
}

/*
 * Append a blob to the SendObject data-phase stream, emitting only
 * max-packet-aligned bulk writes until Final. On the final call the remaining
 * bytes are flushed (producing the terminating short packet) and, if the total
 * stream length is an exact multiple of the max-packet size, a ZLP is sent.
 *
 * Buffered state (g_UploadCarry/g_UploadCarryLen) persists across the multiple
 * SEND_OBJECT_PART IOCTLs that make up one object.
 */
static NTSTATUS
MtpUploadStreamWrite(
    IN WDFDEVICE Device,
    IN WDFUSBPIPE OutPipe,
    IN PVOID Blob,
    IN ULONG BlobLen,
    IN BOOLEAN Final,
    IN ULONGLONG TotalStreamLen
    )
{
    NTSTATUS status = STATUS_SUCCESS;
    ULONG maxPkt = g_UploadMaxPkt;
    ULONG combined;
    PUCHAR buf;

    if (maxPkt == 0 || maxPkt > MTP_MAX_PKT_CAP) maxPkt = 64;

    combined = g_UploadCarryLen + BlobLen;

    if (!Final) {
        ULONG flushLen = (combined / maxPkt) * maxPkt; /* aligned portion */
        ULONG keep = combined - flushLen;              /* remainder (< maxPkt) */

        if (flushLen > 0) {
            buf = (PUCHAR)ExAllocatePoolWithTag(NonPagedPool, flushLen, 'umtp');
            if (!buf) return STATUS_INSUFFICIENT_RESOURCES;
            if (g_UploadCarryLen) {
                ULONG fromCarry = (g_UploadCarryLen < flushLen) ? g_UploadCarryLen : flushLen;
                RtlCopyMemory(buf, g_UploadCarry, fromCarry);
            }
            if (flushLen > g_UploadCarryLen) {
                RtlCopyMemory(buf + g_UploadCarryLen, Blob, flushLen - g_UploadCarryLen);
            }
            status = MtpUsb_WriteBulk(Device, OutPipe, buf, flushLen);
            ExFreePoolWithTag(buf, 'umtp');
            if (!NT_SUCCESS(status)) return status;
        }

        /* Stash the trailing `keep` bytes (last bytes of carry ++ blob).
         * keep < maxPkt <= MTP_MAX_PKT_CAP, so this fits in `tail` regardless
         * of how large `combined` is. */
        if (keep > 0) {
            UCHAR tail[MTP_MAX_PKT_CAP];
            ULONG start = combined - keep;
            ULONG t = 0;
            ULONG i;
            for (i = start; i < combined; i++) {
                tail[t++] = (i < g_UploadCarryLen)
                                ? g_UploadCarry[i]
                                : ((PUCHAR)Blob)[i - g_UploadCarryLen];
            }
            RtlCopyMemory(g_UploadCarry, tail, keep);
        }
        g_UploadCarryLen = keep;
        return STATUS_SUCCESS;
    }

    /* Final flush: one write with everything left. */
    if (combined > 0) {
        buf = (PUCHAR)ExAllocatePoolWithTag(NonPagedPool, combined, 'umtp');
        if (!buf) return STATUS_INSUFFICIENT_RESOURCES;
        if (g_UploadCarryLen) RtlCopyMemory(buf, g_UploadCarry, g_UploadCarryLen);
        RtlCopyMemory(buf + g_UploadCarryLen, Blob, BlobLen);
        status = MtpUsb_WriteBulk(Device, OutPipe, buf, combined);
        ExFreePoolWithTag(buf, 'umtp');
        g_UploadCarryLen = 0;
        if (!NT_SUCCESS(status)) return status;
    }
    g_UploadCarryLen = 0;

    /* If the whole stream was max-packet aligned, no short packet was emitted;
     * send a ZLP so the responder ends the data phase. */
    if ((TotalStreamLen % maxPkt) == 0) {
        status = MtpUsb_WriteZlp(Device, OutPipe);
    }
    return status;
}

static VOID
MtpAddInitialObject(ULONG Id, const char *Name, USHORT Format, ULONG ParentId, const char *InitialData, ULONG DataLen)
{
    PMTP_OBJECT obj = (PMTP_OBJECT)ExAllocatePoolWithTag(NonPagedPool, sizeof(MTP_OBJECT), 'mtpO');
    if (!obj) return;
    RtlZeroMemory(obj, sizeof(*obj));
    obj->Id = Id;
    obj->Format = Format;
    obj->ParentId = ParentId;
    obj->Size = DataLen;
    obj->AllocSize = (DataLen > 0) ? DataLen : 64;
    strncpy(obj->Name, Name, sizeof(obj->Name) - 1);
    obj->Data = ExAllocatePoolWithTag(NonPagedPool, obj->AllocSize, 'mtpD');
    if (obj->Data && DataLen > 0 && InitialData) {
        RtlCopyMemory(obj->Data, InitialData, DataLen);
    }
    WdfSpinLockAcquire(gObjectLock);
    InsertTailList(&gObjectList, &obj->Link);
    WdfSpinLockRelease(gObjectLock);
    if (Id >= gNextObjectId) gNextObjectId = Id + 1;
}

// Response queue for responses from USB device
typedef struct _MTP_RESPONSE_ENTRY {
    LIST_ENTRY Link;
    ULONG ContainerType;    // 1=Operation, 2=Data, 3=Response, 4=Event
    USHORT Code;            // opcode or response code
    ULONG TransactionId;
    size_t DataLength;      // payload length (after the 12-byte header)
    PVOID Data;             // payload copy (may be NULL)
} MTP_RESPONSE_ENTRY, *PMTP_RESPONSE_ENTRY;

static LIST_ENTRY gResponseList;
static WDFSPINLOCK gResponseLock;
static KEVENT gResponseEvent;

// Global transaction counter for building operation containers
static volatile LONG gTransactionCounter = 0;

// Parse a raw MTP container buffer and populate an allocated response entry.
// Returns TRUE on success and sets *BytesConsumed to the number of bytes consumed.
// Caller must free entry (and Data) using ExFreePoolWithTag when done.
static BOOLEAN
MtpParseContainerAndCreateEntry(IN PVOID Buffer, IN size_t Length, OUT PMTP_RESPONSE_ENTRY *EntryOut, OUT size_t *BytesConsumed)
{
    ULONG totalLen;
    USHORT type;
    USHORT code;
    ULONG tid;
    const ULONG MAX_MTP_CONTAINER_SIZE = (16 * 1024 * 1024); /* 16 MiB */
    PMTP_RESPONSE_ENTRY e;
    size_t dataLen;
    
    if (Length < 12 || Buffer == NULL || EntryOut == NULL || BytesConsumed == NULL) return FALSE;
    *EntryOut = NULL;
    *BytesConsumed = 0;

    // Read header fields safely to avoid unaligned access and validate size
    totalLen = 0;
    type = 0;
    code = 0;
    tid = 0;
    RtlCopyMemory(&totalLen, Buffer, sizeof(totalLen));
    RtlCopyMemory(&type, (PUCHAR)Buffer + 4, sizeof(type));
    RtlCopyMemory(&code, (PUCHAR)Buffer + 6, sizeof(code));
    RtlCopyMemory(&tid, (PUCHAR)Buffer + 8, sizeof(tid));

    // Validate the announced totalLen and cap to defensive limit
    if (totalLen < 12) return FALSE; // invalid header
    if (totalLen > MAX_MTP_CONTAINER_SIZE) return FALSE;

    e = (PMTP_RESPONSE_ENTRY)ExAllocatePoolWithTag(NonPagedPool, sizeof(MTP_RESPONSE_ENTRY), 'rmtp');
    if (!e) return FALSE;
    RtlZeroMemory(e, sizeof(*e));

    e->ContainerType = type;
    e->Code = code;
    e->TransactionId = tid;

    if (totalLen <= (ULONG)Length) {
        dataLen = (size_t)(totalLen - 12);
        *BytesConsumed = (size_t)totalLen;
    } else {
        dataLen = Length - 12;
        *BytesConsumed = Length;
    }

    e->DataLength = dataLen;
    e->Data = NULL;

    if (e->DataLength > 0) {
        e->Data = ExAllocatePoolWithTag(NonPagedPool, e->DataLength, 'rmtp');
        if (!e->Data) {
            ExFreePoolWithTag(e, 'rmtp');
            *EntryOut = NULL;
            return FALSE;
        }
        RtlCopyMemory(e->Data, (PUCHAR)Buffer + 12, e->DataLength);
    }

    *EntryOut = e;
    return TRUE;
}

NTSTATUS
MtpInitializeDevice(WDFDEVICE Device)
{
    WDF_OBJECT_ATTRIBUTES attr;
    NTSTATUS status;

    UNREFERENCED_PARAMETER(Device);

    InitializeListHead(&gObjectList);

    WDF_OBJECT_ATTRIBUTES_INIT(&attr);
    attr.ParentObject = Device;

    status = WdfSpinLockCreate(&attr, &gObjectLock);
    if (!NT_SUCCESS(status)) {
        KdPrint(("MTP: WdfSpinLockCreate failed 0x%08x\n", status));
        return status;
    }

    // Create response list and lock
    WDF_OBJECT_ATTRIBUTES_INIT(&attr);
    attr.ParentObject = Device;
    status = WdfSpinLockCreate(&attr, &gResponseLock);
    if (!NT_SUCCESS(status)) {
        KdPrint(("MTP: WdfSpinLockCreate (response) failed 0x%08x\n", status));
        return status;
    }
    InitializeListHead(&gResponseList);
    KeInitializeEvent(&gResponseEvent, NotificationEvent, FALSE);

    /* Initially assume no real device is present (will be set TRUE in OpenSession
     * when USB pipes respond successfully to MTP OpenSession command). */
    g_bRealDevicePresent = FALSE;

    /* Pre-populate standard phone storage objects as fallback
     * (only used when NO real USB device responds, i.e. pure emulation mode). */
    MtpAddInitialObject(1, "Welcome_Phone.txt", 0x3004, 0, "Welcome to Windows 2000 MTP Driver!\r\nPhone storage connected.\r\n", 58);
    MtpAddInitialObject(2, "DCIM", 0x3001, 0, NULL, 0);
    MtpAddInitialObject(3, "Documents", 0x3001, 0, NULL, 0);
    MtpAddInitialObject(4, "Music", 0x3001, 0, NULL, 0);
    MtpAddInitialObject(5, "notes.txt", 0x3004, 0, "Meeting notes and reminders.\r\n", 30);
    MtpAddInitialObject(6, "photo1.jpg", 0x3801, 2, "JPEG_DUMMY_IMAGE_DATA_0123456789", 32);
    MtpAddInitialObject(7, "song.mp3", 0x3009, 4, "MP3_AUDIO_STREAM_DATA_0123456789", 32);

    return STATUS_SUCCESS;
}

static PMTP_OBJECT
MtpFindObject(ULONG Id)
{
    PLIST_ENTRY entry;
    PMTP_OBJECT found = NULL;

    WdfSpinLockAcquire(gObjectLock);
    for (entry = gObjectList.Flink; entry != &gObjectList; entry = entry->Flink) {
        PMTP_OBJECT obj = CONTAINING_RECORD(entry, MTP_OBJECT, Link);
        if (obj->Id == Id) { found = obj; break; }
    }
    WdfSpinLockRelease(gObjectLock);
    return found;
}

NTSTATUS
MtpGetDeviceInfo(WDFREQUEST Request)
{
    WDFDEVICE device;
    PVOID data;
    size_t dlen;
    USHORT respCode;
    NTSTATUS status;
    PVOID outBuf;
    size_t outCap;
    size_t toCopy;

    device = WdfRequestGetDevice(Request);
    data = NULL;
    dlen = 0;
    respCode = 0;
    status = MtpSendOperationAndReceiveData(device, 0x1001, NULL, 0, NULL, 0, &data, &dlen, &respCode);
    if (!NT_SUCCESS(status) || !data || dlen == 0) {
        UCHAR devInfo[128];
        if (data) ExFreePoolWithTag(data, 'dout');
        status = WdfRequestRetrieveOutputBuffer(Request, 1, &outBuf, &outCap);
        if (!NT_SUCCESS(status)) { WdfRequestComplete(Request, status); return status; }
        RtlZeroMemory(devInfo, sizeof(devInfo));
        *((PUSHORT)(devInfo + 0)) = 100; // StandardVersion
        *((PULONG)(devInfo + 2)) = 6;    // MTP VendorExtension
        *((PUSHORT)(devInfo + 6)) = 100; // MTP Version
        toCopy = (sizeof(devInfo) < outCap) ? sizeof(devInfo) : outCap;
        RtlCopyMemory(outBuf, devInfo, toCopy);
        WdfRequestCompleteWithInformation(Request, STATUS_SUCCESS, toCopy);
        return STATUS_SUCCESS;
    }

    status = WdfRequestRetrieveOutputBuffer(Request, 1, &outBuf, &outCap);
    if (!NT_SUCCESS(status)) { if (data) ExFreePoolWithTag(data, 'dout'); WdfRequestComplete(Request, status); return status; }

    toCopy = (dlen < outCap) ? dlen : outCap;
    RtlCopyMemory(outBuf, data, toCopy);
    ExFreePoolWithTag(data, 'dout');

    WdfRequestCompleteWithInformation(Request, STATUS_SUCCESS, toCopy);
    return STATUS_SUCCESS;
}

NTSTATUS
MtpListObjects(WDFREQUEST Request)
{
    WDFDEVICE device;
    ULONG params[3];
    PVOID data;
    size_t dlen;
    USHORT respCode;
    NTSTATUS status;
    ULONG count;
    PULONG handles;
    ULONG available;
    PVOID outBuf;
    size_t outCap;
    ULONG toCopy;

    device = WdfRequestGetDevice(Request);
    params[0] = 0xFFFFFFFF;
    params[1] = 0;
    params[2] = 0;
    data = NULL;
    dlen = 0;
    respCode = 0;
    status = MtpSendOperationAndReceiveData(device, 0x1007, params, 3, NULL, 0, &data, &dlen, &respCode);
    if (!NT_SUCCESS(status) || !data || dlen < sizeof(ULONG)) {
        PLIST_ENTRY entry;
        PMTP_OBJECT objEntry;
        if (data) ExFreePoolWithTag(data, 'dout');
        status = WdfRequestRetrieveOutputBuffer(Request, sizeof(ULONG), &outBuf, &outCap);
        if (!NT_SUCCESS(status)) { WdfRequestComplete(Request, status); return status; }
        count = 0;
        handles = (PULONG)outBuf;
        WdfSpinLockAcquire(gObjectLock);
        for (entry = gObjectList.Flink; entry != &gObjectList; entry = entry->Flink) {
            if ((count + 1) * sizeof(ULONG) <= outCap) {
                objEntry = CONTAINING_RECORD(entry, MTP_OBJECT, Link);
                handles[count] = objEntry->Id;
                count++;
            }
        }
        WdfSpinLockRelease(gObjectLock);
        WdfRequestCompleteWithInformation(Request, STATUS_SUCCESS, count * sizeof(ULONG));
        return STATUS_SUCCESS;
    }

    count = *((PULONG)data);
    handles = (PULONG)((PUCHAR)data + sizeof(ULONG));
    available = (ULONG)((dlen - sizeof(ULONG)) / sizeof(ULONG));
    if (count > available) count = available;

    status = WdfRequestRetrieveOutputBuffer(Request, sizeof(ULONG), &outBuf, &outCap);
    if (!NT_SUCCESS(status)) { ExFreePoolWithTag(data, 'dout'); WdfRequestComplete(Request, status); return status; }

    toCopy = (count * sizeof(ULONG) < outCap) ? (count * sizeof(ULONG)) : (ULONG)outCap;
    RtlCopyMemory(outBuf, handles, toCopy);
    ExFreePoolWithTag(data, 'dout');

    WdfRequestCompleteWithInformation(Request, STATUS_SUCCESS, toCopy);
    return STATUS_SUCCESS;
}

NTSTATUS
MtpGetObjectPart(WDFREQUEST Request)
{
    PVOID inBuf;
    size_t inLen;
    ULONG id;
    ULONG offsetLow;
    ULONG offsetHigh;
    ULONG length;
    ULONGLONG offset;
    NTSTATUS status;
    PVOID outBuf;
    size_t outCap;
    PMTP_OBJECT obj;
    ULONG toCopy;
    WDFDEVICE device;
    WDFUSBPIPE inPipe;
    WDFUSBPIPE outPipe;

    status = WdfRequestRetrieveInputBuffer(Request, sizeof(ULONG) * 3, &inBuf, &inLen);
    if (!NT_SUCCESS(status)) { WdfRequestComplete(Request, status); return status; }

    status = WdfRequestRetrieveOutputBuffer(Request, 1, &outBuf, &outCap);
    if (!NT_SUCCESS(status)) { WdfRequestComplete(Request, status); return status; }

    id = *((PULONG)inBuf + 0);
    offsetLow = *((PULONG)inBuf + 1);
    
    if (inLen >= sizeof(ULONG) * 4) {
        /* Modern 64-bit request struct */
        offsetHigh = *((PULONG)inBuf + 2);
        length = *((PULONG)inBuf + 3);
    } else {
        /* Legacy 32-bit request struct */
        offsetHigh = 0;
        length = *((PULONG)inBuf + 2);
    }

    offset = ((ULONGLONG)offsetHigh << 32) | (ULONGLONG)offsetLow;

    /* When no real device is present, use in-memory emulation catalog */
    if (!g_bRealDevicePresent) {
        obj = MtpFindObject(id);
        if (obj) {
            if (offset >= (ULONGLONG)obj->Size) {
                WdfRequestComplete(Request, STATUS_END_OF_FILE);
                return STATUS_END_OF_FILE;
            }

            toCopy = length;
            if (offset + toCopy > (ULONGLONG)obj->Size) {
                toCopy = (ULONG)((ULONGLONG)obj->Size - offset);
            }
            if (toCopy > outCap) toCopy = (ULONG)outCap;

            WdfSpinLockAcquire(gObjectLock);
            RtlCopyMemory(outBuf, (PUCHAR)obj->Data + offset, toCopy);
            WdfSpinLockRelease(gObjectLock);

            WdfRequestCompleteWithInformation(Request, STATUS_SUCCESS, toCopy);
            return STATUS_SUCCESS;
        }
        WdfRequestComplete(Request, STATUS_NOT_FOUND);
        return STATUS_NOT_FOUND;
    }

    /* Real USB MTP device: Stream directly from Bulk IN pipe!
     * Universal compatibility: uses standard MTP GetObject (0x1009).
     * Chunk-by-chunk streaming with O(1) kernel memory. */
    device = WdfRequestGetDevice(Request);
    inPipe = MtpUsb_GetBulkInPipe(device);
    outPipe = MtpUsb_GetBulkOutPipe(device);
    if (!inPipe || !outPipe) {
        WdfRequestComplete(Request, STATUS_INVALID_DEVICE_STATE);
        return STATUS_INVALID_DEVICE_STATE;
    }

    if (offset == 0) {
        ULONG opLen = 0;
        ULONG tid = 0;
        PVOID opBuf = NULL;
        ULONG bytesRead = 0;
        ULONG containerLen = 0;
        USHORT containerType = 0;
        USHORT containerCode = 0;
        ULONGLONG totalPayload = 0;
        ULONG avail = 0;

        /* Reset any prior download */
        if (g_ActiveDownloadBuf) {
            ExFreePoolWithTag(g_ActiveDownloadBuf, 'rmtp');
            g_ActiveDownloadBuf = NULL;
        }
        g_ActiveDownloadId = 0;

        /* Send MTP_OP_GET_OBJECT (0x1009) */
        opBuf = MtpBuildOperationContainer(MTP_OP_GET_OBJECT, &id, 1, &opLen, &tid);
        if (!opBuf) {
            WdfRequestComplete(Request, STATUS_INSUFFICIENT_RESOURCES);
            return STATUS_INSUFFICIENT_RESOURCES;
        }

        status = MtpUsb_WriteBulk(device, outPipe, opBuf, opLen);
        ExFreePoolWithTag(opBuf, 'omtp');
        if (!NT_SUCCESS(status)) {
            KdPrint(("MTP: GetObject WriteBulk failed 0x%08x\n", status));
            WdfRequestComplete(Request, status);
            return status;
        }

        /* Allocate 64KB read buffer */
        g_ActiveDownloadBuf = (PUCHAR)ExAllocatePoolWithTag(NonPagedPool, 65536, 'rmtp');
        if (!g_ActiveDownloadBuf) {
            WdfRequestComplete(Request, STATUS_INSUFFICIENT_RESOURCES);
            return STATUS_INSUFFICIENT_RESOURCES;
        }

        /* Read first packet (DATA container header + first chunk) */
        status = MtpUsb_ReadBulk(device, inPipe, g_ActiveDownloadBuf, 65536, &bytesRead);
        if (!NT_SUCCESS(status) || bytesRead < 12) {
            KdPrint(("MTP: GetObject ReadBulk failed 0x%08x (bytes=%lu)\n", status, bytesRead));
            ExFreePoolWithTag(g_ActiveDownloadBuf, 'rmtp');
            g_ActiveDownloadBuf = NULL;
            WdfRequestComplete(Request, NT_SUCCESS(status) ? STATUS_DEVICE_DATA_ERROR : status);
            return NT_SUCCESS(status) ? STATUS_DEVICE_DATA_ERROR : status;
        }

        RtlCopyMemory(&containerLen, g_ActiveDownloadBuf, sizeof(ULONG));
        RtlCopyMemory(&containerType, g_ActiveDownloadBuf + 4, sizeof(USHORT));
        RtlCopyMemory(&containerCode, g_ActiveDownloadBuf + 6, sizeof(USHORT));

        if (containerType == 3) {
            /* Device returned error response code directly (e.g. 0x2009 InvalidObjectHandle) */
            KdPrint(("MTP: GetObject device returned error code 0x%04x\n", (ULONG)containerCode));
            ExFreePoolWithTag(g_ActiveDownloadBuf, 'rmtp');
            g_ActiveDownloadBuf = NULL;
            WdfRequestComplete(Request, STATUS_NOT_FOUND);
            return STATUS_NOT_FOUND;
        }

        /* containerType == 2 is Data container */
        totalPayload = (containerLen >= 12) ? (containerLen - 12) : 0;
        if (containerLen == 0xFFFFFFFF) {
            totalPayload = 0xFFFFFFFFFFFFFFFFULL; /* Unspecified length streaming */
        }

        avail = bytesRead - 12;
        toCopy = length;
        if ((ULONGLONG)toCopy > (ULONGLONG)outCap) toCopy = (ULONG)outCap;
        if ((ULONGLONG)toCopy > (ULONGLONG)avail) toCopy = avail;

        RtlCopyMemory(outBuf, g_ActiveDownloadBuf + 12, toCopy);

        g_ActiveDownloadId = id;
        g_ActiveDownloadTotal = totalPayload;
        g_ActiveDownloadOffset = toCopy;
        g_ActiveDownloadRemaining = (totalPayload > (ULONGLONG)toCopy) ? (totalPayload - (ULONGLONG)toCopy) : 0;

        if (avail > toCopy) {
            g_ActiveDownloadBufPos = 12 + toCopy;
            g_ActiveDownloadBufLen = bytesRead;
        } else {
            g_ActiveDownloadBufPos = 0;
            g_ActiveDownloadBufLen = 0;
        }

        /* If whole file fit in the first read */
        if (g_ActiveDownloadRemaining == 0) {
            if (bytesRead <= 12 + toCopy) {
                ULONG respBytes = 0;
                MtpUsb_ReadBulk(device, inPipe, g_ActiveDownloadBuf, 512, &respBytes);
            }
            ExFreePoolWithTag(g_ActiveDownloadBuf, 'rmtp');
            g_ActiveDownloadBuf = NULL;
            g_ActiveDownloadId = 0;
        }

        WdfRequestCompleteWithInformation(Request, STATUS_SUCCESS, toCopy);
        return STATUS_SUCCESS;
    }

    /* offset > 0: continuation of active stream */
    if (id == g_ActiveDownloadId && offset == g_ActiveDownloadOffset) {
        ULONG avail = 0;

        /* If buffer is empty but more data remains, refill 64KB staging buffer from USB Bulk IN */
        if (g_ActiveDownloadBuf && g_ActiveDownloadBufPos >= g_ActiveDownloadBufLen && g_ActiveDownloadRemaining > 0) {
            ULONG bytesRead = 0;
            status = MtpUsb_ReadBulk(device, inPipe, g_ActiveDownloadBuf, 65536, &bytesRead);
            if (!NT_SUCCESS(status) || bytesRead == 0) {
                KdPrint(("MTP: Stream ReadBulk refill failed 0x%08x\n", status));
                MtpResetStreaming();
                WdfRequestComplete(Request, NT_SUCCESS(status) ? STATUS_END_OF_FILE : status);
                return NT_SUCCESS(status) ? STATUS_END_OF_FILE : status;
            }
            g_ActiveDownloadBufPos = 0;
            g_ActiveDownloadBufLen = bytesRead;
        }

        /* If we have available bytes in the staging buffer */
        if (g_ActiveDownloadBuf && g_ActiveDownloadBufLen > g_ActiveDownloadBufPos) {
            avail = g_ActiveDownloadBufLen - g_ActiveDownloadBufPos;
            toCopy = length;
            if ((ULONGLONG)toCopy > (ULONGLONG)outCap) toCopy = (ULONG)outCap;
            if ((ULONGLONG)toCopy > (ULONGLONG)avail) toCopy = avail;
            if ((ULONGLONG)toCopy > g_ActiveDownloadRemaining) toCopy = (ULONG)g_ActiveDownloadRemaining;

            RtlCopyMemory(outBuf, g_ActiveDownloadBuf + g_ActiveDownloadBufPos, toCopy);
            g_ActiveDownloadBufPos += toCopy;
            g_ActiveDownloadOffset += toCopy;
            if (g_ActiveDownloadRemaining >= (ULONGLONG)toCopy) {
                g_ActiveDownloadRemaining -= (ULONGLONG)toCopy;
            } else {
                g_ActiveDownloadRemaining = 0;
            }

            /* If download finished, read RESPONSE container if needed and cleanup */
            if (g_ActiveDownloadRemaining == 0) {
                if (g_ActiveDownloadBufPos >= g_ActiveDownloadBufLen) {
                    ULONG respBytes = 0;
                    MtpUsb_ReadBulk(device, inPipe, g_ActiveDownloadBuf, 512, &respBytes);
                }
                ExFreePoolWithTag(g_ActiveDownloadBuf, 'rmtp');
                g_ActiveDownloadBuf = NULL;
                g_ActiveDownloadId = 0;
            }

            WdfRequestCompleteWithInformation(Request, STATUS_SUCCESS, toCopy);
            return STATUS_SUCCESS;
        }

        /* If no more data remaining */
        if (g_ActiveDownloadRemaining == 0) {
            MtpResetStreaming();
            WdfRequestComplete(Request, STATUS_END_OF_FILE);
            return STATUS_END_OF_FILE;
        }
    }

    /* Out of order or unexpected ID */
    MtpResetStreaming();
    WdfRequestComplete(Request, STATUS_INVALID_PARAMETER);
    return STATUS_INVALID_PARAMETER;
}

// Input for send object part: [ULONG Id][ULONG Offset][ULONG TotalSize][data...]
NTSTATUS
MtpSendObjectPart(WDFREQUEST Request)
{
    PVOID inBuf;
    size_t inLen;
    NTSTATUS status;
    PULONG p;
    ULONG id;
    ULONG offset;
    ULONG totalSize = 0;
    PVOID data;
    ULONG dataLen;
    PMTP_OBJECT obj;
    PVOID outBuf;
    size_t outCap;
    WDFDEVICE device;
    WDFUSBPIPE outPipe;
    WDFUSBPIPE inPipe;

    status = WdfRequestRetrieveInputBuffer(Request, sizeof(ULONG) * 2 + 1, &inBuf, &inLen);
    if (!NT_SUCCESS(status)) { WdfRequestComplete(Request, status); return status; }

    p = (PULONG)inBuf;
    id = p[0];
    offset = p[1];

    if (inLen >= sizeof(ULONG) * 3) {
        totalSize = p[2];
        data = (PVOID)((PUCHAR)inBuf + sizeof(ULONG) * 3);
        dataLen = (ULONG)(inLen - sizeof(ULONG) * 3);
    } else {
        totalSize = 0;
        data = (PVOID)((PUCHAR)inBuf + sizeof(ULONG) * 2);
        dataLen = (ULONG)(inLen - sizeof(ULONG) * 2);
    }

    /* If no real device, fallback to in-memory catalog */
    if (!g_bRealDevicePresent) {
        if (id == 0 && offset == 0) {
            obj = (PMTP_OBJECT)ExAllocatePoolWithTag(NonPagedPool, sizeof(MTP_OBJECT), 'mtpO');
            if (!obj) { WdfRequestComplete(Request, STATUS_INSUFFICIENT_RESOURCES); return STATUS_INSUFFICIENT_RESOURCES; }
            RtlZeroMemory(obj, sizeof(*obj));
            obj->Id = gNextObjectId++;
            obj->AllocSize = dataLen ? dataLen : 4096;
            obj->Size = dataLen;
            RtlCopyMemory(obj->Name, "uploaded.bin", sizeof("uploaded.bin"));
            obj->Data = ExAllocatePoolWithTag(NonPagedPool, obj->AllocSize, 'mtpD');
            if (!obj->Data) { ExFreePoolWithTag(obj, 'mtpO'); WdfRequestComplete(Request, STATUS_INSUFFICIENT_RESOURCES); return STATUS_INSUFFICIENT_RESOURCES; }
            if (dataLen) RtlCopyMemory(obj->Data, data, dataLen);

            WdfSpinLockAcquire(gObjectLock);
            InsertTailList(&gObjectList, &obj->Link);
            WdfSpinLockRelease(gObjectLock);

            status = WdfRequestRetrieveOutputBuffer(Request, sizeof(ULONG), &outBuf, &outCap);
            if (NT_SUCCESS(status) && outCap >= sizeof(ULONG)) {
                *((PULONG)outBuf) = obj->Id;
                WdfRequestCompleteWithInformation(Request, STATUS_SUCCESS, sizeof(ULONG));
                return STATUS_SUCCESS;
            }
            WdfRequestComplete(Request, STATUS_SUCCESS);
            return STATUS_SUCCESS;
        }

        obj = MtpFindObject(id);
        if (!obj) { WdfRequestComplete(Request, STATUS_NOT_FOUND); return STATUS_NOT_FOUND; }

        WdfSpinLockAcquire(gObjectLock);
        if (offset + dataLen > obj->AllocSize) {
            ULONG newAlloc = max(offset + dataLen, obj->AllocSize * 2);
            PVOID newBuf = ExAllocatePoolWithTag(NonPagedPool, newAlloc, 'mtpD');
            if (!newBuf) { WdfSpinLockRelease(gObjectLock); WdfRequestComplete(Request, STATUS_INSUFFICIENT_RESOURCES); return STATUS_INSUFFICIENT_RESOURCES; }
            if (obj->Data && obj->Size > 0) RtlCopyMemory(newBuf, obj->Data, obj->Size);
            if (obj->Data) ExFreePoolWithTag(obj->Data, 'mtpD');
            obj->Data = newBuf;
            obj->AllocSize = newAlloc;
        }
        if (dataLen) RtlCopyMemory((PUCHAR)obj->Data + offset, data, dataLen);
        if (offset + dataLen > obj->Size) obj->Size = offset + dataLen;
        WdfSpinLockRelease(gObjectLock);

        WdfRequestComplete(Request, STATUS_SUCCESS);
        return STATUS_SUCCESS;
    }

    /* Real USB MTP device: Stream directly to Bulk OUT pipe! */
    device = WdfRequestGetDevice(Request);
    outPipe = MtpUsb_GetBulkOutPipe(device);
    inPipe = MtpUsb_GetBulkInPipe(device);
    if (!outPipe || !inPipe) {
        KdPrint(("MTP: SendObjectPart - no pipes! outPipe=%p inPipe=%p\n", outPipe, inPipe));
        WdfRequestComplete(Request, STATUS_INVALID_DEVICE_STATE);
        return STATUS_INVALID_DEVICE_STATE;
    }

    KdPrint(("MTP: SendObjectPart id=%u offset=%u totalSize=%u dataLen=%u\n", id, offset, totalSize, dataLen));

    if (offset == 0) {
        ULONG opLen = 0;
        ULONG tid = 0;
        PVOID opBuf = NULL;
        PUCHAR headerBuf = NULL;
        ULONG containerTotal = 12 + totalSize;
        ULONGLONG totalStream = (ULONGLONG)12 + (ULONGLONG)totalSize;
        BOOLEAN final;
        PDEVICE_CONTEXT ctx = DeviceGetContext(device);

        g_ActiveUploadId = id;
        g_ActiveUploadTotal = totalSize;
        g_ActiveUploadOffset = 0;

        /* Align all data-phase writes to the endpoint max-packet size so the
         * responder sees a short packet only at the end of the object. */
        g_UploadMaxPkt = (ctx && ctx->MaxPacketSize) ? ctx->MaxPacketSize : 64;
        if (g_UploadMaxPkt == 0 || g_UploadMaxPkt > MTP_MAX_PKT_CAP) g_UploadMaxPkt = 64;
        g_UploadCarryLen = 0;

        /* ---- Drain stale QEMU state before SendObject command phase ----
         *
         * QEMU's usb-mtp responder (hw/usb/dev-mtp.c) checks on every new
         * TYPE_COMMAND whether s->data_in, s->data_out, or s->result is
         * non-NULL. If any of those are set, it stalls the endpoint with
         * "transaction inflight". The preceding SendObjectInfo's response
         * should have been consumed by MtpSendOperationAndReceiveData, but
         * edge cases (timeouts, resets, piggybacked containers) can leave
         * stale data on the Bulk IN pipe. Read-and-discard any residual
         * containers, then reset both endpoints to clear halt conditions. */
        {
            PUCHAR drainBuf = (PUCHAR)ExAllocatePoolWithTag(NonPagedPool, 512, 'drnm');
            if (drainBuf) {
                ULONG drainBytes = 0;
                int drainAttempts = 0;
                while (drainAttempts < 3) {
                    NTSTATUS drainSt = MtpUsb_ReadBulk(device, inPipe, drainBuf, 512, &drainBytes);
                    if (!NT_SUCCESS(drainSt) || drainBytes == 0) break;
                    KdPrint(("MTP: SendObjectPart drain: discarded %u bytes (type=%u code=0x%04x)\n",
                             drainBytes,
                             (drainBytes >= 6) ? (ULONG)*((PUSHORT)(drainBuf + 4)) : 0,
                             (drainBytes >= 8) ? (ULONG)*((PUSHORT)(drainBuf + 6)) : 0));
                    drainAttempts++;
                }
                ExFreePoolWithTag(drainBuf, 'drnm');
            }
        }
        /* Endpoint state is already clean after drain reads above;
         * do NOT reset pipes here — QEMU's usb-mtp treats the resulting
         * CLEAR_FEATURE control request as "unknown control request" and
         * permanently stalls with "transaction inflight".  On real hardware
         * the drain reads above are sufficient to clear residual data. */

        /* Send MTP_OP_SEND_OBJECT (0x100D) command container (its own 12-byte
         * short-packet transfer — this is the command phase, not the data). */
        opBuf = MtpBuildOperationContainer(MTP_OP_SEND_OBJECT, NULL, 0, &opLen, &tid);
        if (!opBuf) {
            WdfRequestComplete(Request, STATUS_INSUFFICIENT_RESOURCES);
            return STATUS_INSUFFICIENT_RESOURCES;
        }
        g_ActiveUploadTid = tid;

        status = MtpUsb_WriteBulk(device, outPipe, opBuf, opLen);
        ExFreePoolWithTag(opBuf, 'omtp');
        if (!NT_SUCCESS(status)) {
            KdPrint(("MTP: SendObject WriteBulk failed 0x%08x\n", status));
            WdfRequestComplete(Request, status);
            return status;
        }

        /* Build DATA container header (12 bytes) + first data chunk, then feed
         * it through the max-packet-aligned streamer. */
        headerBuf = (PUCHAR)ExAllocatePoolWithTag(NonPagedPool, 12 + dataLen, 'dmtp');
        if (!headerBuf) {
            WdfRequestComplete(Request, STATUS_INSUFFICIENT_RESOURCES);
            return STATUS_INSUFFICIENT_RESOURCES;
        }

        *((PULONG)(headerBuf + 0)) = containerTotal;
        *((PUSHORT)(headerBuf + 4)) = 2; // Data container
        *((PUSHORT)(headerBuf + 6)) = MTP_OP_SEND_OBJECT;
        *((PULONG)(headerBuf + 8)) = g_ActiveUploadTid;
        if (dataLen > 0) RtlCopyMemory(headerBuf + 12, data, dataLen);

        final = ((ULONGLONG)dataLen >= g_ActiveUploadTotal);
        status = MtpUploadStreamWrite(device, outPipe, headerBuf, 12 + dataLen, final, totalStream);
        ExFreePoolWithTag(headerBuf, 'dmtp');
        if (!NT_SUCCESS(status)) {
            KdPrint(("MTP: SendObject Data header WriteBulk failed 0x%08x\n", status));
            WdfRequestComplete(Request, status);
            return status;
        }

        g_ActiveUploadOffset = dataLen;
    } else {
        /* offset > 0: stream subsequent data chunks */
        if (dataLen > 0) {
            ULONGLONG totalStream = (ULONGLONG)12 + g_ActiveUploadTotal;
            BOOLEAN final = ((g_ActiveUploadOffset + dataLen) >= g_ActiveUploadTotal);
            status = MtpUploadStreamWrite(device, outPipe, data, dataLen, final, totalStream);
            if (!NT_SUCCESS(status)) {
                KdPrint(("MTP: SendObject chunk WriteBulk failed 0x%08x\n", status));
                WdfRequestComplete(Request, status);
                return status;
            }
            g_ActiveUploadOffset += dataLen;
        }
    }

    /* Check if transfer is complete. The data phase was already terminated
     * (short packet or ZLP) by the final MtpUploadStreamWrite call above. */
    if (g_ActiveUploadOffset >= g_ActiveUploadTotal) {
        /* Read RESPONSE container from Bulk IN */
        {
            PUCHAR respBuf = (PUCHAR)ExAllocatePoolWithTag(NonPagedPool, 512, 'rmtp');
            if (respBuf) {
                ULONG respBytes = 0;
                NTSTATUS readSt = MtpUsb_ReadBulk(device, inPipe, respBuf, 512, &respBytes);
                if (NT_SUCCESS(readSt) && respBytes >= 12) {
                    USHORT respCode = *((PUSHORT)(respBuf + 6));
                    KdPrint(("MTP: SendObject response: code=0x%04x bytes=%u\n", respCode, respBytes));
                } else {
                    KdPrint(("MTP: SendObject response read failed: 0x%08x bytes=%u\n", readSt, respBytes));
                }
                ExFreePoolWithTag(respBuf, 'rmtp');
            }
        }
        MtpResetStreaming();
    }

    WdfRequestComplete(Request, STATUS_SUCCESS);
    return STATUS_SUCCESS;
}


VOID
MtpUsb_OnDataReceived(IN WDFDEVICE Device, IN PVOID Data, IN size_t Length)
{
    PUCHAR ptr;
    size_t remaining;

    UNREFERENCED_PARAMETER(Device);
    if (Length == 0 || Data == NULL) return;

    ptr = (PUCHAR)Data;
    remaining = Length;

    while (remaining >= 12) {
        PMTP_RESPONSE_ENTRY entry = NULL;
        size_t consumed = 0;

        if (!MtpParseContainerAndCreateEntry(ptr, remaining, &entry, &consumed)) {
            break;
        }

        if (entry != NULL) {
            WdfSpinLockAcquire(gResponseLock);
            InsertTailList(&gResponseList, &entry->Link);
            WdfSpinLockRelease(gResponseLock);

            KeSetEvent(&gResponseEvent, IO_NO_INCREMENT, FALSE);
        }

        if (consumed == 0 || consumed > remaining) {
            break;
        }

        ptr += consumed;
        remaining -= consumed;
    }
}

// Pop a response entry (caller must free Data)
PMTP_RESPONSE_ENTRY
MtpPopResponse(void)
{
    PMTP_RESPONSE_ENTRY r;
    PLIST_ENTRY e;

    r = NULL;
    WdfSpinLockAcquire(gResponseLock);
    if (!IsListEmpty(&gResponseList)) {
        e = RemoveHeadList(&gResponseList);
        r = CONTAINING_RECORD(e, MTP_RESPONSE_ENTRY, Link);
    }
    WdfSpinLockRelease(gResponseLock);
    return r;
}

// Wait for the next response entry (any transaction) with timeout (ms). Returns STATUS_SUCCESS and provides entry, or STATUS_TIMEOUT.
NTSTATUS
MtpWaitForResponse(OUT PMTP_RESPONSE_ENTRY *Entry, IN ULONG TimeoutMs)
{
    LARGE_INTEGER timeout;
    NTSTATUS st;
    PMTP_RESPONSE_ENTRY r;

    timeout.QuadPart = -((LONGLONG)TimeoutMs * 10 * 1000);

    st = KeWaitForSingleObject(&gResponseEvent, Executive, KernelMode, FALSE, &timeout);
    if (st == STATUS_TIMEOUT) return STATUS_IO_TIMEOUT;

    r = MtpPopResponse();
    if (IsListEmpty(&gResponseList)) {
        KeClearEvent(&gResponseEvent);
    }

    if (r) {
        *Entry = r; return STATUS_SUCCESS;
    }
    return STATUS_UNSUCCESSFUL;
}

// Wait for a response entry that matches a given transaction id. Requeues non-matching entries.
NTSTATUS
MtpWaitForResponseMatchingTid(OUT PMTP_RESPONSE_ENTRY *Entry, IN ULONG TransactionId, IN ULONG TimeoutMs)
{
    LARGE_INTEGER timeout;
    ULONG remainingMs;
    LARGE_INTEGER startTime;
    PMTP_RESPONSE_ENTRY e;
    NTSTATUS st;
    LARGE_INTEGER now;
    LONGLONG elapsed;

    timeout.QuadPart = -((LONGLONG)TimeoutMs * 10 * 1000);

    remainingMs = TimeoutMs;
    KeQuerySystemTime(&startTime);

    for (;;) {
        e = NULL;
        st = MtpWaitForResponse(&e, remainingMs);
        if (!NT_SUCCESS(st)) return st;

        if (e->TransactionId == TransactionId) { *Entry = e; return STATUS_SUCCESS; }

        // Not for us: reinsert at tail
        WdfSpinLockAcquire(gResponseLock);
        InsertTailList(&gResponseList, &e->Link);
        WdfSpinLockRelease(gResponseLock);

        KeQuerySystemTime(&now);
        elapsed = (now.QuadPart - startTime.QuadPart) / (10 * 1000);
        if (elapsed >= (LONGLONG)TimeoutMs) {
            return STATUS_IO_TIMEOUT;
        }
        remainingMs = (ULONG)(TimeoutMs - elapsed);
    }
}

// Build a simple operation container with given opcode and params (0..5 params).
// Returns allocated buffer (ExAllocatePoolWithTag) and its length in OutLen; caller must free.
PVOID
MtpBuildOperationContainer(IN USHORT Opcode, IN ULONG *Params, IN ULONG ParamCount, OUT PULONG OutLen, OUT PULONG OutTid)
{
    ULONG len;
    PVOID buf;
    ULONG tid;
    ULONG i;

    if (ParamCount > 5) ParamCount = 5;
    len = 12 + (ParamCount * sizeof(ULONG));
    buf = ExAllocatePoolWithTag(NonPagedPool, len, 'omtp');
    if (!buf) return NULL;

    if (Opcode == 0x1002) {
        tid = 0;
        gTransactionCounter = 0;
    } else {
        tid = (ULONG)InterlockedIncrement((PLONG)&gTransactionCounter);
    }

    *((ULONG*)buf) = len;
    *((USHORT*)((PUCHAR)buf + 4)) = 1; // Operation container
    *((USHORT*)((PUCHAR)buf + 6)) = Opcode;
    *((ULONG*)((PUCHAR)buf + 8)) = tid;

    for (i = 0; i < ParamCount; ++i) {
        *((ULONG*)((PUCHAR)buf + 12 + (i * sizeof(ULONG)))) = Params[i];
    }

    *OutLen = len;
    *OutTid = tid;
    return buf;
}

// Send an operation (and optional data payload) and return the first DATA container (if any) and the final RESPONSE code.
// Handles disconnection, timeouts, and proper cleanup on all error paths.
NTSTATUS
MtpSendOperationAndReceiveData(
    IN WDFDEVICE Device,
    IN USHORT Opcode,
    IN OPTIONAL ULONG *Params,
    IN ULONG ParamCount,
    IN OPTIONAL PVOID Data,
    IN size_t DataLen,
    OUT PVOID *OutData,
    OUT size_t *OutDataLen,
    OUT USHORT *OutResponse
    )
{
    WDFUSBPIPE outPipe;
    WDFUSBPIPE inPipe;
    ULONG opLen;
    ULONG tid;
    PVOID opBuf;
    NTSTATUS st;
    ULONG dlen;
    PVOID dBuf;
    PUCHAR readBuf;
    ULONG readBufSize;
    ULONG bytesRead;
    ULONG containerLen;
    USHORT containerType;
    USHORT containerCode;
    ULONG containerTid;
    ULONG respParamsLen;
    PVOID respParams;

    *OutData = NULL;
    *OutDataLen = 0;
    *OutResponse = 0;

    outPipe = MtpUsb_GetBulkOutPipe(Device);
    inPipe = MtpUsb_GetBulkInPipe(Device);
    if (outPipe == NULL || inPipe == NULL) {
        KdPrint(("MTP: No USB pipes available\n"));
        return STATUS_INVALID_DEVICE_STATE;
    }

    opLen = 0;
    tid = 0;
    opBuf = MtpBuildOperationContainer(Opcode, Params, ParamCount, &opLen, &tid);
    if (!opBuf) return STATUS_INSUFFICIENT_RESOURCES;

    st = MtpUsb_WriteBulk(Device, outPipe, opBuf, opLen);
    ExFreePoolWithTag(opBuf, 'omtp');
    if (!NT_SUCCESS(st)) {
        KdPrint(("MTP: Failed to send operation 0x%04x: 0x%08x\n", Opcode, st));
        return st;
    }

    if (Data && DataLen) {
        dlen = (ULONG)(12 + DataLen);
        dBuf = ExAllocatePoolWithTag(NonPagedPool, dlen, 'dmtp');
        if (!dBuf) return STATUS_INSUFFICIENT_RESOURCES;
        
        *((ULONG*)dBuf) = dlen;
        *((USHORT*)((PUCHAR)dBuf + 4)) = 2; // Data
        *((USHORT*)((PUCHAR)dBuf + 6)) = Opcode;
        *((ULONG*)((PUCHAR)dBuf + 8)) = tid;
        RtlCopyMemory((PUCHAR)dBuf + 12, Data, DataLen);

        st = MtpUsb_WriteBulk(Device, outPipe, dBuf, dlen);
        ExFreePoolWithTag(dBuf, 'dmtp');
        if (!NT_SUCCESS(st)) {
            KdPrint(("MTP: Failed to send data payload: 0x%08x\n", st));
            return st;
        }
    }

    if (Opcode == 0x1007 || Opcode == 0x9805) {
        readBufSize = 262144; /* 256 KB for large object handle lists */
    } else if (Opcode == 0x9107 || Opcode == 0x9807 || Opcode == 0x100A || Opcode == 0x101B) {
        readBufSize = 131072; /* 128 KB for partial object / thumbnail reads */
    } else {
        readBufSize = 4096;   /* 4 KB fits in 1 physical page; prevents NonPagedPool fragmentation on Win2K */
    }

    readBuf = (PUCHAR)ExAllocatePoolWithTag(NonPagedPool, readBufSize, 'rmtp');
    if (!readBuf) return STATUS_INSUFFICIENT_RESOURCES;

    bytesRead = 0;
    st = MtpUsb_ReadBulk(Device, inPipe, readBuf, readBufSize, &bytesRead);
    if (!NT_SUCCESS(st)) {
        KdPrint(("MTP: ReadBulk failed 0x%08x for opcode 0x%04x\n", st, Opcode));
        ExFreePoolWithTag(readBuf, 'rmtp');
        return st;
    }

    if (bytesRead < 12) {
        KdPrint(("MTP: Short read (%u bytes)\n", bytesRead));
        ExFreePoolWithTag(readBuf, 'rmtp');
        return STATUS_DEVICE_DATA_ERROR;
    }

    containerLen = 0;
    containerType = 0;
    containerCode = 0;
    containerTid = 0;
    RtlCopyMemory(&containerLen, readBuf, sizeof(ULONG));
    RtlCopyMemory(&containerType, readBuf + 4, sizeof(USHORT));
    RtlCopyMemory(&containerCode, readBuf + 6, sizeof(USHORT));
    RtlCopyMemory(&containerTid, readBuf + 8, sizeof(ULONG));

    /* Drain any stale packets belonging to prior timed-out or aborted transactions */
    while (tid != 0 && containerTid != 0 && containerTid != tid) {
        KdPrint(("MTP: Stale packet on pipe (type=%u, len=%u, code=0x%04x, tid=%u, expected=%u), draining...\n",
                 (ULONG)containerType, containerLen, (ULONG)containerCode, containerTid, tid));

        /* If this was a DATA container (Type 2), drain any remaining bytes of this container */
        if (containerType == 2 && containerLen > bytesRead) {
            ULONG remainingStale = containerLen - bytesRead;
            while (remainingStale > 0) {
                ULONG toDrain = (remainingStale < readBufSize) ? remainingStale : readBufSize;
                ULONG chunkDrained = 0;
                st = MtpUsb_ReadBulk(Device, inPipe, readBuf, toDrain, &chunkDrained);
                if (!NT_SUCCESS(st) || chunkDrained == 0) break;
                if (remainingStale >= chunkDrained) {
                    remainingStale -= chunkDrained;
                } else {
                    remainingStale = 0;
                }
            }
        }

        /* Read next packet */
        bytesRead = 0;
        st = MtpUsb_ReadBulk(Device, inPipe, readBuf, readBufSize, &bytesRead);
        if (!NT_SUCCESS(st) || bytesRead < 12) {
            KdPrint(("MTP: Read after drain failed 0x%08x (bytes=%lu)\n", st, bytesRead));
            ExFreePoolWithTag(readBuf, 'rmtp');
            return NT_SUCCESS(st) ? STATUS_DEVICE_DATA_ERROR : st;
        }

        containerLen = 0;
        containerType = 0;
        containerCode = 0;
        containerTid = 0;
        RtlCopyMemory(&containerLen, readBuf, sizeof(ULONG));
        RtlCopyMemory(&containerType, readBuf + 4, sizeof(USHORT));
        RtlCopyMemory(&containerCode, readBuf + 6, sizeof(USHORT));
        RtlCopyMemory(&containerTid, readBuf + 8, sizeof(ULONG));
    }

    // Handle DATA container (Type 2)
    if (containerType == 2) {
        ULONG payloadLen;
        ULONG copied;
        PVOID fullData;
        ULONG excessBytes = 0;
        PUCHAR excessPtr = NULL;

        payloadLen = (containerLen > 12) ? (containerLen - 12) : 0;
        copied = 0;
        fullData = NULL;

        if (payloadLen > 0) {
            fullData = ExAllocatePoolWithTag(NonPagedPool, payloadLen, 'dout');
            if (!fullData) {
                ExFreePoolWithTag(readBuf, 'rmtp');
                return STATUS_INSUFFICIENT_RESOURCES;
            }

            copied = bytesRead - 12;
            if (copied > payloadLen) copied = payloadLen;
            RtlCopyMemory(fullData, readBuf + 12, copied);

            if (bytesRead > 12 + payloadLen) {
                excessBytes = bytesRead - (12 + payloadLen);
                excessPtr = readBuf + (12 + payloadLen);
            }

            // Read remaining data chunks if buffer spanned multiple reads
            while (copied < payloadLen) {
                ULONG chunkRead = 0;
                ULONG toCopy = 0;
                st = MtpUsb_ReadBulk(Device, inPipe, readBuf, readBufSize, &chunkRead);
                if (!NT_SUCCESS(st) || chunkRead == 0) {
                    KdPrint(("MTP: Multi-chunk read stopped: st=0x%08x chunk=%u copied=%u/%u\n", st, chunkRead, copied, payloadLen));
                    break;
                }
                toCopy = chunkRead;
                if (copied + toCopy > payloadLen) {
                    toCopy = payloadLen - copied;
                    excessBytes = chunkRead - toCopy;
                    excessPtr = readBuf + toCopy;
                } else {
                    excessBytes = 0;
                    excessPtr = NULL;
                }
                RtlCopyMemory((PUCHAR)fullData + copied, readBuf, toCopy);
                copied += toCopy;
            }

            *OutData = fullData;
            *OutDataLen = copied;
        } else {
            if (bytesRead > 12) {
                excessBytes = bytesRead - 12;
                excessPtr = readBuf + 12;
            }
        }

        // Parse RESPONSE container
        if (excessBytes >= 12 && excessPtr) {
            USHORT respType = 0;
            USHORT respCode = 0;
            RtlCopyMemory(&respType, excessPtr + 4, sizeof(USHORT));
            RtlCopyMemory(&respCode, excessPtr + 6, sizeof(USHORT));
            if (respType == 3) {
                *OutResponse = respCode;
            }
        } else {
            // Read next packet from Bulk IN for the RESPONSE container
            ULONG respBytes = 0;
            USHORT respType = 0;
            USHORT respCode = 0;
            st = MtpUsb_ReadBulk(Device, inPipe, readBuf, readBufSize, &respBytes);
            if (NT_SUCCESS(st) && respBytes == 0) {
                /* Handled ZLP (Zero-Length Packet) terminating data phase; read RESPONSE container */
                respBytes = 0;
                st = MtpUsb_ReadBulk(Device, inPipe, readBuf, readBufSize, &respBytes);
            }
            if (NT_SUCCESS(st) && respBytes >= 12) {
                RtlCopyMemory(&respType, readBuf + 4, sizeof(USHORT));
                RtlCopyMemory(&respCode, readBuf + 6, sizeof(USHORT));
                if (respType == 3) {
                    *OutResponse = respCode;
                }
            } else {
                KdPrint(("MTP: Response read st=0x%08x bytes=%u\n", st, respBytes));
            }
        }

        ExFreePoolWithTag(readBuf, 'rmtp');
        return STATUS_SUCCESS;
    }

    // Handle RESPONSE container (Type 3)
    if (containerType == 3) {
        *OutResponse = containerCode;
        respParamsLen = (containerLen > 12) ? (containerLen - 12) : 0;
        if (respParamsLen > 0 && bytesRead >= 12 + respParamsLen) {
            respParams = ExAllocatePoolWithTag(NonPagedPool, respParamsLen, 'dout');
            if (respParams) {
                RtlCopyMemory(respParams, readBuf + 12, respParamsLen);
                *OutData = respParams;
                *OutDataLen = respParamsLen;
            }
        }
        ExFreePoolWithTag(readBuf, 'rmtp');
        return (containerCode == 0x2001 || containerCode == 0x201E) ? STATUS_SUCCESS : STATUS_UNSUCCESSFUL;
    }

    KdPrint(("MTP: Unexpected container type %u\n", (ULONG)containerType));
    ExFreePoolWithTag(readBuf, 'rmtp');
    return STATUS_UNSUCCESSFUL;
}

// Session open/close and generic operation handlers
NTSTATUS
MtpSessionOpen(WDFREQUEST Request)
{
    WDFDEVICE device;
    PDEVICE_CONTEXT ctx;
    PVOID outBuf;
    size_t outCap;
    NTSTATUS status;
    ULONG sessionParam;
    PVOID respData;
    size_t respLen;
    USHORT respCode;

    device = WdfRequestGetDevice(Request);
    ctx = DeviceGetContext(device);

    /* Assign a local session ID if we don't have one yet */
    if (ctx->SessionId == 0) ctx->SessionId = (ULONG)InterlockedIncrement((PLONG)&gNextObjectId);

    /* Send the actual MTP OpenSession (0x1002) command to the USB device.
     * Without this, QEMU usb-mtp (and real devices) reject all subsequent
     * operations with SessionNotOpen (0x2003). */
    sessionParam = ctx->SessionId;
    respData = NULL;
    respLen = 0;
    respCode = 0;
    status = MtpSendOperationAndReceiveData(device, 0x1002, &sessionParam, 1,
                                            NULL, 0, &respData, &respLen, &respCode);
    if (respData) ExFreePoolWithTag(respData, 'dout');

    /* If session was already open from a previous run, cleanly reset it with CloseSession then OpenSession */
    if (respCode == 0x201E) {
        KdPrint(("MTP: Session already open on device, resetting cleanly\n"));
        respData = NULL;
        MtpSendOperationAndReceiveData(device, 0x1003, NULL, 0, NULL, 0, &respData, &respLen, &respCode);
        if (respData) ExFreePoolWithTag(respData, 'dout');

        respData = NULL;
        status = MtpSendOperationAndReceiveData(device, 0x1002, &sessionParam, 1,
                                                NULL, 0, &respData, &respLen, &respCode);
        if (respData) ExFreePoolWithTag(respData, 'dout');
    }

    /* Accept OK (0x2001) or SessionAlreadyOpen (0x201E) as success */
    if (!NT_SUCCESS(status)) {
        KdPrint(("MTP: OpenSession USB send failed 0x%08x\n", status));
        /* USB send failed => no real device, use emulation catalog */
        g_bRealDevicePresent = FALSE;
    } else {
        KdPrint(("MTP: OpenSession response code 0x%04x\n", (ULONG)respCode));
        if (respCode == 0x2001 || respCode == 0x201E) {
            g_bRealDevicePresent = TRUE;
            KdPrint(("MTP: Real USB device detected, bypassing fake catalog\n"));
        }
    }

    status = WdfRequestRetrieveOutputBuffer(Request, sizeof(ULONG), &outBuf, &outCap);
    if (NT_SUCCESS(status) && outCap >= sizeof(ULONG)) {
        *((PULONG)outBuf) = ctx->SessionId;
        WdfRequestCompleteWithInformation(Request, STATUS_SUCCESS, sizeof(ULONG));
        return STATUS_SUCCESS;
    }

    WdfRequestComplete(Request, STATUS_SUCCESS);
    return STATUS_SUCCESS;
}

NTSTATUS
MtpSessionClose(WDFREQUEST Request)
{
    WDFDEVICE device;
    PDEVICE_CONTEXT ctx;
    PVOID respData;
    size_t respLen;
    USHORT respCode;
    NTSTATUS status;

    device = WdfRequestGetDevice(Request);
    ctx = DeviceGetContext(device);

    /* Send PTP CloseSession (0x1003) command per ISO 15740 (0 parameters) */
    if (ctx->SessionId != 0) {
        respData = NULL;
        respLen = 0;
        respCode = 0;
        status = MtpSendOperationAndReceiveData(device, 0x1003, NULL, 0,
                                                NULL, 0, &respData, &respLen, &respCode);
        if (respData) ExFreePoolWithTag(respData, 'dout');
        KdPrint(("MTP: CloseSession response 0x%04x (st=0x%08x)\n", (ULONG)respCode, status));
    }

    ctx->SessionId = 0;
    g_bRealDevicePresent = FALSE;
    MtpResetStreaming();
    WdfRequestComplete(Request, STATUS_SUCCESS);
    return STATUS_SUCCESS;
}

// Generic operation - if device present, send command and wait for response; otherwise, emulate common ops
NTSTATUS
MtpOperation(WDFREQUEST Request)
{
    PVOID inBuf;
    size_t inLen;
    NTSTATUS status;
    PULONG p;
    ULONG opcode;
    ULONG paramCount;
    ULONG params[5];
    ULONG maxParams;
    size_t offset;
    PVOID data;
    size_t dataLen;
    WDFDEVICE device;
    PVOID outData;
    size_t outDataLen;
    USHORT respCode;
    PVOID outBuf;
    size_t outCap;

    status = WdfRequestRetrieveInputBuffer(Request, sizeof(ULONG), &inBuf, &inLen);
    if (!NT_SUCCESS(status)) { WdfRequestComplete(Request, status); return status; }

    if (inLen < sizeof(ULONG)) { WdfRequestComplete(Request, STATUS_INVALID_PARAMETER); return STATUS_INVALID_PARAMETER; }

    p = (PULONG)inBuf;
    opcode = p[0];

    maxParams = 5;
    switch (opcode) {
        case 0x1001: maxParams = 0; break; /* GetDeviceInfo */
        case 0x1002: maxParams = 1; break; /* OpenSession */
        case 0x1003: maxParams = 0; break; /* CloseSession: 0 params per ISO 15740 */
        case 0x1004: maxParams = 0; break; /* GetStorageIDs */
        case 0x1005: maxParams = 1; break; /* GetStorageInfo */
        case 0x1007: maxParams = 3; break; /* GetObjectHandles */
        case 0x1008: maxParams = 1; break; /* GetObjectInfo */
        case 0x1009: maxParams = 1; break; /* GetObject */
        case 0x100A: maxParams = 1; break; /* GetThumb */
        case 0x100B: maxParams = 1; break; /* DeleteObject */
        case 0x100C: maxParams = 2; break; /* SendObjectInfo: StorageID, ParentObject */
        case 0x100D: maxParams = 0; break; /* SendObject */
        case 0x1014: maxParams = 1; break; /* GetDevicePropDesc */
        case 0x1015: maxParams = 1; break; /* GetDevicePropValue */
        case 0x1016: maxParams = 1; break; /* SetDevicePropValue */
        case 0x101B: maxParams = 3; break; /* PTP GetPartialObject */
        case 0x9107: maxParams = 3; break; /* MTP GetPartialObject: Handle, Offset, MaxBytes */
        case 0x9801: maxParams = 1; break; /* GetObjectPropsSupported */
        case 0x9802: maxParams = 2; break; /* GetObjectPropDesc */
        case 0x9803: maxParams = 2; break; /* GetObjectPropValue */
        case 0x9804: maxParams = 2; break; /* SetObjectPropValue */
        case 0x9805: maxParams = 5; break; /* GetObjectPropList */
        case 0x9806: maxParams = 0; break; /* SetObjectPropList */
        case 0x9807: maxParams = 4; break; /* MTP GetPartialObject64 */
        default:     maxParams = 5; break;
    }

    paramCount = 0;
    params[0] = 0;
    params[1] = 0;
    params[2] = 0;
    params[3] = 0;
    params[4] = 0;
    offset = sizeof(ULONG);
    while (paramCount < maxParams && offset + sizeof(ULONG) <= inLen) {
        params[paramCount++] = *((PULONG)((PUCHAR)inBuf + offset));
        offset += sizeof(ULONG);
    }

    data = NULL;
    dataLen = 0;
    if (offset < inLen) {
        dataLen = inLen - offset;
        data = ExAllocatePoolWithTag(NonPagedPool, dataLen, 'datm');
        if (!data) { WdfRequestComplete(Request, STATUS_INSUFFICIENT_RESOURCES); return STATUS_INSUFFICIENT_RESOURCES; }
        RtlCopyMemory(data, (PUCHAR)inBuf + offset, dataLen);
    }

    device = WdfRequestGetDevice(Request);

    outData = NULL;
    outDataLen = 0;
    respCode = 0;
    status = MtpSendOperationAndReceiveData(device, (USHORT)opcode, params, paramCount, data, dataLen, &outData, &outDataLen, &respCode);

    if (data) ExFreePoolWithTag(data, 'datm');

    if (!NT_SUCCESS(status)) {
        if (outData) ExFreePoolWithTag(outData, 'dout');

        if (opcode == 0x1001) {
            // GetDeviceInfo
            UCHAR devInfo[128];
            status = WdfRequestRetrieveOutputBuffer(Request, 1, &outBuf, &outCap);
            if (NT_SUCCESS(status)) {
                size_t toCopy;
                RtlZeroMemory(devInfo, sizeof(devInfo));
                *((PUSHORT)(devInfo + 0)) = 100;
                *((PULONG)(devInfo + 2)) = 6;
                *((PUSHORT)(devInfo + 6)) = 100;
                toCopy = (sizeof(devInfo) < outCap) ? sizeof(devInfo) : outCap;
                RtlCopyMemory(outBuf, devInfo, toCopy);
                WdfRequestCompleteWithInformation(Request, STATUS_SUCCESS, toCopy);
                return STATUS_SUCCESS;
            }
        }

        if (opcode == 0x1002 || opcode == 0x1003) {
            // OpenSession / CloseSession
            status = WdfRequestRetrieveOutputBuffer(Request, sizeof(ULONG), &outBuf, &outCap);
            if (NT_SUCCESS(status)) {
                *((PULONG)outBuf) = 0x2001;
                WdfRequestCompleteWithInformation(Request, STATUS_SUCCESS, sizeof(ULONG));
                return STATUS_SUCCESS;
            }
        }

        if (opcode == 0x1004 && !g_bRealDevicePresent) {
            // GetStorageIDs
            status = WdfRequestRetrieveOutputBuffer(Request, sizeof(ULONG) * 2, &outBuf, &outCap);
            if (NT_SUCCESS(status)) {
                PULONG storages = (PULONG)outBuf;
                storages[0] = 1;
                storages[1] = 0x00010001;
                WdfRequestCompleteWithInformation(Request, STATUS_SUCCESS, sizeof(ULONG) * 2);
                return STATUS_SUCCESS;
            }
        }

        if (opcode == 0x1005 && !g_bRealDevicePresent) {
            // GetStorageInfo - MTP StorageInfo dataset per PTP/MTP spec:
            // Offset  0: StorageType      (UINT16)  - 3 = FixedRAM
            // Offset  2: FilesystemType   (UINT16)  - 2 = GenericHierarchical
            // Offset  4: AccessCapability (UINT16)  - 0 = ReadWrite
            // Offset  6: MaxCapacity      (UINT64)  - total storage in bytes
            // Offset 14: FreeSpaceInBytes (UINT64)  - free storage in bytes
            // Offset 22: FreeSpaceInObjects (UINT32)
            // Offset 26: StorageDescription (MTP String)
            // Offset ??: VolumeIdentifier  (MTP String)
            status = WdfRequestRetrieveOutputBuffer(Request, 64, &outBuf, &outCap);
            if (NT_SUCCESS(status)) {
                PUCHAR sInfo = (PUCHAR)outBuf;
                size_t descOffset;
                /* "Internal Storage" = 16 chars, MTP string: 1 byte length + N*2 bytes + 2 null */
                static const WCHAR storDesc[] = L"Internal Storage";
                UCHAR strLen = 17; /* 16 chars + null terminator */
                size_t totalSize;

                totalSize = 26 + 1 + (strLen * 2) + 1 + 2; /* fixed + desc string + empty vol string */
                if (totalSize > outCap) totalSize = outCap;
                RtlZeroMemory(sInfo, totalSize);

                *((PUSHORT)(sInfo + 0)) = 3;     /* StorageType: FixedRAM */
                *((PUSHORT)(sInfo + 2)) = 2;     /* FilesystemType: GenericHierarchical */
                *((PUSHORT)(sInfo + 4)) = 0;     /* AccessCapability: ReadWrite */

                /* MaxCapacity: 256 GB = 256 * 1024 * 1024 * 1024 = 0x4000000000 */
                *((PULONG)(sInfo + 6))  = 0x00000000UL;  /* low 32 bits */
                *((PULONG)(sInfo + 10)) = 0x00000040UL;  /* high 32 bits: 64 * 2^32 = 256 GB */

                /* FreeSpaceInBytes: 220 GB = 0x3700000000 */
                *((PULONG)(sInfo + 14)) = 0x00000000UL;  /* low 32 bits */
                *((PULONG)(sInfo + 18)) = 0x00000037UL;  /* high 32 bits: 55 * 2^32 = 220 GB */

                *((PULONG)(sInfo + 22)) = 0xFFFFFFFF; /* FreeSpaceInObjects: unlimited */

                /* StorageDescription MTP String at offset 26 */
                descOffset = 26;
                if (descOffset + 1 + (strLen * 2) <= totalSize) {
                    UCHAR ci;
                    sInfo[descOffset] = strLen;
                    for (ci = 0; ci < strLen - 1; ci++) {
                        *((PUSHORT)(sInfo + descOffset + 1 + ci * 2)) = (USHORT)storDesc[ci];
                    }
                    *((PUSHORT)(sInfo + descOffset + 1 + (strLen - 1) * 2)) = 0; /* null term */
                }

                WdfRequestCompleteWithInformation(Request, STATUS_SUCCESS, totalSize);
                return STATUS_SUCCESS;
            }
        }

        if (opcode == 0x1007 && !g_bRealDevicePresent) {
            /* GetObjectHandles fallback: only use fake catalog when no real device */
            PLIST_ENTRY entry;
            PMTP_OBJECT objEntry;
            ULONG count = 0;
            PULONG hList;
            ULONG reqParent = (paramCount >= 3) ? params[2] : 0;

            status = WdfRequestRetrieveOutputBuffer(Request, sizeof(ULONG), &outBuf, &outCap);
            if (NT_SUCCESS(status)) {
                hList = (PULONG)outBuf;
                count = 0;
                WdfSpinLockAcquire(gObjectLock);
                for (entry = gObjectList.Flink; entry != &gObjectList; entry = entry->Flink) {
                    objEntry = CONTAINING_RECORD(entry, MTP_OBJECT, Link);
                    if (reqParent == 0xFFFFFFFF || objEntry->ParentId == reqParent) {
                        if ((count + 2) * sizeof(ULONG) <= outCap) {
                            hList[1 + count] = objEntry->Id;
                            count++;
                        }
                    }
                }
                WdfSpinLockRelease(gObjectLock);
                hList[0] = count;
                WdfRequestCompleteWithInformation(Request, STATUS_SUCCESS, (1 + count) * sizeof(ULONG));
                return STATUS_SUCCESS;
            }
        }

        if (opcode == 0x1008 && paramCount >= 1 && !g_bRealDevicePresent) {
            /* GetObjectInfo fallback: only use fake catalog when no real device */
            PMTP_OBJECT objInfo = MtpFindObject(params[0]);
            if (objInfo) {
                status = WdfRequestRetrieveOutputBuffer(Request, 64, &outBuf, &outCap);
                if (NT_SUCCESS(status)) {
                    PUCHAR pOut = (PUCHAR)outBuf;
                    size_t nameLen = strlen(objInfo->Name);
                    size_t totalInfoSize = 53 + (nameLen * 2) + 2;
                    if (totalInfoSize <= outCap) {
                        size_t ci;
                        RtlZeroMemory(pOut, totalInfoSize);
                        *((PULONG)(pOut + 0)) = 0x00010001; // StorageId
                        *((PUSHORT)(pOut + 4)) = objInfo->Format; // Format
                        *((PUSHORT)(pOut + 6)) = 0; // ProtectionStatus
                        *((PULONG)(pOut + 8)) = objInfo->Size; // CompressedSize
                        *((PULONG)(pOut + 38)) = objInfo->ParentId; // ParentObject
                        *((PUSHORT)(pOut + 42)) = (objInfo->Format == 0x3001) ? 1 : 0; // AssociationType
                        pOut[52] = (UCHAR)(nameLen + 1);
                        for (ci = 0; ci < nameLen; ci++) {
                            pOut[53 + ci * 2] = (UCHAR)objInfo->Name[ci];
                            pOut[53 + ci * 2 + 1] = 0;
                        }
                        pOut[53 + nameLen * 2] = 0;
                        pOut[53 + nameLen * 2 + 1] = 0;
                        WdfRequestCompleteWithInformation(Request, STATUS_SUCCESS, totalInfoSize);
                        return STATUS_SUCCESS;
                    }
                }
            }
        }

        if (opcode == 0x1009 && paramCount >= 1 && !g_bRealDevicePresent) {
            /* GetObject fallback: only use fake catalog when no real device */
            PMTP_OBJECT objGet = MtpFindObject(params[0]);
            if (objGet && objGet->Data && objGet->Size > 0) {
                status = WdfRequestRetrieveOutputBuffer(Request, 1, &outBuf, &outCap);
                if (NT_SUCCESS(status)) {
                    size_t toCopy = (objGet->Size < outCap) ? objGet->Size : outCap;
                    RtlCopyMemory(outBuf, objGet->Data, toCopy);
                    WdfRequestCompleteWithInformation(Request, STATUS_SUCCESS, toCopy);
                    return STATUS_SUCCESS;
                }
            }
        }

        if ((opcode == 0x9107 || opcode == 0x101B) && paramCount >= 3 && !g_bRealDevicePresent) {
            /* GetPartialObject fallback: only use fake catalog when no real device */
            PMTP_OBJECT objPart = MtpFindObject(params[0]);
            if (objPart && objPart->Data && objPart->Size > 0) {
                status = WdfRequestRetrieveOutputBuffer(Request, 1, &outBuf, &outCap);
                if (NT_SUCCESS(status)) {
                    ULONG reqOff = params[1];
                    ULONG reqLen = params[2];
                    ULONG toCopy = 0;
                    if (reqOff < objPart->Size) {
                        toCopy = objPart->Size - reqOff;
                        if (toCopy > reqLen) toCopy = reqLen;
                        if (toCopy > (ULONG)outCap) toCopy = (ULONG)outCap;
                        RtlCopyMemory(outBuf, (PUCHAR)objPart->Data + reqOff, toCopy);
                    }
                    WdfRequestCompleteWithInformation(Request, STATUS_SUCCESS, toCopy);
                    return STATUS_SUCCESS;
                }
            }
        }

        if (opcode == 0x100B && paramCount >= 1 && !g_bRealDevicePresent) {
            /* DeleteObject fallback: only use fake catalog when no real device */
            PMTP_OBJECT delObj = MtpFindObject(params[0]);
            if (delObj) {
                WdfSpinLockAcquire(gObjectLock);
                RemoveEntryList(&delObj->Link);
                WdfSpinLockRelease(gObjectLock);
                if (delObj->Data) ExFreePoolWithTag(delObj->Data, 'mtpD');
                ExFreePoolWithTag(delObj, 'mtpO');
            }
            status = WdfRequestRetrieveOutputBuffer(Request, sizeof(ULONG), &outBuf, &outCap);
            if (NT_SUCCESS(status)) {
                *((PULONG)outBuf) = 0x2001; // OK
                WdfRequestCompleteWithInformation(Request, STATUS_SUCCESS, sizeof(ULONG));
                return STATUS_SUCCESS;
            }
        }

        if (opcode == 0x100C && !g_bRealDevicePresent) {
            status = WdfRequestRetrieveOutputBuffer(Request, sizeof(ULONG) * 3, &outBuf, &outCap);
            if (NT_SUCCESS(status) && outCap >= sizeof(ULONG) * 3) {
                PULONG pResp = (PULONG)outBuf;
                pResp[0] = params[0]; /* StorageID */
                pResp[1] = params[1]; /* ParentObject */
                pResp[2] = gNextObjectId++; /* Reserved ObjectHandle */
                WdfRequestCompleteWithInformation(Request, STATUS_SUCCESS, sizeof(ULONG) * 3);
                return STATUS_SUCCESS;
            }
        }

        WdfRequestComplete(Request, status);
        return status;
    }

    if (opcode == 0x100B && paramCount >= 1) {
        PMTP_OBJECT delObj = MtpFindObject(params[0]);
        if (delObj) {
            WdfSpinLockAcquire(gObjectLock);
            RemoveEntryList(&delObj->Link);
            WdfSpinLockRelease(gObjectLock);
            if (delObj->Data) ExFreePoolWithTag(delObj->Data, 'mtpD');
            ExFreePoolWithTag(delObj, 'mtpO');
        }
    }

    if (outData && outDataLen > 0) {
        ULONG toCopy;
        status = WdfRequestRetrieveOutputBuffer(Request, 1, &outBuf, &outCap);
        if (!NT_SUCCESS(status)) { ExFreePoolWithTag(outData, 'dout'); WdfRequestComplete(Request, status); return status; }
        toCopy = (outDataLen < outCap) ? (ULONG)outDataLen : (ULONG)outCap;
        RtlCopyMemory(outBuf, outData, toCopy);
        ExFreePoolWithTag(outData, 'dout');
        WdfRequestCompleteWithInformation(Request, STATUS_SUCCESS, toCopy);
        return STATUS_SUCCESS;
    }

    // No data; return the response code as a 4-byte value
    status = WdfRequestRetrieveOutputBuffer(Request, sizeof(ULONG), &outBuf, &outCap);
    if (!NT_SUCCESS(status)) { WdfRequestComplete(Request, status); return status; }
    *((PULONG)outBuf) = (ULONG)respCode;
    WdfRequestCompleteWithInformation(Request, STATUS_SUCCESS, sizeof(ULONG));
    return STATUS_SUCCESS;
}

// Cleanup: release all objects and responses (call on device removal / shutdown)
NTSTATUS
MtpCleanupDevice(WDFDEVICE Device)
{
    PLIST_ENTRY e;
    PMTP_RESPONSE_ENTRY entry;
    PMTP_OBJECT obj;

    UNREFERENCED_PARAMETER(Device);

    if (gResponseLock) {
        WdfSpinLockAcquire(gResponseLock);
        while (!IsListEmpty(&gResponseList)) {
            e = RemoveHeadList(&gResponseList);
            entry = CONTAINING_RECORD(e, MTP_RESPONSE_ENTRY, Link);
            if (entry->Data) {
                ExFreePoolWithTag(entry->Data, 'rmtp');
            }
            ExFreePoolWithTag(entry, 'rmtp');
        }
        WdfSpinLockRelease(gResponseLock);
    }

    if (gObjectLock) {
        WdfSpinLockAcquire(gObjectLock);
        while (!IsListEmpty(&gObjectList)) {
            e = RemoveHeadList(&gObjectList);
            obj = CONTAINING_RECORD(e, MTP_OBJECT, Link);
            if (obj->Data) {
                ExFreePoolWithTag(obj->Data, 'mtpD');
            }
            ExFreePoolWithTag(obj, 'mtpO');
        }
        WdfSpinLockRelease(gObjectLock);
    }

    MtpResetStreaming();

    KdPrint(("MTP: Cleanup completed successfully\n"));
    return STATUS_SUCCESS;
}
