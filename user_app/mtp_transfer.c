/*
 * mtp_transfer.c - MTP File Transfer Application for Windows 2000
 * 
 * This application uses the MTP KMDF driver to browse and transfer files
 * between the PC and MTP devices (phones, cameras, etc.)
 * 
 * Compile using Windows 2000 SDK:
 *   cl /O2 /W3 mtp_transfer.c /link /subsystem:console kernel32.lib user32.lib
 */

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ============================================================================
 * IOCTL Definitions (must match driver's Mtp.h)
 * ============================================================================ */

#ifndef FILE_DEVICE_UNKNOWN
#define FILE_DEVICE_UNKNOWN 0x00000022
#endif
#ifndef METHOD_BUFFERED
#define METHOD_BUFFERED 0
#endif
#ifndef FILE_READ_DATA
#define FILE_READ_DATA 0x0001
#endif
#ifndef FILE_WRITE_DATA
#define FILE_WRITE_DATA 0x0002
#endif

#ifndef CTL_CODE
#define CTL_CODE(DeviceType, Function, Method, Access) \
    (((DeviceType) << 16) | ((Access) << 14) | ((Function) << 2) | (Method))
#endif

#define IOCTL_MTP_GET_DEVICE_INFO    CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_READ_DATA)
#define IOCTL_MTP_LIST_OBJECTS       CTL_CODE(FILE_DEVICE_UNKNOWN, 0x801, METHOD_BUFFERED, FILE_READ_DATA)
#define IOCTL_MTP_GET_OBJECT_PART    CTL_CODE(FILE_DEVICE_UNKNOWN, 0x802, METHOD_BUFFERED, FILE_READ_DATA)
#define IOCTL_MTP_SEND_OBJECT_PART   CTL_CODE(FILE_DEVICE_UNKNOWN, 0x803, METHOD_BUFFERED, FILE_WRITE_DATA)
#define IOCTL_MTP_SESSION_OPEN       CTL_CODE(FILE_DEVICE_UNKNOWN, 0x810, METHOD_BUFFERED, FILE_READ_DATA)
#define IOCTL_MTP_SESSION_CLOSE      CTL_CODE(FILE_DEVICE_UNKNOWN, 0x811, METHOD_BUFFERED, FILE_READ_DATA)
#define IOCTL_MTP_OPERATION          CTL_CODE(FILE_DEVICE_UNKNOWN, 0x812, METHOD_BUFFERED, FILE_READ_DATA)
#define IOCTL_MTP_GET_TRANSFER_SPEED CTL_CODE(FILE_DEVICE_UNKNOWN, 0x815, METHOD_BUFFERED, FILE_READ_DATA)

/* Default device symbolic link name */
#define DEVICE_NAME "\\\\.\\MtpDevice"

/* MTP Operation Codes */
#define MTP_OP_GET_DEVICE_INFO       0x1001
#define MTP_OP_OPEN_SESSION          0x1002
#define MTP_OP_CLOSE_SESSION         0x1003
#define MTP_OP_GET_STORAGE_IDS       0x1004
#define MTP_OP_GET_STORAGE_INFO      0x1005
#define MTP_OP_GET_NUM_OBJECTS       0x1006
#define MTP_OP_GET_OBJECT_HANDLES    0x1007
#define MTP_OP_GET_OBJECT_INFO       0x1008
#define MTP_OP_GET_OBJECT            0x1009
#define MTP_OP_GET_THUMB             0x100A
#define MTP_OP_DELETE_OBJECT         0x100B
#define MTP_OP_SEND_OBJECT_INFO      0x100C
#define MTP_OP_SEND_OBJECT           0x100D
#define MTP_OP_GET_PARTIAL_OBJECT    0x101B
#define MTP_OP_GET_OBJECT_PROPS_SUPP 0x9801
#define MTP_OP_GET_OBJECT_PROP_DESC  0x9802
#define MTP_OP_GET_OBJECT_PROP_VALUE 0x9803
#define MTP_OP_SET_OBJECT_PROP_VALUE 0x9804

/* MTP Response Codes */
#define MTP_RESP_OK                  0x2001
#define MTP_RESP_GENERAL_ERROR       0x2002
#define MTP_RESP_SESSION_NOT_OPEN    0x2003
#define MTP_RESP_INVALID_TRANSACTION_ID 0x2004
#define MTP_RESP_OPERATION_NOT_SUPPORTED 0x2005
#define MTP_RESP_PARAMETER_NOT_SUPPORTED 0x2006
#define MTP_RESP_INCOMPLETE_TRANSFER 0x2007
#define MTP_RESP_INVALID_STORAGE_ID  0x2008
#define MTP_RESP_INVALID_OBJECT_HANDLE 0x2009
#define MTP_RESP_DEVICE_BUSY         0x2019

/* MTP Object Format Codes */
#define MTP_FORMAT_UNDEFINED         0x3000
#define MTP_FORMAT_ASSOCIATION       0x3001  /* Folder */
#define MTP_FORMAT_SCRIPT            0x3002
#define MTP_FORMAT_EXECUTABLE        0x3003
#define MTP_FORMAT_TEXT              0x3004
#define MTP_FORMAT_HTML              0x3005
#define MTP_FORMAT_DPOF              0x3006
#define MTP_FORMAT_AIFF              0x3007
#define MTP_FORMAT_WAV               0x3008
#define MTP_FORMAT_MP3               0x3009
#define MTP_FORMAT_AVI               0x300A
#define MTP_FORMAT_MPEG              0x300B
#define MTP_FORMAT_ASF               0x300C
#define MTP_FORMAT_EXIF_JPEG         0x3801
#define MTP_FORMAT_TIFF_EP           0x3802
#define MTP_FORMAT_BMP               0x3804
#define MTP_FORMAT_GIF               0x3807
#define MTP_FORMAT_JFIF              0x3808
#define MTP_FORMAT_PNG               0x380B
#define MTP_FORMAT_TIFF              0x380D
#define MTP_FORMAT_WMA               0xB901
#define MTP_FORMAT_OGG               0xB902
#define MTP_FORMAT_AAC               0xB903
#define MTP_FORMAT_MP4_CONTAINER     0xB982
#define MTP_FORMAT_MP2               0xB983
#define MTP_FORMAT_3GP_CONTAINER     0xB984
#define MTP_FORMAT_UNDEFINED_AUDIO   0xB900
#define MTP_FORMAT_WMV               0xB981
#define MTP_FORMAT_UNDEFINED_VIDEO   0xB980

/* ============================================================================
 * Structures
 * ============================================================================ */

/* Request structure for GetObjectPart IOCTL (64-bit offsets, matches driver) */
#pragma pack(push, 1)
typedef struct _MTP_GET_PART_REQ {
    DWORD Id;
    DWORD OffsetLow;
    DWORD OffsetHigh;
    DWORD Length;
} MTP_GET_PART_REQ, *PMTP_GET_PART_REQ;

/* Dynamic USB transfer speed info (matches driver) */
typedef struct _MTP_SPEED_INFO {
    DWORD ControllerType;    /* 1=UHCI/OHCI (USB 1.1), 2=EHCI (USB 2.0), 3=xHCI (USB 3.x/4) */
    DWORD MaxPacketSize;     /* 64, 512, or 1024 */
    DWORD OptimalChunkSize;  /* 16384 (16KB), 65536 (64KB), or 262144 (256KB) */
    CHAR  Description[64];
} MTP_SPEED_INFO, *PMTP_SPEED_INFO;
#pragma pack(pop)

/* Object info structure (simplified) */
typedef struct _MTP_OBJECT_INFO {
    DWORD StorageId;
    WORD  ObjectFormat;
    WORD  ProtectionStatus;
    DWORD CompressedSize;
    WORD  ThumbFormat;
    DWORD ThumbCompressedSize;
    DWORD ThumbPixWidth;
    DWORD ThumbPixHeight;
    DWORD ImagePixWidth;
    DWORD ImagePixHeight;
    DWORD ImageBitDepth;
    DWORD ParentObject;
    WORD  AssociationType;
    DWORD AssociationDesc;
    DWORD SequenceNumber;
    /* Followed by MTP strings for Filename, DateCreated, DateModified, Keywords */
} MTP_OBJECT_INFO, *PMTP_OBJECT_INFO;

/* Global state */
static HANDLE g_hDevice = INVALID_HANDLE_VALUE;
static DWORD  g_sessionId = 0;
static BOOL   g_sessionOpen = FALSE;

/* ============================================================================
 * Helper Functions
 * ============================================================================ */

/* Print a buffer in hex format */
void PrintHexDump(const BYTE *buffer, DWORD size, DWORD maxBytes)
{
    DWORD i;
    DWORD limit = (size < maxBytes) ? size : maxBytes;
    
    for (i = 0; i < limit; i++) {
        printf("%02X ", buffer[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }
    if (limit % 16 != 0) printf("\n");
    if (size > maxBytes) printf("... (%lu more bytes)\n", size - maxBytes);
}

/* Format 64-bit file size */
void FormatFileSize64(ULONGLONG bytes, char *buf, size_t bufSize)
{
    if (bytes < 1024ULL) {
        _snprintf(buf, bufSize, "%u B", (DWORD)bytes);
    } else if (bytes < 1048576ULL) {
        _snprintf(buf, bufSize, "%.2f KB", (double)bytes / 1024.0);
    } else if (bytes < 1073741824ULL) {
        _snprintf(buf, bufSize, "%.2f MB", (double)bytes / 1048576.0);
    } else {
        _snprintf(buf, bufSize, "%.2f GB", (double)bytes / 1073741824.0);
    }
}

/* Read MTP string from buffer (returns pointer past string, NULL on error) */
BYTE* ReadMtpString(BYTE *buf, DWORD maxLen, WCHAR *outStr, DWORD outMaxChars)
{
    BYTE len;
    DWORD i;
    
    if (maxLen < 1) return NULL;
    len = buf[0];  /* String length in WCHAR including null terminator */
    
    if (len == 0) {
        outStr[0] = L'\0';
        return buf + 1;
    }
    
    if (maxLen < (DWORD)(1 + len * 2)) return NULL;
    
    /* Copy string (len includes null terminator) */
    for (i = 0; i < len && i < outMaxChars - 1; i++) {
        outStr[i] = (WCHAR)(buf[1 + i*2] | (buf[1 + i*2 + 1] << 8));
    }
    outStr[i] = L'\0';
    
    return buf + 1 + len * 2;
}

/* Get format name from format code */
const char* GetFormatName(WORD format)
{
    switch (format) {
        case MTP_FORMAT_UNDEFINED:       return "Undefined";
        case MTP_FORMAT_ASSOCIATION:     return "Folder";
        case MTP_FORMAT_TEXT:            return "Text";
        case MTP_FORMAT_HTML:            return "HTML";
        case MTP_FORMAT_MP3:             return "MP3";
        case MTP_FORMAT_WAV:             return "WAV";
        case MTP_FORMAT_AVI:             return "AVI";
        case MTP_FORMAT_MPEG:            return "MPEG";
        case MTP_FORMAT_ASF:             return "ASF";
        case MTP_FORMAT_EXIF_JPEG:       return "JPEG";
        case MTP_FORMAT_BMP:             return "BMP";
        case MTP_FORMAT_GIF:             return "GIF";
        case MTP_FORMAT_PNG:             return "PNG";
        case MTP_FORMAT_TIFF:            return "TIFF";
        case MTP_FORMAT_WMA:             return "WMA";
        case MTP_FORMAT_OGG:             return "OGG";
        case MTP_FORMAT_AAC:             return "AAC";
        case MTP_FORMAT_MP4_CONTAINER:   return "MP4";
        case MTP_FORMAT_3GP_CONTAINER:   return "3GP";
        case MTP_FORMAT_WMV:             return "WMV";
        default:                         return "Unknown";
    }
}

/* ============================================================================
 * Driver Communication Functions
 * ============================================================================ */

/* Open the MTP device driver */
BOOL OpenMtpDevice(const char *deviceName)
{
    g_hDevice = CreateFileA(
        deviceName,
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );
    
    if (g_hDevice == INVALID_HANDLE_VALUE) {
        printf("ERROR: Failed to open device '%s'\n", deviceName);
        printf("Error code: %lu\n", GetLastError());
        return FALSE;
    }
    
    printf("Device opened successfully: %s\n", deviceName);
    return TRUE;
}

/* Close the MTP device driver */
void CloseMtpDevice(void)
{
    if (g_hDevice != INVALID_HANDLE_VALUE) {
        CloseHandle(g_hDevice);
        g_hDevice = INVALID_HANDLE_VALUE;
        printf("Device closed.\n");
    }
}

/* Open an MTP session */
BOOL MtpOpenSession(void)
{
    DWORD bytesReturned;
    BOOL result;
    
    if (g_sessionOpen) {
        printf("Session already open (ID: 0x%08lX)\n", g_sessionId);
        return TRUE;
    }
    
    result = DeviceIoControl(
        g_hDevice,
        IOCTL_MTP_SESSION_OPEN,
        NULL, 0,
        &g_sessionId, sizeof(g_sessionId),
        &bytesReturned,
        NULL
    );
    
    if (result) {
        g_sessionOpen = TRUE;
        printf("MTP Session opened. Session ID: 0x%08lX\n", g_sessionId);
        return TRUE;
    } else {
        printf("ERROR: Failed to open MTP session. Error: %lu\n", GetLastError());
        return FALSE;
    }
}

/* Close MTP session */
BOOL MtpCloseSession(void)
{
    DWORD bytesReturned;
    BOOL result;
    
    if (!g_sessionOpen) {
        printf("No session open.\n");
        return TRUE;
    }
    
    result = DeviceIoControl(
        g_hDevice,
        IOCTL_MTP_SESSION_CLOSE,
        NULL, 0,
        NULL, 0,
        &bytesReturned,
        NULL
    );
    
    if (result) {
        g_sessionOpen = FALSE;
        g_sessionId = 0;
        printf("MTP Session closed.\n");
        return TRUE;
    } else {
        printf("ERROR: Failed to close MTP session. Error: %lu\n", GetLastError());
        return FALSE;
    }
}

/* Send a generic MTP operation and receive response */
BOOL MtpSendOperation(WORD opcode, DWORD *params, DWORD paramCount,
                      BYTE *sendData, DWORD sendDataLen,
                      BYTE *recvBuffer, DWORD recvBufferSize,
                      DWORD *bytesReceived)
{
    BYTE *inputBuffer;
    DWORD inputSize;
    DWORD i;
    DWORD offset;
    BOOL result;
    DWORD bytesRet;
    
    /* Build input: [DWORD opcode][DWORD param0]...[DWORD paramN][data...] */
    inputSize = sizeof(DWORD) + (paramCount * sizeof(DWORD)) + sendDataLen;
    inputBuffer = (BYTE*)malloc(inputSize);
    if (!inputBuffer) {
        printf("ERROR: Memory allocation failed\n");
        return FALSE;
    }
    
    offset = 0;
    *((DWORD*)(inputBuffer + offset)) = (DWORD)opcode;
    offset += sizeof(DWORD);
    
    for (i = 0; i < paramCount; i++) {
        *((DWORD*)(inputBuffer + offset)) = params[i];
        offset += sizeof(DWORD);
    }
    
    if (sendData && sendDataLen > 0) {
        memcpy(inputBuffer + offset, sendData, sendDataLen);
    }
    
    bytesRet = 0;
    result = DeviceIoControl(
        g_hDevice,
        IOCTL_MTP_OPERATION,
        inputBuffer, inputSize,
        recvBuffer, recvBufferSize,
        &bytesRet,
        NULL
    );
    
    free(inputBuffer);
    
    if (bytesReceived) *bytesReceived = bytesRet;
    
    if (!result) {
        printf("ERROR: MTP Operation 0x%04X failed. Error: %lu\n", opcode, GetLastError());
        return FALSE;
    }
    
    return TRUE;
}

/* Get device info */
BOOL MtpGetDeviceInfo(void)
{
    BYTE buffer[4096];
    DWORD bytesReturned;
    BOOL result;
    BYTE *p;
    WORD standardVersion;
    DWORD vendorExtId;
    WORD vendorExtVersion;
    WCHAR vendorExtDesc[256];
    
    printf("\n--- Device Information ---\n");
    
    result = DeviceIoControl(
        g_hDevice,
        IOCTL_MTP_GET_DEVICE_INFO,
        NULL, 0,
        buffer, sizeof(buffer),
        &bytesReturned,
        NULL
    );
    
    if (!result) {
        printf("ERROR: Failed to get device info. Error: %lu\n", GetLastError());
        return FALSE;
    }
    
    if (bytesReturned < 8) {
        printf("Received %lu bytes (insufficient for parsing)\n", bytesReturned);
        PrintHexDump(buffer, bytesReturned, 256);
        return FALSE;
    }
    
    p = buffer;
    
    /* Parse DeviceInfo dataset */
    standardVersion = *((WORD*)p); p += 2;
    vendorExtId = *((DWORD*)p); p += 4;
    vendorExtVersion = *((WORD*)p); p += 2;
    
    printf("MTP/PTP Standard Version: %u.%02u\n", standardVersion / 100, standardVersion % 100);
    printf("Vendor Extension ID: 0x%08lX\n", vendorExtId);
    printf("Vendor Extension Version: %u.%02u\n", vendorExtVersion / 100, vendorExtVersion % 100);
    
    /* Skip to strings (simplified parsing - actual format is more complex) */
    if (bytesReturned > 64) {
        /* Try to find and parse strings at end of data */
        p = ReadMtpString(p, (DWORD)(buffer + bytesReturned - p), vendorExtDesc, 256);
        if (p) wprintf(L"Vendor Extension: %s\n", vendorExtDesc);
        
        /* Skip functional mode, operations, events, properties arrays... 
           For a full implementation, parse these properly */
    }
    
    printf("Raw data (%lu bytes):\n", bytesReturned);
    PrintHexDump(buffer, bytesReturned, 128);
    
    return TRUE;
}

/* Get storage IDs */
BOOL MtpGetStorageIds(DWORD *storageIds, DWORD maxIds, DWORD *count)
{
    BYTE buffer[1024];
    DWORD bytesReceived;
    DWORD numIds;
    DWORD i;
    DWORD params[1];
    
    params[0] = 0;  /* No parameters for GetStorageIDs */
    
    if (!MtpSendOperation(MTP_OP_GET_STORAGE_IDS, NULL, 0, NULL, 0,
                          buffer, sizeof(buffer), &bytesReceived)) {
        return FALSE;
    }
    
    if (bytesReceived < sizeof(DWORD)) {
        printf("ERROR: Invalid response size\n");
        return FALSE;
    }
    
    numIds = *((DWORD*)buffer);
    printf("Found %lu storage(s)\n", numIds);
    
    if (count) *count = numIds;
    
    for (i = 0; i < numIds && i < maxIds; i++) {
        if ((i + 1) * sizeof(DWORD) + sizeof(DWORD) <= bytesReceived) {
            storageIds[i] = *((DWORD*)(buffer + sizeof(DWORD) + i * sizeof(DWORD)));
            printf("  Storage %lu: ID 0x%08lX\n", i + 1, storageIds[i]);
        }
    }
    
    return TRUE;
}

/* Get object handles from a storage */
BOOL MtpGetObjectHandles(DWORD storageId, DWORD parentHandle, 
                         DWORD *handles, DWORD maxHandles, DWORD *count)
{
    BYTE buffer[8192];
    DWORD bytesReceived;
    DWORD params[3];
    DWORD numHandles;
    DWORD i;
    
    params[0] = storageId;       /* Storage ID (0xFFFFFFFF = all) */
    params[1] = 0;               /* Object format filter (0 = all) */
    params[2] = parentHandle;    /* Parent object (0 = root, 0xFFFFFFFF = all) */
    
    if (!MtpSendOperation(MTP_OP_GET_OBJECT_HANDLES, params, 3, NULL, 0,
                          buffer, sizeof(buffer), &bytesReceived)) {
        return FALSE;
    }
    
    if (bytesReceived < sizeof(DWORD)) {
        printf("ERROR: Invalid response size\n");
        return FALSE;
    }
    
    numHandles = *((DWORD*)buffer);
    if (count) *count = numHandles;
    
    printf("Found %lu object(s)\n", numHandles);
    
    for (i = 0; i < numHandles && i < maxHandles; i++) {
        if ((i + 1) * sizeof(DWORD) + sizeof(DWORD) <= bytesReceived) {
            handles[i] = *((DWORD*)(buffer + sizeof(DWORD) + i * sizeof(DWORD)));
        }
    }
    
    return TRUE;
}

/* Get object info */
BOOL MtpGetObjectInfo(DWORD objectHandle)
{
    BYTE buffer[4096];
    DWORD bytesReceived;
    DWORD params[1];
    BYTE *p;
    DWORD storageId;
    WORD objectFormat;
    WORD protectionStatus;
    DWORD compressedSize;
    DWORD parentObject;
    WCHAR filename[256];
    
    params[0] = objectHandle;
    
    if (!MtpSendOperation(MTP_OP_GET_OBJECT_INFO, params, 1, NULL, 0,
                          buffer, sizeof(buffer), &bytesReceived)) {
        return FALSE;
    }
    
    if (bytesReceived < 52) {
        printf("  Object 0x%08lX: Invalid info (only %lu bytes)\n", objectHandle, bytesReceived);
        return FALSE;
    }
    
    p = buffer;
    
    storageId = *((DWORD*)p); p += 4;
    objectFormat = *((WORD*)p); p += 2;
    protectionStatus = *((WORD*)p); p += 2;
    compressedSize = *((DWORD*)p); p += 4;
    
    /* Skip thumbnail info (16 bytes) */
    p += 16;
    
    /* Skip image info (12 bytes) */
    p += 12;
    
    parentObject = *((DWORD*)p); p += 4;
    
    /* Skip association info (6 bytes) */
    p += 6;
    
    /* Skip sequence number (4 bytes) */
    p += 4;
    
    /* Read filename string */
    filename[0] = L'\0';
    if ((DWORD)(p - buffer) < bytesReceived) {
        ReadMtpString(p, (DWORD)(buffer + bytesReceived - p), filename, 256);
    }
    
    /* 64-bit file size support */
    {
        ULONGLONG trueSize = (ULONGLONG)compressedSize;
        char sizeStr[32];
        if (compressedSize == 0xFFFFFFFF && objectFormat != MTP_FORMAT_ASSOCIATION) {
            BYTE propBuf[16];
            DWORD propBytes = 0;
            DWORD propParams[2];
            propParams[0] = objectHandle;
            propParams[1] = 0xDC04; /* ObjectSize property (64-bit) */
            if (MtpSendOperation(MTP_OP_GET_OBJECT_PROP_VALUE, propParams, 2, NULL, 0, propBuf, sizeof(propBuf), &propBytes) && propBytes >= 8) {
                DWORD low = *((DWORD*)(propBuf + 0));
                DWORD high = *((DWORD*)(propBuf + 4));
                trueSize = ((ULONGLONG)high << 32) | (ULONGLONG)low;
            }
        }
        FormatFileSize64(trueSize, sizeStr, sizeof(sizeStr));
        wprintf(L"  Object 0x%08lX: %s [%hs] Size: %hs (%I64u bytes), Parent: 0x%08lX\n",
               objectHandle, filename, GetFormatName(objectFormat), 
               sizeStr, trueSize, parentObject);
    }
    
    return TRUE;
}

/* List all objects in storage */
BOOL MtpListObjects(DWORD storageId)
{
    DWORD handles[256];
    DWORD count;
    DWORD i;
    
    printf("\n--- Listing Objects ---\n");
    printf("Storage ID: 0x%08lX\n", storageId);
    
    if (!MtpGetObjectHandles(storageId, 0xFFFFFFFF, handles, 256, &count)) {
        return FALSE;
    }
    
    for (i = 0; i < count && i < 256; i++) {
        MtpGetObjectInfo(handles[i]);
    }
    
    return TRUE;
}

/* Download a file from device */
BOOL MtpDownloadFile(DWORD objectHandle, const char *localPath)
{
    HANDLE hFile;
    BYTE *buffer;
    DWORD chunkSize = 65536;
    MTP_GET_PART_REQ req;
    DWORD bytesReturned;
    DWORD bytesWritten;
    ULONGLONG totalBytes = 0;
    BOOL result;
    DWORD startTick, lastTick, curTick;
    MTP_SPEED_INFO speedInfo;
    DWORD speedRet = 0;
    char sizeStr[32];
    
    printf("\n--- Downloading Object 0x%08lX ---\n", objectHandle);
    printf("Saving to: %s\n", localPath);
    
    /* Query optimal speed/chunk size from driver */
    if (DeviceIoControl(g_hDevice, IOCTL_MTP_GET_TRANSFER_SPEED, NULL, 0,
                        &speedInfo, sizeof(speedInfo), &speedRet, NULL) && speedRet >= sizeof(DWORD)*3) {
        if (speedInfo.OptimalChunkSize >= 16384 && speedInfo.OptimalChunkSize <= 262144) {
            chunkSize = speedInfo.OptimalChunkSize;
        }
        printf("USB Controller: %s (Optimal Chunk: %lu KB)\n", 
               (speedInfo.ControllerType == 1) ? "USB 1.1 Full-Speed (UHCI/OHCI)" :
               (speedInfo.ControllerType == 2) ? "USB 2.0 High-Speed (EHCI)" :
               (speedInfo.ControllerType == 3) ? "USB 3.x/4 SuperSpeed (xHCI)" : "Standard MTP",
               chunkSize / 1024);
    }
    
    buffer = (BYTE*)malloc(chunkSize);
    if (!buffer) {
        printf("ERROR: Memory allocation failed for chunk buffer (%lu bytes)\n", chunkSize);
        return FALSE;
    }
    
    hFile = CreateFileA(localPath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        printf("ERROR: Cannot create file '%s' (Error %lu)\n", localPath, GetLastError());
        free(buffer);
        return FALSE;
    }
    
    startTick = GetTickCount();
    lastTick = startTick;
    
    req.Id = objectHandle;
    req.OffsetLow = 0;
    req.OffsetHigh = 0;
    req.Length = chunkSize;
    
    while (1) {
        result = DeviceIoControl(
            g_hDevice,
            IOCTL_MTP_GET_OBJECT_PART,
            &req, sizeof(req),
            buffer, chunkSize,
            &bytesReturned,
            NULL
        );
        
        if (!result) {
            DWORD err = GetLastError();
            if (err == ERROR_HANDLE_EOF || bytesReturned == 0) {
                break;
            }
            printf("\nERROR: Failed to read object part at offset %lu. Error: %lu\n", req.OffsetLow, err);
            CloseHandle(hFile);
            free(buffer);
            return FALSE;
        }
        
        if (bytesReturned == 0) break;
        
        if (!WriteFile(hFile, buffer, bytesReturned, &bytesWritten, NULL) || bytesWritten != bytesReturned) {
            printf("\nERROR: Failed to write to disk. Error: %lu\n", GetLastError());
            CloseHandle(hFile);
            free(buffer);
            return FALSE;
        }
        
        totalBytes += bytesReturned;
        
        /* 64-bit offset calculation */
        {
            ULONGLONG nextOff = ((ULONGLONG)req.OffsetHigh << 32) | (ULONGLONG)req.OffsetLow;
            nextOff += bytesReturned;
            req.OffsetLow = (DWORD)(nextOff & 0xFFFFFFFF);
            req.OffsetHigh = (DWORD)(nextOff >> 32);
        }
        
        curTick = GetTickCount();
        if (curTick - lastTick >= 200 || bytesReturned < chunkSize) {
            DWORD elapsedMs = curTick - startTick;
            double speedMB = 0.0;
            if (elapsedMs > 0) {
                speedMB = ((double)totalBytes / 1048576.0) / ((double)elapsedMs / 1000.0);
            }
            FormatFileSize64(totalBytes, sizeStr, sizeof(sizeStr));
            printf("\rDownloaded: %s [%.2f MB/s]...", sizeStr, speedMB);
            fflush(stdout);
            lastTick = curTick;
        }
        
        if (bytesReturned < chunkSize) break;
    }
    
    CloseHandle(hFile);
    free(buffer);
    
    FormatFileSize64(totalBytes, sizeStr, sizeof(sizeStr));
    {
        DWORD totalMs = GetTickCount() - startTick;
        double avgSpeed = 0.0;
        if (totalMs > 0) {
            avgSpeed = ((double)totalBytes / 1048576.0) / ((double)totalMs / 1000.0);
        }
        printf("\nDownload complete: %s in %.1f sec (Avg: %.2f MB/s)\n", sizeStr, (double)totalMs / 1000.0, avgSpeed);
    }
    return TRUE;
}

/* Upload a file to device */
BOOL MtpUploadFile(const char *localPath, DWORD parentHandle)
{
    HANDLE hFile;
    BYTE *buffer;
    DWORD chunkSize = 65536;
    DWORD headerSize = 8; /* [DWORD id][DWORD offset] */
    DWORD bufferSize;
    DWORD bytesRead;
    ULONGLONG totalBytes = 0;
    ULONGLONG fileSize = 0;
    DWORD fileSizeLow, fileSizeHigh = 0;
    DWORD objectId = 0;
    DWORD bytesReturned;
    BOOL result;
    DWORD startTick, lastTick, curTick;
    MTP_SPEED_INFO speedInfo;
    DWORD speedRet = 0;
    char sizeStr[32];
    
    printf("\n--- Uploading File ---\n");
    printf("Source: %s\n", localPath);
    printf("Parent Object: 0x%08lX\n", parentHandle);
    
    if (DeviceIoControl(g_hDevice, IOCTL_MTP_GET_TRANSFER_SPEED, NULL, 0,
                        &speedInfo, sizeof(speedInfo), &speedRet, NULL) && speedRet >= sizeof(DWORD)*3) {
        if (speedInfo.OptimalChunkSize >= 16384 && speedInfo.OptimalChunkSize <= 262144) {
            chunkSize = speedInfo.OptimalChunkSize;
        }
        printf("USB Controller: %s (Optimal Chunk: %lu KB)\n", 
               (speedInfo.ControllerType == 1) ? "USB 1.1 Full-Speed (UHCI/OHCI)" :
               (speedInfo.ControllerType == 2) ? "USB 2.0 High-Speed (EHCI)" :
               (speedInfo.ControllerType == 3) ? "USB 3.x/4 SuperSpeed (xHCI)" : "Standard MTP",
               chunkSize / 1024);
    }
    
    hFile = CreateFileA(localPath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        printf("ERROR: Cannot open file '%s' (Error %lu)\n", localPath, GetLastError());
        return FALSE;
    }
    
    fileSizeLow = GetFileSize(hFile, &fileSizeHigh);
    fileSize = ((ULONGLONG)fileSizeHigh << 32) | (ULONGLONG)fileSizeLow;
    FormatFileSize64(fileSize, sizeStr, sizeof(sizeStr));
    printf("File size: %s (%I64u bytes)\n", sizeStr, fileSize);
    
    /* Buffer format: [DWORD id][DWORD offset][data...] */
    bufferSize = headerSize + chunkSize;
    buffer = (BYTE*)malloc(bufferSize);
    if (!buffer) {
        printf("ERROR: Memory allocation failed\n");
        CloseHandle(hFile);
        return FALSE;
    }
    
    startTick = GetTickCount();
    lastTick = startTick;
    
    while (ReadFile(hFile, buffer + headerSize, chunkSize, &bytesRead, NULL) && bytesRead > 0) {
        *((DWORD*)(buffer + 0)) = objectId;
        *((DWORD*)(buffer + 4)) = (DWORD)(totalBytes & 0xFFFFFFFF);
        
        result = DeviceIoControl(
            g_hDevice,
            IOCTL_MTP_SEND_OBJECT_PART,
            buffer, headerSize + bytesRead,
            &objectId, sizeof(objectId),
            &bytesReturned,
            NULL
        );
        
        if (!result) {
            printf("\nERROR: Failed to send object part. Error: %lu\n", GetLastError());
            free(buffer);
            CloseHandle(hFile);
            return FALSE;
        }
        
        if (totalBytes == 0 && bytesReturned >= sizeof(DWORD)) {
            printf("Created object ID: 0x%08lX\n", objectId);
        }
        
        totalBytes += bytesRead;
        
        curTick = GetTickCount();
        if (curTick - lastTick >= 200 || totalBytes >= fileSize) {
            DWORD elapsedMs = curTick - startTick;
            double speedMB = 0.0;
            double pct = (fileSize > 0) ? ((double)totalBytes * 100.0 / (double)fileSize) : 0.0;
            if (elapsedMs > 0) {
                speedMB = ((double)totalBytes / 1048576.0) / ((double)elapsedMs / 1000.0);
            }
            FormatFileSize64(totalBytes, sizeStr, sizeof(sizeStr));
            printf("\rUploaded: %s (%.1f%%) [%.2f MB/s]...", sizeStr, pct, speedMB);
            fflush(stdout);
            lastTick = curTick;
        }
    }
    
    free(buffer);
    CloseHandle(hFile);
    
    FormatFileSize64(totalBytes, sizeStr, sizeof(sizeStr));
    {
        DWORD totalMs = GetTickCount() - startTick;
        double avgSpeed = 0.0;
        if (totalMs > 0) {
            avgSpeed = ((double)totalBytes / 1048576.0) / ((double)totalMs / 1000.0);
        }
        printf("\nUpload complete: %s in %.1f sec (Avg: %.2f MB/s)\n", sizeStr, (double)totalMs / 1000.0, avgSpeed);
    }
    return TRUE;
}

/* ============================================================================
 * Interactive Menu
 * ============================================================================ */

void PrintMenu(void)
{
    printf("\n");
    printf("==============================================\n");
    printf(" MTP File Transfer - Windows 2000\n");
    printf("==============================================\n");
    printf("  1. Open MTP Session\n");
    printf("  2. Get Device Info\n");
    printf("  3. List Storages\n");
    printf("  4. List Objects (in storage)\n");
    printf("  5. Get Object Info\n");
    printf("  6. Download File\n");
    printf("  7. Upload File\n");
    printf("  8. Close MTP Session\n");
    printf("  9. Exit\n");
    printf("==============================================\n");
    printf("Session: %s", g_sessionOpen ? "OPEN" : "CLOSED");
    if (g_sessionOpen) printf(" (ID: 0x%08lX)", g_sessionId);
    printf("\n");
    printf("Choice: ");
}

void InteractiveMode(void)
{
    char input[256];
    int choice;
    DWORD storageIds[16];
    DWORD storageCount;
    DWORD storageId;
    DWORD objectHandle;
    char filename[MAX_PATH];
    
    storageCount = 0;
    
    while (1) {
        PrintMenu();
        
        if (!fgets(input, sizeof(input), stdin)) break;
        choice = atoi(input);
        
        switch (choice) {
            case 1:
                MtpOpenSession();
                break;
                
            case 2:
                MtpGetDeviceInfo();
                break;
                
            case 3:
                if (!g_sessionOpen) {
                    printf("Please open a session first.\n");
                    break;
                }
                MtpGetStorageIds(storageIds, 16, &storageCount);
                break;
                
            case 4:
                if (!g_sessionOpen) {
                    printf("Please open a session first.\n");
                    break;
                }
                printf("Enter Storage ID (hex, 0 for all): ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%lx", &storageId);
                if (storageId == 0) storageId = 0xFFFFFFFF;
                MtpListObjects(storageId);
                break;
                
            case 5:
                if (!g_sessionOpen) {
                    printf("Please open a session first.\n");
                    break;
                }
                printf("Enter Object Handle (hex): ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%lx", &objectHandle);
                MtpGetObjectInfo(objectHandle);
                break;
                
            case 6:
                if (!g_sessionOpen) {
                    printf("Please open a session first.\n");
                    break;
                }
                printf("Enter Object Handle (hex): ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%lx", &objectHandle);
                printf("Enter local filename to save: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\r\n")] = 0;  /* Remove newline */
                MtpDownloadFile(objectHandle, filename);
                break;
                
            case 7:
                if (!g_sessionOpen) {
                    printf("Please open a session first.\n");
                    break;
                }
                printf("Enter local filename to upload: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\r\n")] = 0;
                printf("Enter parent object handle (hex, 0 for root): ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%lx", &objectHandle);
                MtpUploadFile(filename, objectHandle);
                break;
                
            case 8:
                MtpCloseSession();
                break;
                
            case 9:
                if (g_sessionOpen) MtpCloseSession();
                printf("Goodbye!\n");
                return;
                
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

/* ============================================================================
 * Main Entry Point
 * ============================================================================ */

void PrintUsage(const char *progName)
{
    printf("MTP File Transfer Application for Windows 2000\n");
    printf("\nUsage:\n");
    printf("  %s                    - Interactive mode\n", progName);
    printf("  %s list               - List all objects\n", progName);
    printf("  %s info <handle>      - Get object info (hex handle)\n", progName);
    printf("  %s download <handle> <file> - Download object to file\n", progName);
    printf("  %s upload <file>      - Upload file to device root\n", progName);
    printf("\nOptions:\n");
    printf("  -d <device>           - Use custom device name\n");
    printf("                          Default: %s\n", DEVICE_NAME);
}

int main(int argc, char *argv[])
{
    const char *deviceName = DEVICE_NAME;
    int argStart = 1;
    
    printf("================================================\n");
    printf(" MTP File Transfer Application\n");
    printf(" Windows 2000 Compatible Version\n");
    printf("================================================\n\n");
    
    /* Parse options */
    while (argStart < argc && argv[argStart][0] == '-') {
        if (strcmp(argv[argStart], "-d") == 0 && argStart + 1 < argc) {
            deviceName = argv[argStart + 1];
            argStart += 2;
        } else if (strcmp(argv[argStart], "-h") == 0 || 
                   strcmp(argv[argStart], "--help") == 0) {
            PrintUsage(argv[0]);
            return 0;
        } else {
            printf("Unknown option: %s\n", argv[argStart]);
            PrintUsage(argv[0]);
            return 1;
        }
    }
    
    /* Open device */
    if (!OpenMtpDevice(deviceName)) {
        printf("\nMake sure:\n");
        printf("  1. MTP driver is installed\n");
        printf("  2. Device is connected\n");
        printf("  3. Device name is correct\n");
        return 1;
    }
    
    /* Handle command-line mode or interactive mode */
    if (argStart >= argc) {
        /* No command specified - interactive mode */
        InteractiveMode();
    } else {
        const char *cmd = argv[argStart];
        
        /* Open session for all commands */
        if (!MtpOpenSession()) {
            CloseMtpDevice();
            return 1;
        }
        
        if (strcmp(cmd, "list") == 0) {
            DWORD storageIds[16];
            DWORD count;
            DWORD i;
            
            MtpGetDeviceInfo();
            if (MtpGetStorageIds(storageIds, 16, &count)) {
                for (i = 0; i < count && i < 16; i++) {
                    MtpListObjects(storageIds[i]);
                }
            }
        }
        else if (strcmp(cmd, "info") == 0 && argStart + 1 < argc) {
            DWORD handle;
            sscanf(argv[argStart + 1], "%lx", &handle);
            MtpGetObjectInfo(handle);
        }
        else if (strcmp(cmd, "download") == 0 && argStart + 2 < argc) {
            DWORD handle;
            sscanf(argv[argStart + 1], "%lx", &handle);
            MtpDownloadFile(handle, argv[argStart + 2]);
        }
        else if (strcmp(cmd, "upload") == 0 && argStart + 1 < argc) {
            MtpUploadFile(argv[argStart + 1], 0);
        }
        else {
            printf("Unknown command or missing arguments: %s\n", cmd);
            PrintUsage(argv[0]);
        }
        
        MtpCloseSession();
    }
    
    CloseMtpDevice();
    return 0;
}
