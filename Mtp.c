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

    // Pre-populate standard phone storage objects (matches QEMU phone storage)
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

    obj = MtpFindObject(id);
    if (obj) {
        /* Object in internal/fallback catalog */
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

    /* Object is on real connected MTP / PTP hardware device:
     * Pure streaming! We use GetPartialObject (0x101B) or GetPartialObject64 (0x95C1)
     * to request ONLY this chunk from the device directly into outBuf.
     * Kernel memory consumption is strictly O(1) - NO giant buffer in RAM!
     */
    {
        PVOID chunkData = NULL;
        size_t chunkDataLen = 0;
        USHORT respCode = 0;
        ULONG params[4];

        if (offsetHigh == 0) {
            /* Standard 32-bit offset: MTP_OP_GET_PARTIAL_OBJECT (0x101B) */
            params[0] = id;
            params[1] = offsetLow;
            params[2] = length;
            status = MtpSendOperationAndReceiveData(WdfRequestGetDevice(Request), MTP_OP_GET_PARTIAL_OBJECT,
                                                    params, 3, NULL, 0, &chunkData, &chunkDataLen, &respCode);
        } else {
            /* 64-bit offset (files >= 4 GB): MTP_OP_GET_PARTIAL_OBJECT_64 (0x95C1) */
            params[0] = id;
            params[1] = offsetLow;
            params[2] = offsetHigh;
            params[3] = length;
            status = MtpSendOperationAndReceiveData(WdfRequestGetDevice(Request), MTP_OP_GET_PARTIAL_OBJECT_64,
                                                    params, 4, NULL, 0, &chunkData, &chunkDataLen, &respCode);
        }

        /* Fallback for legacy devices that only support single-shot 0x1009 (GetObject) */
        if (!NT_SUCCESS(status) || !chunkData || chunkDataLen == 0) {
            if (offset == 0) {
                ULONG getParam = id;
                status = MtpSendOperationAndReceiveData(WdfRequestGetDevice(Request), MTP_OP_GET_OBJECT,
                                                        &getParam, 1, NULL, 0, &chunkData, &chunkDataLen, &respCode);
            }
        }

        if (NT_SUCCESS(status) && chunkData && chunkDataLen > 0) {
            toCopy = (ULONG)chunkDataLen;
            if (toCopy > outCap) toCopy = (ULONG)outCap;
            RtlCopyMemory(outBuf, chunkData, toCopy);
            ExFreePoolWithTag(chunkData, 'dout');
            WdfRequestCompleteWithInformation(Request, STATUS_SUCCESS, toCopy);
            return STATUS_SUCCESS;
        }

        if (chunkData) ExFreePoolWithTag(chunkData, 'dout');
        WdfRequestComplete(Request, STATUS_NOT_FOUND);
        return STATUS_NOT_FOUND;
    }
}

