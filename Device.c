/*
 * Device.c - Device add and PnP callbacks
 */

#include <ntddk.h>

#if (_WIN32_WINNT == 0x0500)
// Only include compatibility layer for Windows 2000 DDK
#include "w2k_compat.h"
#endif

#include <wdf.h>
#include "Usb.h"
#include "Mtp.h"

NTSTATUS
MtpEvtDeviceAdd(
    IN WDFDRIVER       Driver,
    IN OUT PWDFDEVICE_INIT DeviceInit
    )
{
    NTSTATUS status;
    WDFDEVICE device;
    WDF_OBJECT_ATTRIBUTES attributes;
    WDF_PNPPOWER_EVENT_CALLBACKS pnpPowerCallbacks;

    UNREFERENCED_PARAMETER(Driver);

    WDF_PNPPOWER_EVENT_CALLBACKS_INIT(&pnpPowerCallbacks);
    pnpPowerCallbacks.EvtDevicePrepareHardware = MtpEvtDevicePrepareHardware;
    pnpPowerCallbacks.EvtDeviceReleaseHardware = MtpEvtDeviceReleaseHardware;
    pnpPowerCallbacks.EvtDeviceSurpriseRemoval = MtpEvtDeviceSurpriseRemoval;
    pnpPowerCallbacks.EvtDeviceD0Entry = MtpEvtDeviceD0Entry;
    pnpPowerCallbacks.EvtDeviceD0Exit = MtpEvtDeviceD0Exit;

    WdfDeviceInitSetPnpPowerEventCallbacks(DeviceInit, &pnpPowerCallbacks);

    // Use the driver-defined device context so USB pipes and objects are stored per-device
    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&attributes, DEVICE_CONTEXT);

    status = WdfDeviceCreate(&DeviceInit, &attributes, &device);
    if (!NT_SUCCESS(status)) {
        KdPrint(("MTP: WdfDeviceCreate failed 0x%08x\n", status));
        return status;
    }

    // Create I/O queue for device IOCTLs (user-mode test app will use these IOCTLs to exercise MTP)
    {
        WDF_IO_QUEUE_CONFIG ioConfig;
        WDFQUEUE queue;
        WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE(&ioConfig, WdfIoQueueDispatchSequential);
        ioConfig.EvtIoDeviceControl = MtpEvtIoDeviceControl;

        status = WdfIoQueueCreate(device, &ioConfig, WDF_NO_OBJECT_ATTRIBUTES, &queue);
        if (!NT_SUCCESS(status)) {
            KdPrint(("MTP: WdfIoQueueCreate failed 0x%08x\n", status));
            return status;
        }
    }

    // Initialize MTP internals (in-memory store etc.)
    status = MtpInitializeDevice(device);
    if (!NT_SUCCESS(status)) {
        KdPrint(("MTP: MtpInitializeDevice failed 0x%08x\n", status));
        return status;
    }

    // Create symbolic links so user-mode apps can open \\.\MtpDevice or \\.\MtpSample
    {
        UNICODE_STRING symLink;
        RtlInitUnicodeString(&symLink, L"\\DosDevices\\MtpDevice");
        status = WdfDeviceCreateSymbolicLink(device, &symLink);
        if (!NT_SUCCESS(status)) {
            KdPrint(("MTP: WdfDeviceCreateSymbolicLink (MtpDevice) failed 0x%08x\n", status));
        }

        RtlInitUnicodeString(&symLink, L"\\DosDevices\\MtpSample");
        status = WdfDeviceCreateSymbolicLink(device, &symLink);
        if (!NT_SUCCESS(status)) {
            KdPrint(("MTP: WdfDeviceCreateSymbolicLink (MtpSample) failed 0x%08x\n", status));
        }
    }

    KdPrint(("MTP: DeviceAdd completed\n"));
    return STATUS_SUCCESS;
}

