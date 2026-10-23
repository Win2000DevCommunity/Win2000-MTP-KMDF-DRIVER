# Windows 2000 MTP KMDF 1.9 Driver & Application Suite

A complete, production-ready Windows 2000 (SP4+) compatible MTP (Media Transfer Protocol) driver built with **KMDF 1.9** (Kernel-Mode Driver Framework 1.9, KB970158), accompanied by a native Win32 GUI file manager and CLI diagnostic suite.

> **Status:** Fully functional • Tested & verified on Windows 2000 Professional SP4  
> **Architecture:** x86 (i386) • C89 compatible • KMDF 1.9 kernel-mode driver

---

## Table of Contents

1. [Features](#features)
2. [Quick Start (3 Steps)](#quick-start-3-steps)
3. [Release Packages](#release-packages)
4. [Application Suite](#application-suite)
   - [MTP File Manager GUI](#1-mtp-file-manager-gui-mtp_guiexe)
   - [CLI File Transfer Tool](#2-cli-file-transfer-tool-mtp_transferexe)
   - [CLI Diagnostic Tool](#3-cli-diagnostic-tool-mtp_testexe)
5. [Driver Installation](#driver-installation)
6. [KMDF 1.9 Runtime Setup](#kmdf-19-runtime-setup)
7. [Testing in QEMU](#testing-in-qemu)
8. [USB Pass-Through](#usb-pass-through-physical-devices)
9. [Build Instructions](#build-instructions)
10. [Repository Structure](#repository-structure)
11. [Technical Details & Bug Fixes](#technical-details--bug-fixes)

---

## Features

### Kernel-Mode Driver (`mtp.sys`)
- Full MTP protocol engine with opcodes: `DeviceInfo`, `OpenSession`, `CloseSession`, `GetStorageIDs`, `GetStorageInfo`, `GetObjectHandles`, `GetObjectInfo`, `GetObject`, `DeleteObject`, `SendObjectInfo`, `SendObject`
- Dynamic in-memory object store with hierarchical folder support
- Dynamic storage capacity reporting (reads actual device storage, no hardcoded values)
- 16 KB chunked transfers for UHCI stability
- Proper KMDF 1.9 lifecycle (`FxDriverEntry`, `EvtDevicePrepareHardware`, `EvtDeviceD0Entry`)

### Explorer-Style GUI (`mtp_gui.exe`)
- **Authentic Windows 2000 Explorer interface** with Web View sidebar, Address bar, and standard toolbar
- **Multi-view modes:** Large Icons (default), Small Icons, List, Details
- **Web View sidebar** with file preview thumbnails, metadata panel, and storage capacity meter
- **Address bar navigation** with editable path and Go button
- **Intelligent recursive search engine** (`F3` / `Ctrl+F`): wildcard matching (`*.jpg`, `photo*`), file type filters, subfolder scanning, live progress
- **File operations:** Upload (`Ctrl+U`), Download (`Ctrl+S`), Delete (`Del`), Refresh (`F5`)
- **Clipboard operations:** Cut (`Ctrl+X`), Copy (`Ctrl+C`), Paste (`Ctrl+V`)
- **My Computer integration** via shell namespace extension (`MTP_DRIVE.REG`)
- **Folder Options dialog** for customizing view behavior

### CLI Tools
- `mtp_transfer.exe` — Scriptable file list/get/put/delete operations
- `mtp_test.exe` — Low-level IOCTL diagnostic tool (DeviceInfo, Session, Object enumeration)

---

## Quick Start (3 Steps)

### Step 1: Start the Virtual Machine
```cmd
run_w2k_qemu.bat
```
Launches Windows 2000 with UHCI USB controller and emulated Android MTP phone storage.

### Step 2: Connect via VNC
Open your VNC client and connect to `127.0.0.1:5900`.

### Step 3: Install & Launch
Inside Windows 2000, open Command Prompt and run:
```cmd
D:\SETUP.BAT
```
The script deploys the KMDF runtime, driver, registry entries, and launches the Explorer GUI automatically.

---

## Release Packages

| Package | Contents |
|:--------|:---------|
| `Win2000-MTP-KMDF-Driver-Release.zip` | Driver + GUI + CLI tools + KMDF runtime + installer |
| `Win2000-MTP-Release-BareMetal.zip` | Minimal package for physical hardware deployment |
| `Win2000-MTP-Release-QEMU-VM.zip` | Full VM test environment with QEMU config |

### Package Contents
| File | Description |
|:-----|:------------|
| `mtp.sys` | KMDF 1.9 MTP driver binary (C89, x86) |
| `mtp.inf` | Windows 2000 SetupAPI installation INF |
| `WdfCoInstaller01009.dll` | KMDF 1.9 Co-Installer DLL |
| `mtp_gui.exe` | Native Win32 Explorer-style MTP File Manager |
| `mtp_transfer.exe` | Command-line file transfer tool |
| `mtp_test.exe` | IOCTL diagnostic test tool |
| `SETUP.BAT` | One-click deployment script |
| `MTP_DRIVE.REG` | My Computer namespace shell extension |
| `DISABLE_SIGNING.REG` | Disables driver signing prompts |
| `KMDF-v1.9-Win2k-WinXP-Win2k3/` | Microsoft KMDF 1.9 runtime (KB970158) |

---

## Application Suite

### 1. MTP File Manager GUI (`mtp_gui.exe`)

A native Win32 MTP file manager written specifically for Windows 2000, replicating the authentic Explorer experience.

**Explorer Interface:**
- Classic Web View sidebar with pastel folder icon, bold storage title, and blue accent rule
- Dynamic file preview frame: landscape photo thumbnails, document previews, folder icons
- Live metadata panel: file name, type, size, attributes, and quick actions
- Real-time device storage capacity meter (dynamically queried from device)
- Standard Explorer toolbar: Back, Forward, Up, Connect, Disconnect, Refresh, Download, Upload, Delete, Search, Views
- Address bar with editable path and Go button

**Intelligent Search Engine (F3 / Ctrl+F):**
- Breadth-first recursive traversal of MTP object tree
- Wildcard pattern matching (`*`, `?`) with semicolon-separated multi-pattern support
- File type filters: Pictures, Music, Video, Documents, All Files
- Include/exclude subfolders toggle
- Live progress: scanned/found counters with real-time status bar
- Actions: Open Containing Folder, Download to PC
- Non-blocking with cancel support (Stop button)

**Keyboard Shortcuts:**
| Shortcut | Action |
|:---------|:-------|
| `Ctrl+O` | Connect to device |
| `Ctrl+D` | Disconnect |
| `Ctrl+S` | Download selected file |
| `Ctrl+U` | Upload file to device |
| `Del` | Delete selected file |
| `F5` | Refresh file list |
| `F3` / `Ctrl+F` | Search for files or folders |
| `Ctrl+X/C/V` | Cut / Copy / Paste |
| `Ctrl+A` | Select All |

### 2. CLI File Transfer Tool (`mtp_transfer.exe`)

```cmd
mtp_transfer.exe list                          :: List all files and folders
mtp_transfer.exe get 0x00010001 C:\photo.jpg   :: Download by object ID
mtp_transfer.exe put C:\test.txt               :: Upload local file
mtp_transfer.exe delete 0x00010001             :: Delete object
```

### 3. CLI Diagnostic Tool (`mtp_test.exe`)

```cmd
mtp_test.exe    :: Runs: DeviceInfo → SessionOpen → ListObjects → SessionClose
```

---

## Driver Installation

### Method A: Device Manager (Plug-and-Play)
1. Connect your MTP device or attach the virtual USB device
2. In the Found New Hardware Wizard, select "Have Disk..." and browse to `mtp.inf`
3. Select "MTP Device (KMDF 1.9 - Win2000 Compatible)" and complete the wizard

### Method B: Command-Line (Silent)
```cmd
copy /y WdfCoInstaller01009.dll %SystemRoot%\System32\
copy /y mtp.sys %SystemRoot%\System32\drivers\
devcon.exe update mtp.inf "USB\VID_46F4&PID_0004"
```

---

## KMDF 1.9 Runtime Setup

Windows 2000 SP4 requires the official Microsoft KMDF 1.9 runtime (**KB970158**).

**Silent Install:**
```cmd
KMDF-v1.9-Win2k-WinXP-Win2k3\update\update.exe /quiet /norestart
```

**What it installs:**
- `wdf01000.sys` → `%SystemRoot%\System32\drivers\` (KMDF Core Engine)
- `wdfldr.sys` → `%SystemRoot%\System32\drivers\` (KMDF Dynamic Loader)
- Registry: `HKLM\SYSTEM\CurrentControlSet\Control\Wdf\Kmdf\KmdfLibrary\Versions\1`

---

## Testing in QEMU

```cmd
qemu-system-i386.exe ^
  -machine pc-i440fx-9.2,accel=tcg ^
  -cpu pentium3 -smp 2 -m 2048 ^
  -drive "file=win2000-pro-sp4.img,format=raw,if=ide,index=0,media=disk" ^
  -cdrom kmdf-mtp-install.iso ^
  -boot order=c,menu=off ^
  -nic none ^
  -device piix3-usb-uhci,id=uhci ^
  -device "usb-mtp,bus=uhci.0,rootdir=C:/phone_storage,desc=Android Phone (MTP),readonly=off" ^
  -display vnc=127.0.0.1:0
```

> **Important:** Always use `piix3-usb-uhci`. Windows 2000 includes native UHCI drivers (`usbuhci.sys`), ensuring immediate Plug-and-Play detection.

---

## USB Pass-Through (Physical Devices)

Pass through a physical Android phone or digital camera to Windows 2000 under QEMU:
1. Connect device to host and find its Vendor/Product IDs
2. Add to QEMU command line:
   ```cmd
   -device usb-host,vendorid=0x04e8,productid=0x6860
   ```
3. Windows 2000 will bind it to `mtp.sys` via `mtp.inf`

---

## Build Instructions

### Prerequisites
- Windows 2000 DDK (`3790.1830/`) — provides Win2K target libraries and C runtime
- Windows 7 WDK (`7600.16385.1/`) — provides `cl.exe` v15.00 compiler and KMDF 1.9 headers
- Windows 2000 Platform SDK (`2000 sdk/`) — provides user-mode headers and libraries

### Build Driver (`mtp.sys`)
```cmd
build_w2k_kmdf.bat
```
Compiles `Driver.c`, `Device.c`, `Usb.c`, `Mtp.c`, `security_stub.c` with `/GS-` `/ENTRY:FxDriverEntry` targeting Win2K DDK libraries and KMDF 1.9. Output: `Release\mtp.sys`.

### Build GUI & CLI (`mtp_gui.exe`, `mtp_transfer.exe`)
```cmd
cd user_app
build_gui_w2k.bat
```

### Build Diagnostic Tool (`mtp_test.exe`)
```cmd
cd test_app
build_test.bat
```

### Build Installation ISO
```powershell
.\create_iso.ps1
```

### Build Release Packages
```powershell
.\create_two_releases.ps1
```

---

## Repository Structure

```
Win2000-MTP-KMDF-DRIVER/
│
├── Driver.c                  # KMDF DriverEntry and unload callbacks
├── Device.c                  # EvtDeviceAdd, PnP dispatch, IOCTL routing
├── Usb.c                     # USB bulk pipe I/O, transfer execution
├── Mtp.c                     # Complete MTP protocol engine & object store
├── Mtp.h                     # MTP header definitions & structures
├── Usb.h                     # USB interface definitions
├── w2k_compat.h              # Windows 2000 DDK compatibility layer
├── driverspecs.h             # SAL annotation stubs for Win2K DDK
├── specstrings.h             # String annotation stubs for Win2K DDK
├── security_stub.c           # __security_check_cookie fastcall stub
├── mtp.inf                   # Windows 2000 PnP installation INF
│
├── MTP_DRIVE.REG             # My Computer shell namespace extension
├── DISABLE_SIGNING.REG       # Suppress driver signing dialogs
│
├── build_w2k_kmdf.bat        # Driver build script (KMDF 1.9, /GS-)
├── create_iso.ps1            # ISO image generator for VM deployment
├── create_two_releases.ps1   # Release package builder (BareMetal + QEMU)
├── create_release_zip.ps1    # Monolithic full release package builder
├── run_w2k_qemu.bat          # QEMU VM launcher with USB-MTP emulation
│
├── user_app/
│   ├── mtp_gui.c             # Native Win32 Explorer-style MTP file manager
│   ├── mtp_transfer.c        # CLI file transfer utility
│   ├── security_stub_um.c    # User-mode security cookie stub
│   └── build_gui_w2k.bat     # GUI/CLI build script
│
├── test_app/
│   ├── mtp_test.c            # CLI IOCTL diagnostic tool
│   ├── security_cookie.c     # Security cookie stub for test app
│   └── build_test.bat        # Diagnostic build script
│
└── .gitignore                # Excludes build artifacts, SDKs, screenshots
```

---

## Technical Details & Bug Fixes

### 1. BSOD Root Cause & Solution

In previous builds, the driver crashed with `BugCheck 0x1E: KMODE_EXCEPTION_NOT_HANDLED` (`0xC0000005` at `0x00000000`) inside `WdfDriverCreate`.

**Root cause:** The driver was linked with `/ENTRY:DriverEntry`, completely bypassing `WdfDriverEntry.lib`. Because `FxDriverEntry` was never called, `WDFLDR.SYS!WdfVersionBind` was never executed, leaving the `WdfFunctions` jump table populated entirely with `NULL` pointers.

**Fix:** Link with `/ENTRY:FxDriverEntry` and `/OSVERSION:5.0` against Windows 2000 DDK libraries and KMDF 1.9 stubs.

### 2. USB Pipe Reset Stalls

**Problem:** `WdfUsbTargetPipeResetSynchronously` sent `CLEAR_FEATURE(ENDPOINT_HALT)` control requests that caused virtual UHCI controllers and certain legacy hardware to stall.

**Fix:** Removed pipe reset calls during normal transfers, allowing bulk endpoints to stream data continuously.

### 3. 16 KB Transfer Chunking

**Problem:** Large buffer IRPs caused UHCI Transfer Descriptor ring exhaustion in `usbuhci.sys`.

**Fix:** All transfer loops break operations into 16 KB blocks with real-time cancellation support.

### 4. Dynamic Storage Capacity

**Problem:** Storage capacity was previously hardcoded.

**Fix:** `GetStorageInfo` (opcode `0x1005`) dynamically queries the actual device storage, supporting any capacity from 1 GB to 1 TB+.

### 5. Undecorated INF for Windows 2000

Windows 2000 SetupAPI does not recognize decorated `.NT`, `.NTx86`, or `.NT.5.1` sections. The INF uses clean undecorated `[MtpInstall]`, `[MfgSection]`, and `[MtpInstall.Services]` sections.

---

## License

This project is provided as-is for educational and research purposes. See individual component licenses for third-party dependencies.

---

## Verified Operations

| # | Operation | Result |
|:-:|:----------|:------:|
| 1 | Clean Desktop Boot | ✅ |
| 2 | Driver Deployment via SETUP.BAT | ✅ |
| 3 | Hardware Diagnostics (mtp_test.exe) | ✅ |
| 4 | Launch Explorer GUI | ✅ |
| 5 | Connect & List Files | ✅ |
| 6 | Refresh (F5) | ✅ |
| 7 | Download File | ✅ |
| 8 | Upload File | ✅ |
| 9 | Delete File | ✅ |
| 10 | Folder Navigation | ✅ |
| 11 | Address Bar Navigation | ✅ |
| 12 | Search (F3/Ctrl+F) | ✅ |
| 13 | About Dialog | ✅ |
| 14 | My Computer Integration | ✅ |
| 15 | Safe Remove & Reconnect | ✅ |
