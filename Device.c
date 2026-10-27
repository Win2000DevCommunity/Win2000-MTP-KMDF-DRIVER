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
    ctx = DeviceGetContext(Device);
    if (ctx) {
        ctx->UsbPresent = FALSE;
    }
    MtpResetStreaming();
}