VOID
MtpEvtIoDeviceControl(
    IN WDFQUEUE Queue,
    IN WDFREQUEST Request,
    IN size_t OutputBufferLength,
    IN size_t InputBufferLength,
    IN ULONG IoControlCode
    )
{
    NTSTATUS status;
    
    UNREFERENCED_PARAMETER(Queue);
    UNREFERENCED_PARAMETER(OutputBufferLength);
    UNREFERENCED_PARAMETER(InputBufferLength);

    status = STATUS_INVALID_DEVICE_REQUEST;

    switch (IoControlCode) {
    case IOCTL_MTP_GET_DEVICE_INFO:
        MtpGetDeviceInfo(Request);
        break;

    case IOCTL_MTP_LIST_OBJECTS:
        MtpListObjects(Request);
        break;

    case IOCTL_MTP_GET_OBJECT_PART:
        MtpGetObjectPart(Request);
        break;

    case IOCTL_MTP_SEND_OBJECT_PART:
        MtpSendObjectPart(Request);
        break;

    case IOCTL_MTP_SESSION_OPEN:
        MtpSessionOpen(Request);
        break;

    case IOCTL_MTP_SESSION_CLOSE:
        MtpSessionClose(Request);
        break;

    case IOCTL_MTP_OPERATION:
        MtpOperation(Request);
        break;

    case IOCTL_MTP_GET_TRANSFER_SPEED:
        MtpGetTransferSpeed(Request);
        break;

    case IOCTL_MTP_RESET_PIPES: {
        /* User-mode detected consecutive timeout failures; reset both USB
         * bulk pipes to recover from desynchronized pipe state. */
        WDFDEVICE device = WdfRequestGetDevice(Request);
        PDEVICE_CONTEXT ctx = DeviceGetContext(device);
        if (ctx && ctx->UsbPresent) {
            if (ctx->BulkInPipe) MtpUsb_ResetPipe(device, ctx->BulkInPipe);
            if (ctx->BulkOutPipe) MtpUsb_ResetPipe(device, ctx->BulkOutPipe);
            KdPrint(("MTP: Pipes reset via IOCTL request\n"));
        }
        WdfRequestComplete(Request, STATUS_SUCCESS);
        break;
    }

    default:
        WdfRequestComplete(Request, STATUS_NOT_SUPPORTED);
        break;
    }
}

NTSTATUS
MtpGetTransferSpeed(WDFREQUEST Request)
{
    WDFDEVICE device;
    PDEVICE_CONTEXT ctx;
    MTP_SPEED_INFO speed;
    PVOID outBuf;
    size_t outCap;
    NTSTATUS status;

    device = WdfRequestGetDevice(Request);
    ctx = DeviceGetContext(device);
    if (!ctx || !ctx->UsbPresent) {
        WdfRequestComplete(Request, STATUS_INVALID_DEVICE_STATE);
        return STATUS_INVALID_DEVICE_STATE;
    }

    RtlZeroMemory(&speed, sizeof(speed));
    speed.MaxPacketSize = ctx->MaxPacketSize ? ctx->MaxPacketSize : 64;

    if (speed.MaxPacketSize <= 64) {
        /* USB 1.1 Full Speed (UHCI/OHCI) */
        speed.ControllerType = 1;
        speed.OptimalChunkSize = 16384;   /* 16 KB: safe for UHCI frame schedules */
    } else if (speed.MaxPacketSize <= 512) {
        /* USB 2.0 High Speed (EHCI) */
        speed.ControllerType = 2;
        speed.OptimalChunkSize = 65536;   /* 64 KB: optimal for EHCI qTD queues */
    } else {
        /* USB 3.0 / USB 4 SuperSpeed (xHCI) */
        speed.ControllerType = 3;
        speed.OptimalChunkSize = 262144;  /* 256 KB: high throughput burst TRBs */
    }

    status = WdfRequestRetrieveOutputBuffer(Request, sizeof(speed), &outBuf, &outCap);
    if (!NT_SUCCESS(status)) {
        WdfRequestComplete(Request, status);
        return status;
    }

    RtlCopyMemory(outBuf, &speed, sizeof(speed));
    WdfRequestCompleteWithInformation(Request, STATUS_SUCCESS, sizeof(speed));
    return STATUS_SUCCESS;
}

