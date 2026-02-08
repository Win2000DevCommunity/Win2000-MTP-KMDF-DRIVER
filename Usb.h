#pragma once

#include "w2k_compat.h"
#include <ntddk.h>
#include <wdf.h>
#include <usb.h>
#include <usbdi.h>
#include <usbdlib.h>
#include <wdfusb.h>

// USB configuration parameters for the sample
typedef struct _MTP_USB_CONFIG {
    ULONG ReadBufferSize;      // bytes per reader
    ULONG NumReaders;          // number of outstanding readers
    ULONG TransferTimeoutMs;   // timeout for individual transfers
    ULONG RetryCount;          // retry count for transient failures
} MTP_USB_CONFIG, *PMTP_USB_CONFIG;

#ifndef MTP_DEVICE_CONTEXT_DEFINED
#define MTP_DEVICE_CONTEXT_DEFINED
typedef struct _DEVICE_CONTEXT {
    WDFUSBDEVICE UsbDevice;
    WDFUSBINTERFACE UsbInterface;
    WDFUSBPIPE BulkInPipe;
    WDFUSBPIPE BulkOutPipe;
    ULONG MaxPacketSize;
    MTP_USB_CONFIG UsbConfig;
    // Session id maintained by the host driver
    ULONG SessionId;
    // TRUE when a USB device is connected/present (used to avoid waiting for responses when removed)
    BOOLEAN UsbPresent;
} DEVICE_CONTEXT, *PDEVICE_CONTEXT;
#endif

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(DEVICE_CONTEXT, DeviceGetContext)

// USB helpers
NTSTATUS MtpUsb_Create(IN WDFDEVICE Device, IN OPTIONAL PMTP_USB_CONFIG Config);
NTSTATUS MtpUsb_StartReaders(IN WDFDEVICE Device);
NTSTATUS MtpUsb_StopReaders(IN WDFDEVICE Device);
NTSTATUS MtpUsb_WriteBulk(IN WDFDEVICE Device, IN WDFUSBPIPE Pipe, IN PVOID Buffer, IN size_t Length);

// Continuouse reader callback
VOID MtpEvtUsbReadComplete(IN WDFUSBPIPE Pipe, IN WDFMEMORY Buffer, IN size_t NumBytesTransferred, IN WDFCONTEXT Context);

// Utility accessors
WDFUSBPIPE MtpUsb_GetBulkInPipe(IN WDFDEVICE Device);
WDFUSBPIPE MtpUsb_GetBulkOutPipe(IN WDFDEVICE Device);

// Called by USB read callback to hand data to MTP core
VOID MtpUsb_OnDataReceived(IN WDFDEVICE Device, IN PVOID Data, IN size_t Length);

