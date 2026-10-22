/*
 * Usb.c - KMDF USB helper functions (simplified)
 */

#include <ntddk.h>

#if (_WIN32_WINNT == 0x0500)
// Only include compatibility layer for Windows 2000 DDK
#include "w2k_compat.h"
#endif

#include <wdf.h>
#include "Usb.h"


NTSTATUS
MtpUsb_PrepareHardware(WDFDEVICE Device)
{
    NTSTATUS status;
    WDFUSBDEVICE usbDevice;
    PDEVICE_CONTEXT ctx;
    WDFUSBINTERFACE usbInterface;
    UCHAR numEndpoints;
    UCHAR i;
    WDF_USB_PIPE_INFORMATION pi;
    WDFUSBPIPE pipe;
    WDF_USB_DEVICE_SELECT_CONFIG_PARAMS configParams;

    ctx = DeviceGetContext(Device);
    if (!ctx) {
        return STATUS_INVALID_PARAMETER;
    }

    // Default configuration
    ctx->UsbConfig.ReadBufferSize = 16384;
    ctx->UsbConfig.NumReaders = 2;
    ctx->UsbConfig.TransferTimeoutMs = 5000;
    ctx->UsbConfig.RetryCount = 3;

    // Create USB device object if not already created
    if (ctx->UsbDevice == NULL) {
        status = WdfUsbTargetDeviceCreate(Device, WDF_NO_OBJECT_ATTRIBUTES, &usbDevice);
        if (!NT_SUCCESS(status)) {
            KdPrint(("MTP: WdfUsbTargetDeviceCreate failed 0x%08x\n", status));
            return status;
        }
        ctx->UsbDevice = usbDevice;
    }

    // Select single interface configuration
    WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_SINGLE_INTERFACE(&configParams);
    status = WdfUsbTargetDeviceSelectConfig(ctx->UsbDevice, WDF_NO_OBJECT_ATTRIBUTES, &configParams);
    if (!NT_SUCCESS(status)) {
        KdPrint(("MTP: WdfUsbTargetDeviceSelectConfig failed 0x%08x\n", status));
        return status;
    }

    usbInterface = configParams.Types.SingleInterface.ConfiguredUsbInterface;
    if (usbInterface == NULL) {
        KdPrint(("MTP: No configured USB interface found\n"));
        return STATUS_DEVICE_CONFIGURATION_ERROR;
    }

    ctx->UsbInterface = usbInterface;
    numEndpoints = WdfUsbInterfaceGetNumEndpoints(usbInterface, 0);
    KdPrint(("MTP: Configured interface has %u endpoints\n", (ULONG)numEndpoints));

    // Find bulk pipes
    for (i = 0; i < numEndpoints; i++) {
        WDF_USB_PIPE_INFORMATION_INIT(&pi);
        pipe = WdfUsbInterfaceGetConfiguredPipe(usbInterface, i, &pi);
        if (pipe == NULL) {
            continue;
        }

        if (pi.PipeType == WdfUsbPipeTypeBulk) {
            if (WdfUsbTargetPipeIsInEndpoint(pipe)) {
                ctx->BulkInPipe = pipe;
                ctx->MaxPacketSize = pi.MaximumPacketSize;
                KdPrint(("MTP: Bulk IN pipe configured, MaxPacket=%u\n", ctx->MaxPacketSize));
            } else {
                ctx->BulkOutPipe = pipe;
                KdPrint(("MTP: Bulk OUT pipe configured\n"));
            }
        }
    }

    ctx->UsbPresent = TRUE;
    KdPrint(("MTP: USB hardware prepared successfully\n"));
    return STATUS_SUCCESS;
}

NTSTATUS
MtpUsb_ReleaseHardware(WDFDEVICE Device)
{
    PDEVICE_CONTEXT ctx;

    ctx = DeviceGetContext(Device);
    if (ctx) {
        ctx->UsbPresent = FALSE;
        ctx->BulkInPipe = NULL;
        ctx->BulkOutPipe = NULL;
        ctx->UsbInterface = NULL;
        ctx->UsbDevice = NULL;
    }

    KdPrint(("MTP: USB hardware released\n"));
    return STATUS_SUCCESS;
}

NTSTATUS
MtpUsb_Create(WDFDEVICE Device, PMTP_USB_CONFIG Config)
{
    PDEVICE_CONTEXT ctx;

    ctx = DeviceGetContext(Device);
    if (ctx && Config) {
        ctx->UsbConfig = *Config;
    }
    return STATUS_SUCCESS;
}