/*
 * ============================================================================
 * Shell Integration: Dynamic "Portable Device" My Computer NameSpace Icon
 *
 * Windows 2000 Explorer displays shell namespace extensions listed under:
 *   HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\MyComputer\NameSpace
 *
 * The icon is registered dynamically when the driver prepares hardware
 * (device plugged in / loaded) and deleted when the driver releases hardware
 * or encounters surprise removal (device unplugged / unloaded).
 * ============================================================================
 */

#define MTP_GUID_STR L"{E0C30E66-2679-4594-817D-38F75FEF30A1}"
#define MTP_DEVICE_NAME L"Portable Device (Android Smartphone)"
#define MTP_INFOTIP L"Device: Portable Android Device\nFile System: MTP (Media Transfer Protocol)\nStatus: Ready for connection"

static NTSTATUS
MtpSetRegistryStringValue(
    IN PCWSTR KeyPath,
    IN PCWSTR ValueName OPTIONAL,
    IN PCWSTR ValueData,
    IN ULONG ValueType
    )
{
    NTSTATUS status;
    OBJECT_ATTRIBUTES objAttr;
    UNICODE_STRING keyStr;
    UNICODE_STRING valStr;
    UNICODE_STRING dataStr;
    HANDLE hKey = NULL;
    ULONG disposition = 0;

    PAGED_CODE();

    RtlInitUnicodeString(&keyStr, KeyPath);
    InitializeObjectAttributes(&objAttr, &keyStr, OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE, NULL, NULL);

    status = ZwCreateKey(&hKey,
                         KEY_ALL_ACCESS,
                         &objAttr,
                         0,
                         NULL,
                         REG_OPTION_NON_VOLATILE,
                         &disposition);
    if (!NT_SUCCESS(status)) {
        KdPrint(("MTP: ZwCreateKey failed 0x%08x for %ws\n", status, KeyPath));
        return status;
    }

    if (ValueName) {
        RtlInitUnicodeString(&valStr, ValueName);
    } else {
        RtlInitUnicodeString(&valStr, L"");
    }

    RtlInitUnicodeString(&dataStr, ValueData);
    status = ZwSetValueKey(hKey,
                           &valStr,
                           0,
                           ValueType,
                           dataStr.Buffer,
                           dataStr.Length + sizeof(WCHAR));
    if (!NT_SUCCESS(status)) {
        KdPrint(("MTP: ZwSetValueKey failed 0x%08x for %ws\n", status, KeyPath));
    }

    ZwClose(hKey);
    return status;
}

static NTSTATUS
MtpSetRegistryDwordValue(
    IN PCWSTR KeyPath,
    IN PCWSTR ValueName,
    IN ULONG ValueData
    )
{
    NTSTATUS status;
    OBJECT_ATTRIBUTES objAttr;
    UNICODE_STRING keyStr;
    UNICODE_STRING valStr;
    HANDLE hKey = NULL;
    ULONG disposition = 0;

    PAGED_CODE();

    RtlInitUnicodeString(&keyStr, KeyPath);
    InitializeObjectAttributes(&objAttr, &keyStr, OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE, NULL, NULL);

    status = ZwCreateKey(&hKey,
                         KEY_ALL_ACCESS,
                         &objAttr,
                         0,
                         NULL,
                         REG_OPTION_NON_VOLATILE,
                         &disposition);
    if (!NT_SUCCESS(status)) {
        return status;
    }

    RtlInitUnicodeString(&valStr, ValueName);
    status = ZwSetValueKey(hKey,
                           &valStr,
                           0,
                           REG_DWORD,
                           &ValueData,
                           sizeof(ULONG));

    ZwClose(hKey);
    return status;
}

