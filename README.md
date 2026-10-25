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
- **Web View sidebar** with file preview thumbnails, metadata panel, and live storage capacity meter
- **Address bar navigation** with editable path and Go button
- **Intelligent recursive search engine** (`F3` / `Ctrl+F` / `/search` CLI flag):
  - Fast breadth-first recursive tree traversal across nested folders
  - Multi-pattern wildcard matching (`*.jpg;*.png`, `*test*`, `?`)
  - File category filters (Photos, Music, Videos, Documents, Folders)
  - Subfolder recursion toggle
  - Dedicated keyboard support: <kbd>Enter</kbd> to Find Now, <kbd>Esc</kbd> to dismiss, <kbd>Alt+N</kbd> New Search with auto-selection
  - Jump directly to selected file location via "Open Containing Folder"
- **64-bit large capacity & file support:** Full support for modern 256 GB, 512 GB, and 1 TB+ smartphone storage via 64-bit integer math (`UINT64` capacity and `0xDC04` MTP property)
- **File operations:** Upload (`Ctrl+U` or Drag-and-Drop), Download (`Ctrl+S`), Delete (`Del`), Refresh (`F5`)
- **Clipboard operations:** Cut (`Ctrl+X`), Copy (`Ctrl+C`), Paste (`Ctrl+V`) with taskbar balloon notifications
- **My Computer integration** via shell namespace extension (`MTP_DRIVE.REG`)
- **Folder Options dialog** for customizing toolbar, status bar, and notification behavior

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
| `Win2000-MTP-KMDF-Driver-Release.zip` | Complete driver + GUI + CLI tools + KMDF runtime + install ISO |
| `Win2000-MTP-Release-BareMetal.zip` | Deployment files for physical bare-metal hardware |
| `Win2000-MTP-Release-QEMU-VM.zip` | QEMU VM test image with ISO and driver setup |

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
- Real-time device storage capacity meter (dynamically queried from device, supports > 256 GB)
- Standard Explorer toolbar: Back, Forward, Up, Connect, Disconnect, Refresh, Download, Upload, Delete, Search, Views
- Address bar with editable path and Go button

**Intelligent Search Engine (F3 / Ctrl+F / /search):**
- Breadth-first recursive traversal of MTP object tree across all nested directories
- Wildcard pattern matching (`*`, `?`) with semicolon-separated multi-pattern support
- Category filters: All Files (`*.*`), Pictures (`*.jpg;*.png;*.webp`), Music (`*.mp3;*.wma`), Video (`*.mp4;*.avi`), Documents (`*.txt;*.doc;*.pdf`), Folders Only
- Include/exclude subfolders toggle
- Full keyboard integration:
  - <kbd>Enter</kbd> in search query box triggers Find Now immediately
  - <kbd>Alt+N</kbd> (New Search) resets criteria and highlights query box with `EM_SETSEL`
  - <kbd>Alt+O</kbd> opens the containing folder of the selected search result in the main Explorer view
  - <kbd>Esc</kbd> closes search dialog
- Status bar displays real-time search state, number of matches found, and total objects scanned
- Cancel support with responsive Stop button

**Command-Line Switches:**
```cmd
mtp_gui.exe           :: Normal startup (auto-connects to MTP device)
mtp_gui.exe /search   :: Auto-connects and directly launches Search dialog
mtp_gui.exe /noconnect:: Launches without automatic connection (manual mode)
```

**Keyboard Shortcuts:**
| Shortcut | Action |
|:---------|:-------|
| `Ctrl+O` | Connect to device |
| `Ctrl+D` | Disconnect (Safely Remove) |
| `Ctrl+S` | Download selected file |
| `Ctrl+U` | Upload file to device |
| `Del` | Delete selected file |
| `F5` | Refresh file list |
| `F3` / `Ctrl+F` | Find Files or Folders dialog |
| `Alt+Left` / `Backspace` | Navigate Back |
| `Alt+Right` | Navigate Forward |
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

### 4. Dynamic Storage Capacity & 64-Bit Math (> 256 GB up to 2 TB)

**Problem:** Standard 32-bit integers overflow on modern smartphones with 256 GB, 512 GB, or 1 TB+ storage capacities, causing negative numbers or truncated free space.

**Fix:** `GetStorageInfo` (opcode `0x1005`) uses 64-bit unsigned integers (`UINT64` `MaxCapacity`, `FreeSpaceInBytes`). For files larger than 4 GB, `GetObjectInfo` reports `0xFFFFFFFF` in the 32-bit size field, and the GUI queries MTP property `0xDC04` (`MTP_PROPERTY_OBJECT_SIZE_64`) via opcode `0x9803` (`GetObjectPropValue`) to retrieve the full 64-bit file size.

