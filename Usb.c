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
MtpUsb_Create(WDFDEVICE Device, PMTP_USB_CONFIG Config)
{
    NTSTATUS status;
    WDFUSBDEVICE usbDevice;
    PDEVICE_CONTEXT ctx;
    UCHAR numInterfaces;
    WDFUSBINTERFACE usbInterface;
    UCHAR i;
    WDF_USB_PIPE_INFORMATION pi;
    WDFUSBPIPE pipe;
    WDF_USB_CONTINUOUS_READER_CONFIG contReaderConfig;

    // Create USB device object using WDF. Avoid newer create-config helpers
    // which may not be present in older KMDF 1.9 headers.
    status = WdfUsbTargetDeviceCreate(Device, WDF_NO_OBJECT_ATTRIBUTES, &usbDevice);
    if (!NT_SUCCESS(status)) {
        KdPrint(("MTP: WdfUsbTargetDeviceCreate failed 0x%08x\n", status));
        return status;
    }

    // Save the usb device handle in context early
    ctx = DeviceGetContext(Device);
    ctx->UsbDevice = usbDevice;
    // mark USB as present
    ctx->UsbPresent = TRUE;

    // Select first configuration and find bulk endpoints (simplified)
    numInterfaces = WdfUsbTargetDeviceGetNumInterfaces(usbDevice);
    if (numInterfaces == 0) {
        KdPrint(("MTP: No USB interfaces found\n"));
        return STATUS_DEVICE_CONFIGURATION_ERROR;
    }

    usbInterface = WdfUsbTargetDeviceGetInterface(usbDevice, 0);
    if (usbInterface == NULL) {
        KdPrint(("MTP: GetInterface failed\n"));
        return STATUS_DEVICE_CONFIGURATION_ERROR;
    }

    ctx->UsbInterface = usbInterface;

    // store default config if none provided
    if (Config) {
        ctx->UsbConfig = *Config;
    } else {
        ctx->UsbConfig.ReadBufferSize = 4096;
        ctx->UsbConfig.NumReaders = 2;
        ctx->UsbConfig.TransferTimeoutMs = 5000;
        ctx->UsbConfig.RetryCount = 3;
    }

    // Find bulk pipes and configure a continuous reader on the IN pipe
    for (i = 0; i < WdfUsbInterfaceGetNumEndpoints(usbInterface, 0); i++) {
        WDF_USB_PIPE_INFORMATION_INIT(&pi);
        pipe = WdfUsbInterfaceGetConfiguredPipe(usbInterface, i, &pi);
        WdfUsbTargetPipeGetInformation(pipe, &pi);

        if (pi.PipeType == WdfUsbPipeTypeBulk) {
            if (WdfUsbTargetPipeIsInEndpoint(pipe)) {
                // Bulk IN
                ctx->BulkInPipe = pipe;
                ctx->MaxPacketSize = pi.MaximumPacketSize;

                // Configure continuous reader (reader will be started in D0Entry)
                WDF_USB_CONTINUOUS_READER_CONFIG_INIT(&contReaderConfig, MtpEvtUsbReadComplete, Device, ctx->UsbConfig.ReadBufferSize);
                contReaderConfig.NumPendingReads = (UCHAR)ctx->UsbConfig.NumReaders;

                status = WdfUsbTargetPipeConfigContinuousReader(ctx->BulkInPipe, &contReaderConfig);
                if (!NT_SUCCESS(status)) {
                    KdPrint(("MTP: Failed to configure continuous reader 0x%08x\n", status));
                }

            } else {
                ctx->BulkOutPipe = pipe;
            }
        }
    }

    KdPrint(("MTP: USB device created and pipes located\n"));
    return STATUS_SUCCESS;
}

