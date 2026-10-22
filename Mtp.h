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

// Dynamic USB transfer speed & chunk size IOCTL
#define IOCTL_MTP_GET_TRANSFER_SPEED     CTL_CODE(FILE_DEVICE_UNKNOWN, 0x815, METHOD_BUFFERED, FILE_READ_DATA)

// Legacy single-shot IOCTLs (wrapper around chunked APIs)
#define IOCTL_MTP_GET_OBJECT             IOCTL_MTP_GET_OBJECT_PART
#define IOCTL_MTP_SEND_OBJECT            IOCTL_MTP_SEND_OBJECT_PART

// MTP Opcode Constants (including 64-bit large-file transfer extensions)
#define MTP_OP_GET_DEVICE_INFO           0x1001
#define MTP_OP_OPEN_SESSION              0x1002
#define MTP_OP_CLOSE_SESSION             0x1003
#define MTP_OP_GET_STORAGE_IDS           0x1004
#define MTP_OP_GET_STORAGE_INFO          0x1005
#define MTP_OP_GET_NUM_OBJECTS           0x1006
#define MTP_OP_GET_OBJECT_HANDLES        0x1007
#define MTP_OP_GET_OBJECT_INFO           0x1008
#define MTP_OP_GET_OBJECT                0x1009
#define MTP_OP_DELETE_OBJECT             0x100B
#define MTP_OP_SEND_OBJECT_INFO          0x100C
#define MTP_OP_SEND_OBJECT               0x100D
#define MTP_OP_GET_PARTIAL_OBJECT        0x101B
#define MTP_OP_GET_PARTIAL_OBJECT_64     0x95C1
#define MTP_OP_GET_OBJECT_PROP_VALUE     0x9803
#define MTP_PROP_OBJECT_SIZE_64          0xDC03

// Dynamic controller speed information
typedef struct _MTP_SPEED_INFO {
    ULONG ControllerType;    // 1 = UHCI/OHCI (USB 1.1), 2 = EHCI (USB 2.0), 3 = xHCI (USB 3.x/4)
    ULONG MaxPacketSize;     // 64, 512, or 1024
    ULONG OptimalChunkSize;  // 16384 (16KB for UHCI), 65536 (64KB for EHCI), 262144 (256KB for xHCI)
} MTP_SPEED_INFO, *PMTP_SPEED_INFO;

// 64-bit Partial Object Request (Supports files from 0 to 18 Exabytes)
#pragma pack(push, 1)
typedef struct _MTP_GET_PART_REQ {
    ULONG Id;
    ULONG OffsetLow;
    ULONG OffsetHigh;
    ULONG Length;
} MTP_GET_PART_REQ, *PMTP_GET_PART_REQ;
#pragma pack(pop)

NTSTATUS MtpInitializeDevice(WDFDEVICE Device);
NTSTATUS MtpGetDeviceInfo(WDFREQUEST Request);
NTSTATUS MtpGetTransferSpeed(WDFREQUEST Request);
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