NTSTATUS
MtpRegisterMyComputerIcon(VOID)
{
    NTSTATUS status;

    PAGED_CODE();
    KdPrint(("MTP: Registering Portable Device icon in My Computer...\n"));

    /* 1. Base CLSID definition in HKLM\SOFTWARE\Classes\CLSID\{...} */
    MtpSetRegistryStringValue(
        L"\\Registry\\Machine\\SOFTWARE\\Classes\\CLSID\\" MTP_GUID_STR,
        NULL,
        MTP_DEVICE_NAME,
        REG_SZ);

    MtpSetRegistryStringValue(
        L"\\Registry\\Machine\\SOFTWARE\\Classes\\CLSID\\" MTP_GUID_STR,
        L"LocalizedString",
        MTP_DEVICE_NAME,
        REG_SZ);

    MtpSetRegistryStringValue(
        L"\\Registry\\Machine\\SOFTWARE\\Classes\\CLSID\\" MTP_GUID_STR,
        L"InfoTip",
        MTP_INFOTIP,
        REG_SZ);

    /* 2. DefaultIcon (Windows 2000 digital camera icon from sticpl.cpl) */
    MtpSetRegistryStringValue(
        L"\\Registry\\Machine\\SOFTWARE\\Classes\\CLSID\\" MTP_GUID_STR L"\\DefaultIcon",
        NULL,
        L"%SystemRoot%\\System32\\sticpl.cpl,1",
        REG_EXPAND_SZ);

    /* 3. ShellFolder attributes */
    MtpSetRegistryDwordValue(
        L"\\Registry\\Machine\\SOFTWARE\\Classes\\CLSID\\" MTP_GUID_STR L"\\ShellFolder",
        L"Attributes",
        0);

    /* 4. Shell verbs */
    MtpSetRegistryStringValue(
        L"\\Registry\\Machine\\SOFTWARE\\Classes\\CLSID\\" MTP_GUID_STR L"\\Shell",
        NULL,
        L"Open",
        REG_SZ);

    MtpSetRegistryStringValue(
        L"\\Registry\\Machine\\SOFTWARE\\Classes\\CLSID\\" MTP_GUID_STR L"\\Shell\\Open",
        NULL,
        L"&Open",
        REG_SZ);

    /* 5. Shell Open command: launches mtp_gui.exe */
    MtpSetRegistryStringValue(
        L"\\Registry\\Machine\\SOFTWARE\\Classes\\CLSID\\" MTP_GUID_STR L"\\Shell\\Open\\Command",
        NULL,
        L"\"%SystemRoot%\\System32\\mtp_gui.exe\"",
        REG_EXPAND_SZ);

    /* 6. NameSpace extension under My Computer - makes the icon appear! */
    status = MtpSetRegistryStringValue(
        L"\\Registry\\Machine\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\" MTP_GUID_STR,
        NULL,
        MTP_DEVICE_NAME,
        REG_SZ);

    if (NT_SUCCESS(status)) {
        KdPrint(("MTP: Successfully registered Portable Device in My Computer NameSpace\n"));
    } else {
        KdPrint(("MTP: Failed to register NameSpace extension: 0x%08x\n", status));
    }

    return status;
}

NTSTATUS
MtpUnregisterMyComputerIcon(VOID)
{
    NTSTATUS status;
    OBJECT_ATTRIBUTES objAttr;
    UNICODE_STRING keyStr;
    HANDLE hKey = NULL;

    PAGED_CODE();
    KdPrint(("MTP: Unregistering Portable Device icon from My Computer...\n"));

    /*
     * Only delete the NameSpace key under MyComputer!
     * Keep the CLSID definition intact so COM/Shell class registration
     * remains valid for future device insertions.
     */
    RtlInitUnicodeString(&keyStr,
        L"\\Registry\\Machine\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace\\" MTP_GUID_STR);
    InitializeObjectAttributes(&objAttr, &keyStr, OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE, NULL, NULL);

    status = ZwOpenKey(&hKey, DELETE, &objAttr);
    if (NT_SUCCESS(status)) {
        status = ZwDeleteKey(hKey);
        ZwClose(hKey);
        KdPrint(("MTP: Successfully removed Portable Device NameSpace key (0x%08x)\n", status));
    } else {
        KdPrint(("MTP: NameSpace key not present or ZwOpenKey returned 0x%08x\n", status));
    }

    return status;
}

