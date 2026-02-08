#pragma once

#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif

#include <ntddk.h>
#include <wdf.h>
#include "Usb.h"

#define IOCTL_MTP_GET_DEVICE_INFO        CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_READ_DATA)
#define IOCTL_MTP_LIST_OBJECTS           CTL_CODE(FILE_DEVICE_UNKNOWN, 0x801, METHOD_BUFFERED, FILE_READ_DATA)
#define IOCTL_MTP_GET_OBJECT_PART        CTL_CODE(FILE_DEVICE_UNKNOWN, 0x802, METHOD_BUFFERED, FILE_READ_DATA)
#define IOCTL_MTP_SEND_OBJECT_PART       CTL_CODE(FILE_DEVICE_UNKNOWN, 0x803, METHOD_BUFFERED, FILE_WRITE_DATA)

// Session and generic operation IOCTLs
#define IOCTL_MTP_SESSION_OPEN           CTL_CODE(FILE_DEVICE_UNKNOWN, 0x810, METHOD_BUFFERED, FILE_READ_DATA)
#define IOCTL_MTP_SESSION_CLOSE          CTL_CODE(FILE_DEVICE_UNKNOWN, 0x811, METHOD_BUFFERED, FILE_READ_DATA)
#define IOCTL_MTP_OPERATION              CTL_CODE(FILE_DEVICE_UNKNOWN, 0x812, METHOD_BUFFERED, FILE_READ_DATA)

// Legacy single-shot IOCTLs (wrapper around chunked APIs)
#define IOCTL_MTP_GET_OBJECT             IOCTL_MTP_GET_OBJECT_PART
#define IOCTL_MTP_SEND_OBJECT            IOCTL_MTP_SEND_OBJECT_PART

NTSTATUS MtpInitializeDevice(WDFDEVICE Device);
NTSTATUS MtpGetDeviceInfo(WDFREQUEST Request);
NTSTATUS MtpListObjects(WDFREQUEST Request);
NTSTATUS MtpGetObjectPart(WDFREQUEST Request);
NTSTATUS MtpSendObjectPart(WDFREQUEST Request);
NTSTATUS MtpCleanupDevice(WDFDEVICE Device);

// Internal helper function
NTSTATUS MtpSendOperationAndReceiveData(IN WDFDEVICE Device, IN USHORT Opcode, IN OPTIONAL ULONG *Params, IN ULONG ParamCount, IN OPTIONAL PVOID Data, IN size_t DataLen, OUT PVOID *OutData, OUT size_t *OutDataLen, OUT USHORT *OutResponse);

// Session and operation handlers
NTSTATUS MtpSessionOpen(WDFREQUEST Request);
NTSTATUS MtpSessionClose(WDFREQUEST Request);
NTSTATUS MtpOperation(WDFREQUEST Request);

// Hook called from USB read callback to enqueue device responses
VOID MtpUsb_OnDataReceived(IN WDFDEVICE Device, IN PVOID Data, IN size_t Length);

// Driver event prototypes
NTSTATUS MtpEvtDeviceAdd(IN WDFDRIVER Driver, IN OUT PWDFDEVICE_INIT DeviceInit);
NTSTATUS MtpEvtDevicePrepareHardware(IN WDFDEVICE Device, IN WDFCMRESLIST ResourcesRaw, IN WDFCMRESLIST ResourcesTranslated);
NTSTATUS MtpEvtDeviceReleaseHardware(IN WDFDEVICE Device, IN WDFCMRESLIST ResourcesTranslated);
NTSTATUS MtpEvtDeviceD0Entry(IN WDFDEVICE Device, IN WDF_POWER_DEVICE_STATE PreviousState);
NTSTATUS MtpEvtDeviceD0Exit(IN WDFDEVICE Device, IN WDF_POWER_DEVICE_STATE TargetState);
VOID MtpEvtIoDeviceControl(IN WDFQUEUE Queue, IN WDFREQUEST Request, IN size_t OutputBufferLength, IN size_t InputBufferLength, IN ULONG IoControlCode);
