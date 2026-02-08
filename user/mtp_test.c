/*
 * mtp_test.c - simple user-mode test for the MTP driver.
 *
 * NOTE: This test is intended to be built against the Windows 2000 SDK
 * located in the workspace at "2000 sdk". Use the provided
 * build_test.bat which sets /I to the 2000 SDK Include directory so
 * that no newer Windows headers are used.
 */

#include <windows.h>
#include <winioctl.h>  /* IOCTL helpers; provided by the 2000 SDK Include */
#include <stdio.h>
#include <stdlib.h>

#ifndef IOCTL_MTP_GET_DEVICE_INFO
#define IOCTL_MTP_GET_DEVICE_INFO        CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_READ_DATA)
#define IOCTL_MTP_LIST_OBJECTS           CTL_CODE(FILE_DEVICE_UNKNOWN, 0x801, METHOD_BUFFERED, FILE_READ_DATA)
#define IOCTL_MTP_GET_OBJECT_PART        CTL_CODE(FILE_DEVICE_UNKNOWN, 0x802, METHOD_BUFFERED, FILE_READ_DATA)
#define IOCTL_MTP_SEND_OBJECT_PART       CTL_CODE(FILE_DEVICE_UNKNOWN, 0x803, METHOD_BUFFERED, FILE_WRITE_DATA)
#endif

int main()
{
    HANDLE h = CreateFileA("\\\\.\\MtpSample", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (h == INVALID_HANDLE_VALUE) {
        printf("Failed to open device: %u\n", GetLastError());
        return 1;
    }

    printf("Opened device. Getting device info...\n");
    BYTE buf[512]; DWORD returned;
    if (DeviceIoControl(h, IOCTL_MTP_GET_DEVICE_INFO, NULL, 0, buf, sizeof(buf), &returned, NULL)) {
        printf("DeviceInfo (%u bytes): %s\n", returned, (char*)buf);
    } else {
        printf("GetDeviceInfo failed: %u\n", GetLastError());
    }

    // Prepare a large payload and send in chunks
    const size_t totalSize = 64 * 1024; // 64KB
    const size_t chunk = 4096;
    BYTE *payload = malloc(totalSize);
    for (size_t i = 0; i < totalSize; ++i) payload[i] = (BYTE)(i & 0xFF);

    DWORD objectId = 0;
    // Send chunks: first chunk with Id=0 asks driver to create an object and returns assigned Id
    size_t sent = 0;
    while (sent < totalSize) {
        DWORD idField = objectId; // 0 for first
        DWORD offset = (DWORD)sent;
        size_t thisLen = min(chunk, totalSize - sent);

        size_t inSize = sizeof(idField) + sizeof(offset) + thisLen;
        BYTE *inBuf = malloc(inSize);
        memcpy(inBuf, &idField, sizeof(idField));
        memcpy(inBuf + sizeof(idField), &offset, sizeof(offset));
        memcpy(inBuf + sizeof(idField) + sizeof(offset), payload + sent, thisLen);

        BYTE outBuf[8]; DWORD outLen = 0;
        BOOL ok = DeviceIoControl(h, IOCTL_MTP_SEND_OBJECT_PART, inBuf, (DWORD)inSize, outBuf, sizeof(outBuf), &outLen, NULL);
        if (!ok) {
            printf("Send chunk failed at offset %u: %u\n", offset, GetLastError());
            free(inBuf); break;
        }

        if (objectId == 0 && outLen >= sizeof(DWORD)) {
            objectId = *((DWORD*)outBuf);
            printf("Created object Id: %u\n", objectId);
        }

        sent += thisLen;
        free(inBuf);
    }

    if (objectId != 0) {
        printf("Upload complete, Id=%u, size=%u. Now downloading in chunks...\n", objectId, (unsigned)totalSize);
        size_t received = 0;
        while (received < totalSize) {
            struct { DWORD Id; DWORD Offset; DWORD Length; } req;
            req.Id = objectId; req.Offset = (DWORD)received; req.Length = (DWORD)min(chunk, totalSize - received);
            BYTE *out = malloc(req.Length);
            DWORD got = 0;
            BOOL ok = DeviceIoControl(h, IOCTL_MTP_GET_OBJECT_PART, &req, sizeof(req), out, req.Length, &got, NULL);
            if (!ok) { printf("GetObjectPart failed at %u: %u\n", req.Offset, GetLastError()); free(out); break; }

            // simple verification
            for (DWORD i = 0; i < got; ++i) {
                if (out[i] != (BYTE)((received + i) & 0xFF)) { printf("Data mismatch at %u\n", (unsigned)(received + i)); break; }
            }

            free(out);
            received += got;
            printf("Received %u/%u bytes\n", (unsigned)received, (unsigned)totalSize);
        }
        printf("Download complete\n");
    }

    free(payload);
    CloseHandle(h);
    return 0;
}
