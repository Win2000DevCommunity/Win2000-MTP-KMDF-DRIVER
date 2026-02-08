/*
 * mtp_test.c - User-mode test application for MTP KMDF driver
 * Windows 2000 compatible
 */

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

/* IOCTL definitions - must match Mtp.h */
#define IOCTL_MTP_GET_DEVICE_INFO    CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_READ_DATA)
#define IOCTL_MTP_LIST_OBJECTS       CTL_CODE(FILE_DEVICE_UNKNOWN, 0x801, METHOD_BUFFERED, FILE_READ_DATA)
#define IOCTL_MTP_GET_OBJECT_PART    CTL_CODE(FILE_DEVICE_UNKNOWN, 0x802, METHOD_BUFFERED, FILE_READ_DATA)
#define IOCTL_MTP_SEND_OBJECT_PART   CTL_CODE(FILE_DEVICE_UNKNOWN, 0x803, METHOD_BUFFERED, FILE_WRITE_DATA)
#define IOCTL_MTP_SESSION_OPEN       CTL_CODE(FILE_DEVICE_UNKNOWN, 0x810, METHOD_BUFFERED, FILE_READ_DATA)
#define IOCTL_MTP_SESSION_CLOSE      CTL_CODE(FILE_DEVICE_UNKNOWN, 0x811, METHOD_BUFFERED, FILE_READ_DATA)
#define IOCTL_MTP_OPERATION          CTL_CODE(FILE_DEVICE_UNKNOWN, 0x812, METHOD_BUFFERED, FILE_READ_DATA)

#define DEVICE_NAME "\\\\.\\MtpDevice"

void PrintBuffer(LPVOID buffer, DWORD size)
{
    DWORD i;
    unsigned char *p = (unsigned char*)buffer;
    
    printf("Data (%u bytes):\n", size);
    for (i = 0; i < size && i < 256; i++) {
        printf("%02X ", p[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }
    if (size > 256) printf("... (truncated)\n");
    printf("\n");
}

BOOL TestGetDeviceInfo(HANDLE hDevice)
{
    BYTE buffer[4096];
    DWORD bytesReturned;
    BOOL result;
    
    printf("\n=== Test 1: Get Device Info ===\n");
    
    ZeroMemory(buffer, sizeof(buffer));
    
    result = DeviceIoControl(
        hDevice,
        IOCTL_MTP_GET_DEVICE_INFO,
        NULL,
        0,
        buffer,
        sizeof(buffer),
        &bytesReturned,
        NULL
    );
    
    if (result) {
        printf("Success! Received %u bytes\n", bytesReturned);
        PrintBuffer(buffer, bytesReturned);
        return TRUE;
    } else {
        printf("Failed! Error: %u\n", GetLastError());
        return FALSE;
    }
}

BOOL TestSessionOpen(HANDLE hDevice)
{
    DWORD sessionId;
    DWORD bytesReturned;
    BOOL result;
    
    printf("\n=== Test 2: Open MTP Session ===\n");
    
    sessionId = 0;
    
    result = DeviceIoControl(
        hDevice,
        IOCTL_MTP_SESSION_OPEN,
        NULL,
        0,
        &sessionId,
        sizeof(sessionId),
        &bytesReturned,
        NULL
    );
    
    if (result) {
        printf("Success! Session ID: 0x%08X\n", sessionId);
        return TRUE;
    } else {
        printf("Failed! Error: %u\n", GetLastError());
        return FALSE;
    }
}

BOOL TestListObjects(HANDLE hDevice)
{
    BYTE buffer[8192];
    DWORD bytesReturned;
    BOOL result;
    
    printf("\n=== Test 3: List Objects ===\n");
    
    ZeroMemory(buffer, sizeof(buffer));
    
    result = DeviceIoControl(
        hDevice,
        IOCTL_MTP_LIST_OBJECTS,
        NULL,
        0,
        buffer,
        sizeof(buffer),
        &bytesReturned,
        NULL
    );
    
    if (result) {
        printf("Success! Received %u bytes\n", bytesReturned);
        PrintBuffer(buffer, bytesReturned);
        return TRUE;
    } else {
        printf("Failed! Error: %u\n", GetLastError());
        return FALSE;
    }
}

BOOL TestSessionClose(HANDLE hDevice)
{
    DWORD bytesReturned;
    BOOL result;
    
    printf("\n=== Test 4: Close MTP Session ===\n");
    
    result = DeviceIoControl(
        hDevice,
        IOCTL_MTP_SESSION_CLOSE,
        NULL,
        0,
        NULL,
        0,
        &bytesReturned,
        NULL
    );
    
    if (result) {
        printf("Success! Session closed\n");
        return TRUE;
    } else {
        printf("Failed! Error: %u\n", GetLastError());
        return FALSE;
    }
}

int main(int argc, char* argv[])
{
    HANDLE hDevice;
    char *deviceName;
    
    printf("========================================\n");
    printf(" MTP KMDF Driver Test Application\n");
    printf(" Windows 2000 Compatible\n");
    printf("========================================\n");
    
    /* Allow custom device name */
    deviceName = (argc > 1) ? argv[1] : DEVICE_NAME;
    
    printf("\nOpening device: %s\n", deviceName);
    
    hDevice = CreateFile(
        deviceName,
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );
    
    if (hDevice == INVALID_HANDLE_VALUE) {
        printf("ERROR: Failed to open device!\n");
        printf("Error code: %u\n", GetLastError());
        printf("\nPossible reasons:\n");
        printf("  - Driver not installed\n");
        printf("  - Wrong device name\n");
        printf("  - Device not connected\n");
        printf("\nUsage: %s [device_name]\n", argv[0]);
        printf("Example: %s \\\\.\\MtpDevice\n", argv[0]);
        return 1;
    }
    
    printf("Device opened successfully!\n");
    
    /* Run tests */
    TestGetDeviceInfo(hDevice);
    
    TestSessionOpen(hDevice);
    
    TestListObjects(hDevice);
    
    TestSessionClose(hDevice);
    
    /* Cleanup */
    CloseHandle(hDevice);
    
    printf("\n========================================\n");
    printf(" All tests completed!\n");
    printf("========================================\n");
    
    return 0;
}
