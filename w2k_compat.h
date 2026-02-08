#pragma once
/*
 * w2k_compat.h - Windows 2000 DDK compatibility definitions
 * 
 * This header provides fallback definitions for macros and types that
 * don't exist in the Windows 2000 DDK but are used by modern code
 * analysis tools and KMDF headers.
 */
// Use local DriverSpecs stubs for annotation definitions
#include "driverspecs.h"

// Windows version macros
#ifndef NTDDI_WIN2K
#define NTDDI_WIN2K 0x05000000
#endif

#ifndef NTDDI_VERSION
#define NTDDI_VERSION NTDDI_WIN2K
#endif

#ifndef OSVER
#define OSVER(x) (x)
#endif

// Windows 2000 pool APIs compatibility
#ifndef ExFreePoolWithTag
#define ExFreePoolWithTag(P, Tag) ExFreePool(P)
#endif

// KMDF 1.9 doesn't have WdfRequestGetDevice, need to go through queue
#ifndef WdfRequestGetDevice
#define WdfRequestGetDevice(Request) WdfIoQueueGetDevice(WdfRequestGetIoQueue(Request))
#endif

// SAL (Source Annotation Language) annotations - used by code analysis tools
// These expand to nothing if not already defined
#ifndef _In_
#define _In_
#endif

#ifndef _In_opt_
#define _In_opt_
#endif

#ifndef _Out_
#define _Out_
#endif

#ifndef _Inout_
#define _Inout_
#endif

#ifndef _Outptr_
#define _Outptr_
#endif

#ifndef _Outptr_result_maybenull_
#define _Outptr_result_maybenull_
#endif

#ifndef _In_reads_bytes_
#define _In_reads_bytes_(size)
#endif

#ifndef _Out_writes_bytes_
#define _Out_writes_bytes_(size)
#endif

// Driver declaration macros used by static analysis
#ifndef DRIVER_INITIALIZE
#define DRIVER_INITIALIZE
#endif

#ifndef DRIVER_UNLOAD
#define DRIVER_UNLOAD
#endif

// KMDF/WDF compatibility
#ifndef USBD_CLIENT_CONTRACT_VERSION_602
#define USBD_CLIENT_CONTRACT_VERSION_602 0
#endif

#ifndef WDF_USB_DEVICE_CREATE_CONFIG
#define WDF_USB_DEVICE_CREATE_CONFIG(x)
#endif

// Windows 2000 doesn't have GROUP_AFFINITY - stub it out
#ifndef _GROUP_AFFINITY_DEFINED
#define _GROUP_AFFINITY_DEFINED
typedef struct _GROUP_AFFINITY {
    ULONG_PTR Mask;
    USHORT Group;
    USHORT Reserved[3];
} GROUP_AFFINITY, *PGROUP_AFFINITY;
#endif

// Windows 2000 doesn't have WDF_INTERRUPT_EXTENDED_POLICY - pre-declare
#ifndef _WDF_INTERRUPT_EXTENDED_POLICY_DEFINED
#define _WDF_INTERRUPT_EXTENDED_POLICY_DEFINED
typedef struct _WDF_INTERRUPT_EXTENDED_POLICY WDF_INTERRUPT_EXTENDED_POLICY, *PWDF_INTERRUPT_EXTENDED_POLICY;
#endif