// Simple synchronous bulk write (blocking) with retry logic and device presence check
// Returns STATUS_INVALID_DEVICE_STATE if device is marked as absent (disconnected)
NTSTATUS
MtpUsb_WriteBulk(
    WDFDEVICE Device,
    WDFUSBPIPE Pipe,
    PVOID Buffer,
    size_t Length
    )
{
    PDEVICE_CONTEXT ctx;
    ULONG retries;
    NTSTATUS status;
    ULONG attempt;
    WDFREQUEST request;
    WDFMEMORY memory;
    WDF_OBJECT_ATTRIBUTES memAttrib;
    
    if (!Buffer || Length == 0 || !Device || !Pipe) {
        return STATUS_INVALID_PARAMETER;
    }

    ctx = DeviceGetContext(Device);
    
    // Check if device is still present
    if (!ctx || !ctx->UsbPresent) {
        KdPrint(("MTP: USB device not present, aborting write\n"));
        return STATUS_INVALID_DEVICE_STATE;
    }

    // Create memory object from preallocated buffer
    WDF_OBJECT_ATTRIBUTES_INIT(&memAttrib);
    memAttrib.ParentObject = Device;
    status = WdfMemoryCreatePreallocated(&memAttrib, Buffer, (size_t)Length, &memory);
    if (!NT_SUCCESS(status)) {
        KdPrint(("MTP: WdfMemoryCreatePreallocated failed 0x%08x\n", status));
        return status;
    }

    retries = ctx->UsbConfig.RetryCount;
    status = STATUS_UNSUCCESSFUL;

    for (attempt = 0; attempt <= retries; ++attempt) {
        // Re-check device presence before each retry
        if (!ctx->UsbPresent) {
            WdfObjectDelete(memory);
            return STATUS_INVALID_DEVICE_STATE;
        }

        request = NULL;
        status = WdfRequestCreate(WDF_NO_OBJECT_ATTRIBUTES, WdfUsbTargetPipeGetIoTarget(Pipe), &request);
        if (!NT_SUCCESS(status)) {
            if (attempt == retries) {
                KdPrint(("MTP: WdfRequestCreate failed 0x%08x on final attempt\n", status));
                WdfObjectDelete(memory);
                return status;
            }
            continue;
        }

        status = WdfUsbTargetPipeFormatRequestForWrite(Pipe, request, memory, NULL);
        if (!NT_SUCCESS(status)) {
            WdfObjectDelete(request);
            if (attempt == retries) {
                KdPrint(("MTP: WdfUsbTargetPipeFormatRequestForWrite failed 0x%08x\n", status));
                WdfObjectDelete(memory);
                return status;
            }
            continue;
        }

        if (!WdfRequestSend(request, WdfUsbTargetPipeGetIoTarget(Pipe), NULL)) {
            status = WdfRequestGetStatus(request);
            WdfObjectDelete(request);
            
            // Check for device gone status codes
            if (status == STATUS_CANCELLED || status == STATUS_DEVICE_NOT_CONNECTED ||
                status == STATUS_NO_SUCH_DEVICE || status == STATUS_IO_DEVICE_ERROR) {
                ctx->UsbPresent = FALSE;
                KdPrint(("MTP: Device disconnected or I/O error 0x%08x\n", status));
                WdfObjectDelete(memory);
                return STATUS_INVALID_DEVICE_STATE;
            }
            
            // Also check for device timeout which may indicate disconnection
            if (status == STATUS_IO_TIMEOUT) {
                KdPrint(("MTP: I/O timeout (possible disconnection): 0x%08x\n", status));
                // Don't immediately mark as absent, but return the timeout
                WdfObjectDelete(memory);
                return status;
            }
            
            if (attempt == retries) {
                KdPrint(("MTP: WdfRequestSend failed 0x%08x on final attempt\n", status));
                WdfObjectDelete(memory);
                return status;
            }
            continue;
        }

        WdfObjectDelete(request);

        if (NT_SUCCESS(status)) {
            WdfObjectDelete(memory);
            return status;  // Success
        }
        
        // transient failure: try again (no long delay to keep driver responsive)
    }

    KdPrint(("MTP: WriteBulk exhausted all retries, last status 0x%08x\n", status));
    WdfObjectDelete(memory);
    return status;
}


// Read helper (continuous reader completion) used for event and response processing
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

    // Hand the buffer to the MTP core module (the core will parse containers)
    MtpUsb_OnDataReceived(device, data, NumBytesTransferred);

}

// Start/Stop readers
NTSTATUS
MtpUsb_StartReaders(WDFDEVICE Device)
{
    PDEVICE_CONTEXT ctx;
    
    ctx = DeviceGetContext(Device);
    if (!ctx || !ctx->BulkInPipe) return STATUS_INVALID_DEVICE_STATE;
    return WdfIoTargetStart(WdfUsbTargetPipeGetIoTarget(ctx->BulkInPipe));
}

NTSTATUS
MtpUsb_StopReaders(WDFDEVICE Device)
{
    PDEVICE_CONTEXT ctx;
    
    ctx = DeviceGetContext(Device);
    if (!ctx || !ctx->BulkInPipe) return STATUS_INVALID_DEVICE_STATE;
    WdfIoTargetStop(WdfUsbTargetPipeGetIoTarget(ctx->BulkInPipe), 0);
    return STATUS_SUCCESS;
}

WDFUSBPIPE MtpUsb_GetBulkInPipe(WDFDEVICE Device) { return DeviceGetContext(Device)->BulkInPipe; }
WDFUSBPIPE MtpUsb_GetBulkOutPipe(WDFDEVICE Device) { return DeviceGetContext(Device)->BulkOutPipe; }