// Input for send object part: [ULONG Id][ULONG Offset][data...]
NTSTATUS
MtpSendObjectPart(WDFREQUEST Request)
{
    PVOID inBuf;
    size_t inLen;
    NTSTATUS status;
    PULONG p;
    ULONG id;
    ULONG offset;
    PVOID data;
    ULONG dataLen;
    PMTP_OBJECT obj;
    PVOID outBuf;
    size_t outCap;

    status = WdfRequestRetrieveInputBuffer(Request, sizeof(ULONG)*2 + 1, &inBuf, &inLen);
    if (!NT_SUCCESS(status)) { WdfRequestComplete(Request, status); return status; }

    p = (PULONG)inBuf;
    id = p[0];
    offset = p[1];
    data = (PVOID)((PUCHAR)inBuf + sizeof(ULONG)*2);
    dataLen = (ULONG)(inLen - sizeof(ULONG)*2);

    obj = NULL;
    if (id == 0 && offset == 0) {
        obj = (PMTP_OBJECT)ExAllocatePoolWithTag(NonPagedPool, sizeof(MTP_OBJECT), 'mtpO');
        if (!obj) { WdfRequestComplete(Request, STATUS_INSUFFICIENT_RESOURCES); return STATUS_INSUFFICIENT_RESOURCES; }
        RtlZeroMemory(obj, sizeof(*obj));
        obj->Id = gNextObjectId++;
        obj->AllocSize = dataLen;
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
        ULONG newAlloc;
        PVOID newBuf;
        
        newAlloc = max(offset + dataLen, obj->AllocSize * 2);
        if (newAlloc < obj->AllocSize + 1024) newAlloc = obj->AllocSize + 1024;
        newBuf = ExAllocatePoolWithTag(NonPagedPool, newAlloc, 'mtpD');
        if (!newBuf) { WdfSpinLockRelease(gObjectLock); WdfRequestComplete(Request, STATUS_INSUFFICIENT_RESOURCES); return STATUS_INSUFFICIENT_RESOURCES; }
        RtlCopyMemory(newBuf, obj->Data, obj->Size);
        ExFreePoolWithTag(obj->Data, 'mtpD');
        obj->Data = newBuf;
        obj->AllocSize = newAlloc;
    }

    // write data
    RtlCopyMemory((PUCHAR)obj->Data + offset, data, dataLen);
    if (offset + dataLen > obj->Size) obj->Size = offset + dataLen;
    WdfSpinLockRelease(gObjectLock);

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

    tid = (ULONG)InterlockedIncrement((PLONG)&gTransactionCounter);

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
    const ULONG READ_BUF_SIZE = 16384;
    ULONG bytesRead;
    ULONG containerLen;
    USHORT containerType;
    USHORT containerCode;
    ULONG containerTid;

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

    readBuf = (PUCHAR)ExAllocatePoolWithTag(NonPagedPool, READ_BUF_SIZE, 'rmtp');
    if (!readBuf) return STATUS_INSUFFICIENT_RESOURCES;

    bytesRead = 0;
    st = MtpUsb_ReadBulk(Device, inPipe, readBuf, READ_BUF_SIZE, &bytesRead);
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

    // Handle DATA container (Type 2)
    if (containerType == 2) {
        ULONG payloadLen;
        ULONG copied;
        PVOID fullData;

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

            // Read remaining data chunks if buffer spanned multiple reads
            while (copied < payloadLen) {
                ULONG chunkRead;
                ULONG toCopy;
                chunkRead = 0;
                toCopy = 0;
                st = MtpUsb_ReadBulk(Device, inPipe, readBuf, READ_BUF_SIZE, &chunkRead);
                if (!NT_SUCCESS(st) || chunkRead == 0) break;
                toCopy = chunkRead;
                if (copied + toCopy > payloadLen) toCopy = payloadLen - copied;
                RtlCopyMemory((PUCHAR)fullData + copied, readBuf, toCopy);
                copied += toCopy;
            }

            *OutData = fullData;
            *OutDataLen = copied;
        }

        // Check if RESPONSE container was concatenated in the same buffer
        if (bytesRead >= containerLen + 12) {
            USHORT respType;
            USHORT respCode;
            respType = 0;
            respCode = 0;
            RtlCopyMemory(&respType, readBuf + containerLen + 4, sizeof(USHORT));
            RtlCopyMemory(&respCode, readBuf + containerLen + 6, sizeof(USHORT));
            if (respType == 3) {
                *OutResponse = respCode;
            }
        } else {
            // Read next packet from Bulk IN for the RESPONSE container
            ULONG respBytes;
            USHORT respType;
            USHORT respCode;
            respBytes = 0;
            respType = 0;
            respCode = 0;
            st = MtpUsb_ReadBulk(Device, inPipe, readBuf, READ_BUF_SIZE, &respBytes);
            if (NT_SUCCESS(st) && respBytes >= 12) {
                RtlCopyMemory(&respType, readBuf + 4, sizeof(USHORT));
                RtlCopyMemory(&respCode, readBuf + 6, sizeof(USHORT));
                if (respType == 3) {
                    *OutResponse = respCode;
                }
            }
        }

        ExFreePoolWithTag(readBuf, 'rmtp');
        return STATUS_SUCCESS;
    }

    // Handle RESPONSE container (Type 3)
    if (containerType == 3) {
        *OutResponse = containerCode;
        ExFreePoolWithTag(readBuf, 'rmtp');
        return STATUS_SUCCESS;
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

    /* Accept OK (0x2001) or SessionAlreadyOpen (0x201E) as success */
    if (!NT_SUCCESS(status)) {
        KdPrint(("MTP: OpenSession USB send failed 0x%08x\n", status));
        /* Fall through - still report the local session so the app can try operations */
    } else {
        KdPrint(("MTP: OpenSession response code 0x%04x\n", (ULONG)respCode));
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
    ULONG sessionParam;
    PVOID respData;
    size_t respLen;
    USHORT respCode;
    NTSTATUS status;

    device = WdfRequestGetDevice(Request);
    ctx = DeviceGetContext(device);

    /* Send the actual MTP CloseSession (0x1003) command */
    if (ctx->SessionId != 0) {
        sessionParam = ctx->SessionId;
        respData = NULL;
        respLen = 0;
        respCode = 0;
        status = MtpSendOperationAndReceiveData(device, 0x1003, &sessionParam, 1,
                                                NULL, 0, &respData, &respLen, &respCode);
        if (respData) ExFreePoolWithTag(respData, 'dout');
        KdPrint(("MTP: CloseSession response 0x%04x (st=0x%08x)\n", (ULONG)respCode, status));
    }

    ctx->SessionId = 0;
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

    paramCount = 0;
    params[0] = 0;
    params[1] = 0;
    params[2] = 0;
    params[3] = 0;
    params[4] = 0;
    offset = sizeof(ULONG);
    while (paramCount < 5 && offset + sizeof(ULONG) <= inLen) {
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

        if (opcode == 0x1004) {
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

        if (opcode == 0x1005) {
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

        if (opcode == 0x1007) {
            // GetObjectHandles
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

        if (opcode == 0x1008 && paramCount >= 1) {
            // GetObjectInfo
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

        if (opcode == 0x1009 && paramCount >= 1) {
            // GetObject
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

        if (opcode == 0x100B && paramCount >= 1) {
            // DeleteObject
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

    KdPrint(("MTP: Cleanup completed successfully\n"));
    return STATUS_SUCCESS;
}
