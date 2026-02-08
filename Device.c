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

    status = MtpUsb_Create(device, NULL);
    if (!NT_SUCCESS(status)) {
        KdPrint(("MTP: MtpUsb_Create failed 0x%08x\n", status));
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

    // Create a symbolic link so a user-mode test app can open \\.\MtpSample
    {
        UNICODE_STRING symLink;
        RtlInitUnicodeString(&symLink, L"\\DosDevices\\MtpSample");
        status = WdfDeviceCreateSymbolicLink(device, &symLink);
        if (!NT_SUCCESS(status)) {
            KdPrint(("MTP: WdfDeviceCreateSymbolicLink failed 0x%08x\n", status));
            // not fatal - continue
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
        status = MtpGetDeviceInfo(Request);
        break;

    case IOCTL_MTP_LIST_OBJECTS:
        status = MtpListObjects(Request);
        break;

    case IOCTL_MTP_GET_OBJECT_PART:
        status = MtpGetObjectPart(Request);
        break;

    case IOCTL_MTP_SEND_OBJECT_PART:
        status = MtpSendObjectPart(Request);
        break;

    case IOCTL_MTP_SESSION_OPEN:
        status = MtpSessionOpen(Request);
        break;

    case IOCTL_MTP_SESSION_CLOSE:
        status = MtpSessionClose(Request);
        break;

    case IOCTL_MTP_OPERATION:
        status = MtpOperation(Request);
        break;

    default:
        status = STATUS_NOT_SUPPORTED;
        break;
    }

    if (!NT_SUCCESS(status)) {
        WdfRequestComplete(Request, status);
    }
}


NTSTATUS
MtpEvtDevicePrepareHardware(
    IN WDFDEVICE Device,
    IN WDFCMRESLIST ResourcesRaw,
    IN WDFCMRESLIST ResourcesTranslated
    )
{
    UNREFERENCED_PARAMETER(ResourcesRaw);
    UNREFERENCED_PARAMETER(ResourcesTranslated);

    // Device-level hardware initialization. For USB we select config in MtpUsb_Create.
    UNREFERENCED_PARAMETER(Device);
    KdPrint(("MTP: PrepareHardware called\n"));
    return STATUS_SUCCESS;
}

NTSTATUS
MtpEvtDeviceReleaseHardware(
    IN WDFDEVICE Device,
    IN WDFCMRESLIST ResourcesTranslated
    )
{
    PDEVICE_CONTEXT ctx;
    NTSTATUS status;
    
    UNREFERENCED_PARAMETER(ResourcesTranslated);

    ctx = DeviceGetContext(Device);
    
    // Mark USB as absent first to fail any pending operations
    if (ctx) {
        ctx->UsbPresent = FALSE;
        KdPrint(("MTP: Marked USB device as absent\n"));
    }

    // Stop USB readers
    status = MtpUsb_StopReaders(Device);
    if (!NT_SUCCESS(status)) {
        KdPrint(("MTP: MtpUsb_StopReaders returned 0x%08x\n", status));
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
