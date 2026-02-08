================================================================================
  MTP KMDF 1.9 Driver for Windows 2000 - Build Instructions
  Presentation: February 2, 2026
================================================================================

QUICK START - For Presentation
-------------------------------
Simply double-click:  BUILD_RELEASE.bat

This will:
  1. Clean previous builds
  2. Compile all source files (Driver.c, Device.c, Usb.c, Mtp.c, security_stub.c)
  3. Link the driver with KMDF 1.9 libraries
  4. Copy final driver to Release\mtp.sys
  5. Display build summary

Build Output:
  - Release\mtp.sys       (Windows 2000 driver binary)
  - Release\mtp.pdb       (Debug symbols)

Build Requirements:
  - Windows Server 2003 DDK (3790.1830)
  - Windows 7 DDK (7600.16385.1) - for KMDF 1.9 libraries
  - Both DDKs already configured in this workspace

Manual Build (if needed):
  1. Open Command Prompt
  2. cd to this directory
  3. Run: build_w2k.bat
  4. Driver will be in: objchk_w2k_x86\i386\mtp.sys

Technical Details:
  - Target OS: Windows 2000 (5.0)
  - KMDF Version: 1.9 (last version supporting Windows 2000)
  - Architecture: x86 (32-bit)
  - Build Type: Checked (Debug) - includes KdPrint logging
  - Compiler: Microsoft C/C++ 13.10.4035 (Windows 2003 DDK)
  - C Standard: C90 (all variable declarations at function start)

Key Compatibility Fixes Applied:
  - C90 compliance (220+ variable declarations moved)
  - ExFreePoolWithTag stub (uses ExFreePool on W2K)
  - WdfRequestGetDevice macro (KMDF 1.9 uses queue-based API)
  - Security cookie stub (buffer checks not in W2K)
  - Volatile qualifier casts for InterlockedIncrement
  - WdfMemoryCreatePreallocated for USB transfers

Files in This Build:
  - Driver.c         : Driver entry point and WDF configuration
  - Device.c         : PnP callbacks (Add, PrepareHardware, D0Entry/Exit)
  - Usb.c            : USB bulk transfer operations
  - Mtp.c            : MTP protocol implementation with in-memory object store
  - security_stub.c  : Security cookie stub for KMDF compatibility
  - Mtp.h            : Public function declarations
  - Usb.h            : USB context structures
  - w2k_compat.h     : Windows 2000 compatibility layer
  - sources          : DDK build configuration
  - makefile         : DDK build system entry point

Deployment on Windows 2000:
  1. Copy Release\mtp.sys to target system
  2. Install KMDF 1.9 coinstaller (WdfCoInstaller01009.dll)
  3. Create INF file for device installation
  4. Use Device Manager to install driver

Good luck with the presentation!
================================================================================
