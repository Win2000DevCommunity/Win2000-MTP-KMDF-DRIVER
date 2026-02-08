# Windows 2000 MTP KMDF 1.9 Driver

## Overview
This project provides a Windows 2000-compatible MTP (Media Transfer Protocol) driver using KMDF 1.9, plus a user-mode test application. It is designed for legacy device support and educational/demo purposes.

---

## Quick Build Instructions

### 1. **Build the Driver**
- **Script to run:**
  - `BUILD_RELEASE.bat`
- **What it does:**
  - Cleans previous builds
  - Compiles all driver sources
  - Links with KMDF 1.9 libraries
  - Copies the resulting `mtp.sys` to the `Release` folder
  - Shows a build summary

### 2. **Build the User-Mode Test App**
- **Script to run:**
  - `test_app\build_test.bat`
- **What it does:**
  - Compiles the test app using the Windows 2000 DDK/SDK headers
  - Produces `mtp_test.exe` for testing driver IOCTLs

---

## Requirements
- **Windows 2000 DDK** (included in the Windows Server 2003 DDK)
  - Path example: `3790.1830` (for build system and driver compilation)
- **Windows 2000 SDK** (for user-mode test app)
  - Path example: `2000 sdk` (for headers/libs)
- **KMDF 1.9 CoInstaller** (from Windows 7 DDK, for runtime on Win2000)
  - File: `WdfCoInstaller01009.dll` (see `7600.16385.1/redist/wdf/x86/`)

---

## Deployment Notes
- **You MUST install KMDF 1.9 runtime on Windows 2000** before loading the driver:
  - Copy `WdfCoInstaller01009.dll` to the target system
  - Run: `rundll32 WdfCoInstaller01009.dll,WdfPreDeviceInstall`
  - Or manually extract/copy `Wdf01000.sys` to `C:\WINNT\System32\drivers\`
- **Driver output:**
  - `Release\mtp.sys` (ready to deploy)
- **Test app output:**
  - `test_app\mtp_test.exe`

---

## Current Issues / Troubleshooting

- **BSOD (KMODE_EXCEPTION_NOT_HANDLED) at WdfDriverCreate:**
  - A blue screen or crash with a stack trace pointing to `WdfDriverCreate` or a NULL pointer dereference has been observed on Windows 2000.
  - This typically indicates that the KMDF 1.9 runtime (`Wdf01000.sys`) is not loaded at the time the driver is started, or that there is a problem with driver or INF configuration (such as PnP settings or KMDF version specification).
  - The exact root cause and reliable resolution are still under investigation. If you encounter this issue, please review your environment and configuration, and report any findings.
  - This is a known blocker for all KMDF-based drivers on Windows 2000 if the runtime is not properly loaded.

---

## File Structure
- `Driver.c`, `Device.c`, `Usb.c`, `Mtp.c` — Driver sources
- `Mtp.h`, `Usb.h`, `w2k_compat.h` — Driver headers
- `sources`, `makefile` — DDK build system files
- `BUILD_RELEASE.bat` — Main build script (run this!)
- `security_stub.c` — Security cookie stub for legacy builds
- `test_app/` — User-mode test app and build script

---

## Credits
- Built for Windows 2000 using official DDK/SDK tools
- KMDF 1.9 support via Windows 7 DDK redist

---

## Project Scope

This project is a **pre-professional** Windows 2000 MTP KMDF 1.9 driver and user-mode application. It is intended as a robust reference for real-world driver and application development, not just as a demo or educational sample.

- The user-mode application (see `user_app/`) features a GUI for interacting with the driver.

---

## User-Mode Application (GUI)

![MTP File Transfer GUI]([https://media.discordapp.net/attachments/1335004090668810310/1470035218571198647/image.png?ex=6989d47c&is=698882fc&hm=25398f84cbe3cc9bc465d292bcad0405fadbb3324652d86a39bf2586115a64cc&=&format=webp&quality=lossless&width=1071&height=770]))

The user-mode application, located in the `user_app/` directory, provides a graphical interface for interacting with the MTP driver. It allows users to:

- Connect to MTP devices
- Browse, transfer, and manage files
- Send commands to the driver using custom IOCTLs (DeviceIoControl)
- Monitor device status and transfer progress

The app demonstrates real-world usage of driver IOCTLs from a Windows 2000 user-mode GUI, making it a practical reference for legacy device communication and driver testing.

---

**For any issues, check the README_BUILD.txt and test_app/README.txt for troubleshooting and usage details.**