NTSTATUS
MtpEvtDevicePrepareHardware(
    IN WDFDEVICE Device,
    IN WDFCMRESLIST ResourcesRaw,
    IN WDFCMRESLIST ResourcesTranslated
    )
{
    NTSTATUS status;

    UNREFERENCED_PARAMETER(ResourcesRaw);
    UNREFERENCED_PARAMETER(ResourcesTranslated);

    KdPrint(("MTP: PrepareHardware called\n"));

    status = MtpUsb_PrepareHardware(Device);
    if (!NT_SUCCESS(status)) {
        KdPrint(("MTP: MtpUsb_PrepareHardware failed 0x%08x\n", status));
        return status;
    }

    /*
     * Hardware is prepared and MTP device is ready.
     * Register "Portable Device" icon in My Computer NameSpace so it appears immediately!
     */
    MtpRegisterMyComputerIcon();

    return STATUS_SUCCESS;
}

NTSTATUS
MtpEvtDeviceReleaseHardware(
    IN WDFDEVICE Device,
    IN WDFCMRESLIST ResourcesTranslated
    )
{
    NTSTATUS status;
    
    UNREFERENCED_PARAMETER(ResourcesTranslated);

    /*
     * Hardware is released (device unplugged or driver stopping).
     * Remove "Portable Device" icon from My Computer NameSpace.
     */
    MtpUnregisterMyComputerIcon();

    // Stop USB readers
    status = MtpUsb_StopReaders(Device);
    if (!NT_SUCCESS(status)) {
        KdPrint(("MTP: MtpUsb_StopReaders returned 0x%08x\n", status));
    }

    // Release USB hardware resources
    status = MtpUsb_ReleaseHardware(Device);
    if (!NT_SUCCESS(status)) {
        KdPrint(("MTP: MtpUsb_ReleaseHardware returned 0x%08x\n", status));
    }

    // Cleanup MTP in-memory objects and responses
    status = MtpCleanupDevice(Device);
    if (!NT_SUCCESS(status)) {
        KdPrint(("MTP: MtpCleanupDevice returned 0x%08x\n", status));
    }

    KdPrint(("MTP: ReleaseHardware completed\n"));
    return STATUS_SUCCESS;
}

NTSTATUS
MtpEvtDeviceD0Entry(
    IN WDFDEVICE Device,
    IN WDF_POWER_DEVICE_STATE PreviousState
    )
{
    NTSTATUS status;
    
    UNREFERENCED_PARAMETER(PreviousState);

    status = MtpUsb_StartReaders(Device);
    if (!NT_SUCCESS(status)) {
        KdPrint(("MTP: MtpUsb_StartReaders failed 0x%08x\n", status));
        return status;
    }

    KdPrint(("MTP: D0Entry completed\n"));
    return STATUS_SUCCESS;
}


NTSTATUS
MtpEvtDeviceD0Exit(
    IN WDFDEVICE Device,
    IN WDF_POWER_DEVICE_STATE TargetState
    )
{
    PDEVICE_CONTEXT ctx;
    
    UNREFERENCED_PARAMETER(TargetState);

    ctx = DeviceGetContext(Device);
    if (ctx && ctx->BulkInPipe) {
        // Use a conservative stop flag (0) for broader KMDF header compatibility
        WdfIoTargetStop(WdfUsbTargetPipeGetIoTarget(ctx->BulkInPipe), 0);
    }

    KdPrint(("MTP: D0Exit completed\n"));
    return STATUS_SUCCESS;
}

VOID
MtpEvtDeviceSurpriseRemoval(
    IN WDFDEVICE Device
    )
{
    PDEVICE_CONTEXT ctx;
    KdPrint(("MTP: SurpriseRemoval called\n"));

    /*
     * Immediate surprise removal: remove icon from My Computer right away.
     */
    MtpUnregisterMyComputerIcon();

    ctx = DeviceGetContext(Device);
    if (ctx) {
        ctx->UsbPresent = FALSE;
    }
    MtpResetStreaming();
}