NTSTATUS
MtpUsb_WriteBulk(
    WDFDEVICE Device,
    WDFUSBPIPE Pipe,
    PVOID Buffer,
    size_t Length
    )
{
    PDEVICE_CONTEXT ctx;
    NTSTATUS status;
    WDF_MEMORY_DESCRIPTOR memDesc;
    ULONG bytesWritten = 0;
    WDF_REQUEST_SEND_OPTIONS sendOptions;
    ULONG timeout;

    if (!Buffer || Length == 0 || !Device || !Pipe) {
        return STATUS_INVALID_PARAMETER;
    }

    ctx = DeviceGetContext(Device);
    if (!ctx || !ctx->UsbPresent) {
        KdPrint(("MTP: USB device not present, aborting write\n"));
        return STATUS_INVALID_DEVICE_STATE;
    }

    timeout = ctx->UsbConfig.TransferTimeoutMs ? ctx->UsbConfig.TransferTimeoutMs : 5000;

    WDF_MEMORY_DESCRIPTOR_INIT_BUFFER(&memDesc, Buffer, (ULONG)Length);

    WDF_REQUEST_SEND_OPTIONS_INIT(&sendOptions, 0);
    WDF_REQUEST_SEND_OPTIONS_SET_TIMEOUT(&sendOptions, WDF_REL_TIMEOUT_IN_MS(timeout));

    status = WdfUsbTargetPipeWriteSynchronously(
        Pipe,
        NULL,
        &sendOptions,
        &memDesc,
        &bytesWritten
    );

    if (!NT_SUCCESS(status)) {
        KdPrint(("MTP: WdfUsbTargetPipeWriteSynchronously failed 0x%08x\n", status));
    }

    return status;
}

NTSTATUS
MtpUsb_ReadBulk(
    IN WDFDEVICE Device,
    IN WDFUSBPIPE Pipe,
    IN PVOID Buffer,
    IN size_t BufferLength,
    OUT PULONG BytesRead
    )
{
    PDEVICE_CONTEXT ctx;
    NTSTATUS status;
    WDF_MEMORY_DESCRIPTOR memDesc;
    ULONG bytesTransferred;
    WDF_REQUEST_SEND_OPTIONS sendOptions;
    ULONG timeout;

    bytesTransferred = 0;
    if (BytesRead) *BytesRead = 0;
    if (!Buffer || BufferLength == 0 || !Device || !Pipe) {
        return STATUS_INVALID_PARAMETER;
    }

    ctx = DeviceGetContext(Device);
    if (!ctx || !ctx->UsbPresent) {
        KdPrint(("MTP: USB device not present, aborting read\n"));
        return STATUS_INVALID_DEVICE_STATE;
    }

    timeout = ctx->UsbConfig.TransferTimeoutMs ? ctx->UsbConfig.TransferTimeoutMs : 5000;

    WDF_MEMORY_DESCRIPTOR_INIT_BUFFER(&memDesc, Buffer, (ULONG)BufferLength);

    WDF_REQUEST_SEND_OPTIONS_INIT(&sendOptions, 0);
    WDF_REQUEST_SEND_OPTIONS_SET_TIMEOUT(&sendOptions, WDF_REL_TIMEOUT_IN_MS(timeout));

    status = WdfUsbTargetPipeReadSynchronously(
        Pipe,
        NULL,
        &sendOptions,
        &memDesc,
        &bytesTransferred
    );

    if (!NT_SUCCESS(status)) {
        KdPrint(("MTP: WdfUsbTargetPipeReadSynchronously failed 0x%08x\n", status));
    }

    if (BytesRead) *BytesRead = bytesTransferred;
    return status;
}

VOID
MtpEvtUsbReadComplete(
    WDFUSBPIPE  Pipe,
    WDFMEMORY   Buffer,
    size_t      NumBytesTransferred,
    WDFCONTEXT  Context
    )
{
    WDFDEVICE device;
    PVOID data;
    
    UNREFERENCED_PARAMETER(Pipe);
    
    device = (WDFDEVICE)Context;
    if (NumBytesTransferred == 0) return;

    data = WdfMemoryGetBuffer(Buffer, NULL);
    MtpUsb_OnDataReceived(device, data, NumBytesTransferred);
}

NTSTATUS
MtpUsb_StartReaders(WDFDEVICE Device)
{
    UNREFERENCED_PARAMETER(Device);
    return STATUS_SUCCESS;
}

NTSTATUS
MtpUsb_StopReaders(WDFDEVICE Device)
{
    UNREFERENCED_PARAMETER(Device);
    return STATUS_SUCCESS;
}

WDFUSBPIPE MtpUsb_GetBulkInPipe(WDFDEVICE Device)
{
    PDEVICE_CONTEXT ctx = DeviceGetContext(Device);
    return ctx ? ctx->BulkInPipe : NULL;
}

WDFUSBPIPE MtpUsb_GetBulkOutPipe(WDFDEVICE Device)
{
    PDEVICE_CONTEXT ctx = DeviceGetContext(Device);
    return ctx ? ctx->BulkOutPipe : NULL;
}
