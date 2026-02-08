/*
 * Driver.c - KMDF 1.9 MTP sample (Windows 2000 compatible)
 * Minimal, extended sample/reference implementation for study and testing.
 */

#include <ntddk.h>

#if (_WIN32_WINNT == 0x0500)
// Only include compatibility layer for Windows 2000 DDK
#include "w2k_compat.h"
#endif

#include <wdf.h>
#include "Mtp.h"

// DriverEntry - Standard Windows 2000 kernel driver entry point
// Called by the I/O Manager when the driver is loaded
NTSTATUS
DriverEntry(
    IN PDRIVER_OBJECT  DriverObject,
    IN PUNICODE_STRING RegistryPath
    )
{
    WDF_DRIVER_CONFIG config;
    NTSTATUS status;

    WDF_DRIVER_CONFIG_INIT(&config, MtpEvtDeviceAdd);

    status = WdfDriverCreate(DriverObject,
                             RegistryPath,
                             WDF_NO_OBJECT_ATTRIBUTES,
                             &config,
                             WDF_NO_HANDLE);

    if (!NT_SUCCESS(status)) {
        KdPrint(("MTP: WdfDriverCreate failed 0x%08x\n", status));
    } else {
        KdPrint(("MTP: DriverEntry success\n"));
    }

    return status;
}
