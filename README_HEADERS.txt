README: Headers used by this MTP KMDF (1.9) + Windows 2000 driver project

This file documents the headers referenced by the driver and user-mode test program, the full paths found in the workspace, which project files include them, and a short explanation of what we use the header for.

---

## KMDF (WDF) headers (KMDF 1.9)

- `wdf.h`
  - Path: c:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\7600.16385.1\inc\wdf\kmdf\1.9\wdf.h
  - Included by: `Driver.c`, `Device.c`, `Usb.c`, `Mtp.c`, `Usb.h`, `Mtp.h`
  - Use: Core KMDF types and APIs. Commonly used symbols:
    - WdfDriverCreate, WdfDeviceCreate, WdfDeviceInitSetPnpPowerEventCallbacks
    - WdfIoQueueCreate, WdfIoTargetStart, WdfIoTargetStop
    - WdfRequestRetrieveInputBuffer, WdfRequestRetrieveOutputBuffer, WdfRequestComplete, WdfRequestCompleteWithInformation
    - WDF_OBJECT_ATTRIBUTES_INIT, WDF_OBJECT_ATTRIBUTES, WdfSpinLockCreate, WdfMemoryCreate, WdfObjectDelete
    - InterlockedIncrement (transaction counter helper used in-building ops)

- `wdfdriver.h`
  - Path: c:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\7600.16385.1\inc\wdf\kmdf\1.9\wdfdriver.h
  - Included by: (pulled in via `wdf.h` / KMDF headers)
  - Use: Driver create APIs, driver-level types/structures.

- `wdfusb.h`
  - Path: c:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\7600.16385.1\inc\wdf\kmdf\1.9\wdfusb.h
  - Included by: `Device.c`, `Usb.c`, `Usb.h`
  - Use: WDFUSB API. Commonly used symbols:
    - WdfUsbTargetDeviceCreate, WdfUsbTargetDeviceGetInterface, WdfUsbTargetDeviceGetNumInterfaces
    - WdfUsbInterfaceGetNumEndpoints, WdfUsbInterfaceGetConfiguredPipe, WdfUsbTargetPipeIsInEndpoint
    - WdfUsbTargetPipeConfigContinuousReader, WDF_USB_CONTINUOUS_READER_CONFIG_INIT
    - WdfUsbTargetPipeFormatRequestForWrite, WdfUsbTargetPipeGetIoTarget, WdfUsbTargetPipeGetInformation

---

## Windows 2000 (3790.1830) / DDK headers (kernel & USB)

- `ntddk.h`
  - Path: c:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\3790.1830\inc\ddk\w2k\ntddk.h
  - Included by: `Driver.c`, `Device.c`, `Usb.c`, `Mtp.c`, `Usb.h`, `Mtp.h`
  - Use: Kernel-mode types/macros and helpers. Commonly used symbols:
    - Memory / allocation: ExAllocatePoolWithTag, ExFreePoolWithTag
    - Rtl helpers: RtlCopyMemory, RtlZeroMemory
    - Synchronization: KeInitializeEvent, KeWaitForSingleObject, KeSetEvent, KeClearEvent, Executive, KernelMode
    - Interlocked/atomic: InterlockedIncrement
    - Debugging: KdPrint
    - Status codes: NTSTATUS values defined in ntstatus.h (STATUS_SUCCESS, STATUS_IO_TIMEOUT, STATUS_DEVICE_DATA_ERROR, ...)
    - Type aliases: PVOID, ULONG, USHORT, LIST_ENTRY, KEVENT, etc.

- `ntstatus.h`
  - Path: c:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\3790.1830\inc\ddk\w2k\ntstatus.h
  - Included by: indirectly via `ntddk.h` and other kernel headers
  - Use: Definition of NTSTATUS values used for return codes and status checks.

- `usbdi.h`
  - Path: c:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\3790.1830\inc\w2k\usbdi.h
  - Included by: (used indirectly by USB-related code and for reference to USB structures/constants)
  - Use: USB Device Interface definitions and structures used when examining descriptors or interacting with legacy USBD data structures.