### 5. Undecorated INF for Windows 2000

Windows 2000 SetupAPI does not recognize decorated `.NT`, `.NTx86`, or `.NT.5.1` sections. The INF uses clean undecorated `[MtpInstall]`, `[MfgSection]`, and `[MtpInstall.Services]` sections.

### 6. Native Windows Search vs. MTP GUI Search Architecture

**Problem:** In Windows 2000, pressing `F3` on the desktop launches the native shell Search window (`Search Results`), but it cannot find any files on the MTP smartphone.

**Reason:** Windows 2000 Explorer Search relies exclusively on mounted DOS block drive letters (`C:\`, `D:\`) or local NTFS/FAT file systems. MTP is an object/transaction protocol where files are referenced by 32-bit handles rather than disk sectors.

**Solution:** `mtp_gui.exe` provides a native Windows 2000 Search window (`Find: Files or Folders on Portable Device`) that communicates directly with `mtp.sys` via IOCTLs, using a multi-threaded breadth-first traversal queue to recursively scan the device hierarchy.

### 7. Search Dialog Message Routing & Enter Key Subclassing

**Problem:** When pressing <kbd>Enter</kbd> in the search edit box, `IsDialogMessage` or default edit controls consume `VK_RETURN` or swallow `WM_CHAR`, failing to start the search.

**Fix:**
- `SearchEditSubclassProc` handles `WM_GETDLGCODE` and returns `DLGC_WANTALLKEYS | DLGC_WANTCHARS` so `IsDialogMessage` does not intercept navigation keys.
- `WM_KEYDOWN` for `VK_RETURN` triggers `IDC_SEARCH_BTN_FINDNOW` immediately.
- `SearchWndProc` responds to `DM_GETDEFID` with `MAKELRESULT(IDC_SEARCH_BTN_FINDNOW, DC_HASDEFID)` and maps standard `IDOK` commands to `IDC_SEARCH_BTN_FINDNOW`.
- `EM_SETSEL(0, -1)` automatically selects the query text upon "New Search" for rapid keyword replacement.

---

## License

This project is provided as-is for educational and research purposes. See individual component licenses for third-party dependencies.

---

## Verified Operations (100% Passing in Live QEMU)

| # | Operation | Result | Timestamp / Verification |
|:-:|:----------|:------:|:------------------------|
| 1 | Clean Desktop Boot | ✅ | Verified at 10:32:40 |
| 2 | Driver Deployment via SETUP.BAT | ✅ | Verified with DevCon & KMDF runtime |
| 3 | Hardware Diagnostics (mtp_test.exe) | ✅ | DeviceInfo, Session, Object handles PASS |
| 4 | Launch Explorer GUI (mtp_gui.exe) | ✅ | Authentic Win2K Explorer layout |
| 5 | Connect & List Files (Ctrl+O) | ✅ | Internal Storage root enumerated |
| 6 | Refresh (F5) | ✅ | Real-time device re-query |
| 7 | Download File (Ctrl+S) | ✅ | 16 KB chunked bulk stream |
| 8 | Upload File (Ctrl+U / Drag & Drop) | ✅ | Write streaming to device store |
| 9 | Delete File (Del) | ✅ | `DeleteObject` opcode execution |
| 10 | Folder Navigation | ✅ | In/out directory traversal |
| 11 | Address Bar Navigation | ✅ | Direct path entry & Go button |
| 12 | Recursive Search All Items (`*`) | ✅ | Found all files across nested folders (`\DCIM`, `\Music`) |
| 13 | Photo Wildcard Filter (`*.jpg`) | ✅ | Matched `photo1.jpg` in `\DCIM` subfolder |
| 14 | Document Filter (`*.txt`) | ✅ | Matched `Welcome_Phone.txt` & `notes.txt` |
| 15 | Open Containing Folder (Alt+O) | ✅ | Result selection & jump navigation |
| 16 | Direct Search Launch (`/search`) | ✅ | Immediate Search dialog on startup |
| 17 | About Dialog & Storage Meter | ✅ | 64-bit capacity reporting (> 256 GB) |
| 18 | My Computer Integration | ✅ | Portable Device icon via `MTP_DRIVE.REG` |
| 19 | Safe Remove & Reconnect | ✅ | Balloon notifications & hardware deload |