- `usbioctl.h`
  - Path: c:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\3790.1830\inc\w2k\usbioctl.h
  - Included by: (used when USB IOCTL constants are needed)
  - Use: IOCTL definitions for low-level USB control operations (used for reference or any direct IOCTL usage).

- `usb100.h`
  - Path: c:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\3790.1830\inc\w2k\usb100.h
  - Included by: (USB descriptor constants usage)
  - Use: USB 1.0 descriptor and constant definitions (e.g., standard descriptor types / class codes).

- `usbdlib.h`
  - Path: c:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\3790.1830\inc\ddk\wdm\w2k\usbdlib.h
  - Included by: (used indirectly by USB helper layers)
  - Use: USBD helper types/functions for descriptor handling and older USBD-style helpers.

- `windef.h` and `winerror.h`
  - Path: c:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\3790.1830\inc\w2k\windef.h
  - Included by: kernel and user files via higher-level headers
  - Use: Basic Windows types (`DWORD`, `BOOL`, `MAX_PATH`) and Win32/WINERR error codes used both in kernel and user-mode code.

---

## Project headers (in this repository)

- `Mtp.h`
  - Path: src\mtp_kmdf_w2k\Mtp.h
  - Included by: `Driver.c`, `Device.c`, `Mtp.c`
  - Use: Declarations for MTP core functions, IOCTL definitions (IOCTL_MTP_*), object store prototypes and context structure shared across the driver.
  - Exported runtime helpers used across files:
    - MtpInitializeDevice, MtpCleanupDevice, MtpGetDeviceInfo, MtpListObjects
    - MtpGetObjectPart, MtpSendObjectPart
    - MtpSessionOpen, MtpSessionClose, MtpOperation
    - MtpUsb_OnDataReceived (used by the USB layer to hand parsed buffers to the core)

- `Usb.h`
  - Path: src\mtp_kmdf_w2k\Usb.h
  - Included by: `Device.c`, `Usb.c`, `Usb.h` (self)
  - Use: Device context (WDFUSBDEVICE, pipe references), prototypes for USB helper functions (`MtpUsb_Create`, `MtpUsb_WriteBulk`, `MtpUsb_StartReaders`, `MtpUsb_StopReaders`) and definitions for continuous reader callback wiring.

---

## User-mode headers (test program) — use Windows 2000 SDK in workspace

- `Windows.h`, `WinIoCtl.h`, `stdio.h`, `stdlib.h`
  - Path (workspace): c:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\2000 sdk\Include\Windows.h
  - Included by: `user\mtp_test.c`
  - Use: The user-mode test is built explicitly against the Windows 2000 SDK in the workspace (`2000 sdk`). The build script `user\build_test.bat` sets the Include path to the 2000 SDK and the LIB path to `2000 sdk\Lib` so no newer Windows headers are used.
  - Specific symbols/functions used from these headers:
    - `Windows.h` (Win32 core): `CreateFileA`, `CloseHandle`, `GetLastError`, `HANDLE`, `INVALID_HANDLE_VALUE`, `GENERIC_READ`, `GENERIC_WRITE`, `OPEN_EXISTING`
    - `WinIoCtl.h`: `DeviceIoControl` and IOCTL/overlapped helpers (present in 2000 SDK)
    - `stdio.h`: `printf`
    - `stdlib.h`: `malloc`, `free`

Note: The build script checks that `Windows.h` exists in the `2000 sdk\Include` directory and errors out if the folder is not present. This enforces using only the legacy headers the project owner requested.

---

## Build guidance / notes

- The driver MUST be compiled with the correct include order so that *non-KMDF* headers come from the Windows 2000 `3790.1830` include tree and WDF headers come from the KMDF 1.9 include tree. The project `Sources` and the README indicate using the Windows 2000 DDK `setenv.bat` and adding the KMDF 1.9 include directory.

- If you need to verify an exact header file, search the workspace paths above. The canonical list of the KMDF and W2K header locations used in this project is already recorded in `headers_used.txt`.

---

If you'd like, I can also add the header paths to the top-level `README.md` and/or annotate each source file with a short comment referencing the expected header version (KMDF 1.9 vs W2K). Want me to do that? 
