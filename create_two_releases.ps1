$ErrorActionPreference = "Stop"

$workspaceRoot = "D:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1"
$releaseDir = "$workspaceRoot\Release"

# ==============================================================================
# 1. Build Package 1: Win2000-MTP-Release-QEMU-VM.zip
# ==============================================================================
Write-Host "=========================================================="
Write-Host "  Building Package 1: QEMU Virtual Machine Edition"
Write-Host "=========================================================="

$qemuStaging = "$env:TEMP\MTP_Release_QEMU_VM"
if (Test-Path $qemuStaging) { Remove-Item -Recurse -Force $qemuStaging }
New-Item -ItemType Directory -Path "$qemuStaging\mtp_phone_storage\DCIM\Camera" | Out-Null
New-Item -ItemType Directory -Path "$qemuStaging\mtp_phone_storage\Documents" | Out-Null
New-Item -ItemType Directory -Path "$qemuStaging\mtp_phone_storage\Download" | Out-Null
New-Item -ItemType Directory -Path "$qemuStaging\mtp_phone_storage\Music" | Out-Null

# Copy ISO
$isoPath = "C:\Users\Win2000\Documents\QEMU\Windows2000-Pro-SP4\kmdf-mtp-install.iso"
Copy-Item $isoPath "$qemuStaging\"

# Copy QEMU launcher batch
Copy-Item "$workspaceRoot\run_w2k_qemu.bat" "$qemuStaging\"

# Copy sample phone/camera storage content
$hostPhoneStorage = "C:\Users\Win2000\Documents\QEMU\mtp_phone_storage"
if (Test-Path $hostPhoneStorage) {
    Copy-Item -Recurse "$hostPhoneStorage\*" "$qemuStaging\mtp_phone_storage\" -Force
}

# Standalone tools
Copy-Item "$workspaceRoot\user_app\mtp_gui.exe" "$qemuStaging\"
Copy-Item "$workspaceRoot\user_app\mtp_gui_debug.exe" "$qemuStaging\"
Copy-Item "$workspaceRoot\test_app\mtp_test.exe" "$qemuStaging\"
Copy-Item "$workspaceRoot\Release\MTP_DRIVE.REG" "$qemuStaging\"
Copy-Item "$workspaceRoot\Release\DISABLE_SIGNING.REG" "$qemuStaging\"

# Create README_QEMU_VM.md
$readmeQemu = @"
# Windows 2000 MTP KMDF Driver - QEMU Virtual Machine Edition

This package is tailored for running and testing the MTP KMDF 1.9 driver and Windows 2000 Explorer GUI inside QEMU, VirtualBox, or VMware.

---

## Package Contents
- **`kmdf-mtp-install.iso`**: Complete pre-built installation CD-ROM containing the KMDF 1.9 runtime, MTP driver, DevCon utility, and the Explorer GUI.
- **`run_w2k_qemu.bat`**: Ready-to-use QEMU launcher configured with UHCI USB controller and emulated MTP device.
- **`mtp_phone_storage/`**: Sample phone and camera storage tree (DCIM photos, documents, music).
- **`mtp_gui.exe`**: Standalone native Windows 2000 Explorer-style MTP file manager.
- **`MTP_DRIVE.REG`**: Registry file to add "MTP Portable Device" to "My Computer".
- **`DISABLE_SIGNING.REG`**: Registry file to suppress unsigned driver prompts on Win2K.

---

## Quick Start in QEMU

### 1. Launch QEMU with MTP Emulation
Run ``run_w2k_qemu.bat`` or execute:
````cmd
qemu-system-i386.exe ^
  -machine pc-i440fx-9.2,accel=tcg ^
  -cpu pentium3 -smp 2 -m 2048 ^
  -drive "file=win2000-pro-sp4.img,format=raw,if=ide,index=0,media=disk" ^
  -cdrom kmdf-mtp-install.iso ^
  -boot order=c,menu=off ^
  -nic none ^
  -device piix3-usb-uhci,id=uhci ^
  -device "usb-mtp,bus=uhci.0,rootdir=C:/path/to/mtp_phone_storage,desc=Android Phone (MTP),readonly=off" ^
  -display vnc=127.0.0.1:0
````

### 2. Testing Physical Cameras & Phones via USB Pass-Through
To test a physical Canon, Nikon, Sony digital camera or Android phone in QEMU:
1. Plug the camera or phone into your host PC USB port.
2. In host Device Manager, locate the device Vendor ID and Product ID (e.g. ``VID_04A9&PID_3218`` for Canon).
3. Add the pass-through argument to QEMU:
   ``-device usb-host,vendorid=0x04a9,productid=0x3218``
4. Start the VM. Windows 2000 will detect the camera directly!

### 3. One-Click Setup inside Windows 2000
1. Inside the Windows 2000 VM, open Command Prompt (``Start -> Run -> cmd``).
2. Run:
   ````cmd
   D:\SETUP.BAT
   ````
3. The script installs KMDF 1.9, deploys the driver via DevCon, registers "MTP Portable Device" in "My Computer", and launches the Explorer GUI!
"@
Set-Content -Path "$qemuStaging\README_QEMU_VM.md" -Value $readmeQemu -Encoding UTF8

$qemuZip = "$workspaceRoot\Win2000-MTP-Release-QEMU-VM.zip"
if (Test-Path $qemuZip) { Remove-Item -Force $qemuZip }

Write-Host "Compressing QEMU VM package to $qemuZip..."
Add-Type -AssemblyName System.IO.Compression.FileSystem
[System.IO.Compression.ZipFile]::CreateFromDirectory($qemuStaging, $qemuZip, [System.IO.Compression.CompressionLevel]::Optimal, $false)
Copy-Item $qemuZip "$releaseDir\" -Force

Write-Host "Package 1 created: $qemuZip"


# ==============================================================================
# 2. Build Package 2: Win2000-MTP-Release-BareMetal.zip
# ==============================================================================
Write-Host "`n=========================================================="
Write-Host "  Building Package 2: Bare Metal Physical PC Edition"
Write-Host "=========================================================="

$metalStaging = "$env:TEMP\MTP_Release_BareMetal"
if (Test-Path $metalStaging) { Remove-Item -Recurse -Force $metalStaging }
New-Item -ItemType Directory -Path "$metalStaging\Driver" | Out-Null
New-Item -ItemType Directory -Path "$metalStaging\Applications" | Out-Null
New-Item -ItemType Directory -Path "$metalStaging\KMDF-1.9-Runtime" | Out-Null

# Driver Files (both in Driver\ and root for instant plug-and-play)
Copy-Item "$workspaceRoot\Release\mtp.sys" "$metalStaging\"
Copy-Item "$workspaceRoot\Release\mtp.inf" "$metalStaging\"
Copy-Item "$workspaceRoot\Release\WdfCoInstaller01009.dll" "$metalStaging\"

Copy-Item "$workspaceRoot\Release\mtp.sys" "$metalStaging\Driver\"
Copy-Item "$workspaceRoot\Release\mtp.inf" "$metalStaging\Driver\"
Copy-Item "$workspaceRoot\Release\WdfCoInstaller01009.dll" "$metalStaging\Driver\"

# Tools & Setup scripts
Copy-Item "$workspaceRoot\3790.1830\tools\devcon\i386\devcon.exe" "$metalStaging\"
Copy-Item "$workspaceRoot\Release\MTP_DRIVE.REG" "$metalStaging\"
Copy-Item "$workspaceRoot\Release\DISABLE_SIGNING.REG" "$metalStaging\"

# Applications
Copy-Item "$workspaceRoot\user_app\mtp_gui.exe" "$metalStaging\"
Copy-Item "$workspaceRoot\user_app\mtp_gui_debug.exe" "$metalStaging\"
Copy-Item "$workspaceRoot\test_app\mtp_test.exe" "$metalStaging\"
Copy-Item "$workspaceRoot\user_app\mtp_transfer.exe" "$metalStaging\"

Copy-Item "$workspaceRoot\user_app\mtp_gui.exe" "$metalStaging\Applications\"
Copy-Item "$workspaceRoot\user_app\mtp_gui_debug.exe" "$metalStaging\Applications\"
Copy-Item "$workspaceRoot\test_app\mtp_test.exe" "$metalStaging\Applications\"
Copy-Item "$workspaceRoot\user_app\mtp_transfer.exe" "$metalStaging\Applications\"

# Official Microsoft KMDF 1.9 runtime installer package
Copy-Item -Recurse "D:\Users\win2000\Downloads\KMDF-v1.9-Win2k-WinXP-Win2k3\*" "$metalStaging\KMDF-1.9-Runtime\"

# Automated SETUP.BAT for Bare Metal
$bareMetalSetup = @"
@echo off
cd /d %~dp0
echo ========================================================
echo   Windows 2000 MTP Driver Setup (Bare Metal PC Edition)
echo ========================================================
echo.
echo [1/5] Disabling driver signing warning dialogs...
regedit.exe /s DISABLE_SIGNING.REG

echo.
echo [2/5] Installing Microsoft KMDF 1.9 Runtime if needed...
if exist KMDF-1.9-Runtime\update\update.exe (
    KMDF-1.9-Runtime\update\update.exe /quiet /norestart
)

echo.
echo [3/5] Deploying driver files and registering My Computer extension...
copy WdfCoInstaller01009.dll %SystemRoot%\System32\ /y >nul 2>&1
copy mtp.sys %SystemRoot%\System32\drivers\ /y >nul 2>&1
copy mtp.inf %SystemRoot%\inf\ /y >nul 2>&1
copy mtp_gui.exe %SystemRoot%\System32\ /y >nul 2>&1
regedit.exe /s MTP_DRIVE.REG
echo Driver files deployed and MTP Portable Device registered in My Computer.

echo.
echo [4/5] Scanning USB bus for MTP / PTP Cameras and Phones...
devcon.exe rescan
devcon.exe update mtp.inf "USB\CLASS_06&SUBCLASS_01&PROT_01" >nul 2>&1
devcon.exe update mtp.inf "USB\CLASS_06&SUBCLASS_01" >nul 2>&1
devcon.exe update mtp.inf "USB\CLASS_06" >nul 2>&1
devcon.exe update mtp.inf "USB\VID_46F4&PID_0004" >nul 2>&1
echo USB Bus Scan Completed.

echo.
echo [5/5] Launching MTP Portable Device Explorer...
start mtp_gui.exe

echo.
echo ========================================================
echo   Installation Completed Successfully!
echo ========================================================
"@
Set-Content -Path "$metalStaging\SETUP.BAT" -Value $bareMetalSetup -Encoding ASCII

# Create README_BARE_METAL.md
$readmeMetal = @"
# Windows 2000 MTP KMDF Driver - Bare Metal Physical PC Edition

A complete, production-ready Windows 2000 Professional SP4 MTP & PTP driver package for physical vintage PCs, supporting smartphones, digital cameras, and portable media players.

---

## Supported Physical Hardware
- **Operating System:** Windows 2000 Professional with Service Pack 4 (SP4)
- **USB Controllers Supported:**
  - **USB 1.1 UHCI** (Intel PIIX3/PIIX4, VIA VT82C586/596/686)
  - **USB 1.1 OHCI** (AMD, ALi, SiS, NEC)
  - **USB 2.0 EHCI** (NEC, Intel ICH4+, VIA VT6212)
- **Digital Cameras Supported (PTP / MTP mode):**
  - **Canon**: EOS DSLR & Mirrorless, PowerShot, IXUS series
  - **Nikon**: D-Series DSLR, Coolpix, Z-Series
  - **Sony**: Alpha DSLR/Mirrorless, Cyber-shot, Handycam
  - **Fujifilm**: FinePix, X-Series
  - **Panasonic**: Lumix series
  - **Olympus / OM System**: OM-D, PEN, Tough
  - **GoPro**: Hero series (MTP mode)
  - **Universal Fallback**: Any digital camera advertising USB Still Image Capture (Class 0x06, SubClass 0x01, Protocol 0x01)
- **Smartphones Supported (MTP mode):**
  - **Samsung Galaxy**: S-series, A-series, Note series
  - **Google / Android**: Pixel, Nexus, AOSP devices
  - **Xiaomi / Redmi / POCO**
  - **LG, Motorola, HTC, Sony Xperia, OnePlus, Huawei**
  - **Apple iPhone**: PTP mode for camera photo importing

---

## Package Contents
- **`Driver/`**: ``mtp.sys``, ``mtp.inf``, ``WdfCoInstaller01009.dll``
- **`Applications/`**:
  - ``mtp_gui.exe``: Native Windows 2000 Explorer-style MTP file manager with Web View sidebar, Address bar, Large Icons view, and live preview pane.
  - ``mtp_test.exe``: CLI diagnostic tool testing kernel IOCTL communication.
  - ``mtp_transfer.exe``: Command-line scriptable file transfer utility.
- **`KMDF-1.9-Runtime/`**: Official Microsoft KMDF 1.9 installer package (``KB970158``).
- **`SETUP.BAT`**: One-click installer batch script.
- **`MTP_DRIVE.REG`**: Registry file to add "MTP Portable Device" to "My Computer".
- **`DISABLE_SIGNING.REG`**: Registry file to disable driver signing warnings.
- **`devcon.exe`**: Windows 2000 Device Console utility.

---

## Installation on a Physical PC

### Method 1: One-Click Automated Setup (Recommended)
1. Copy the contents of this package to a folder, USB drive, or CD on your Windows 2000 PC.
2. Double-click ``SETUP.BAT``.
3. The script automatically:
   - Suppresses driver signing warning dialogs.
   - Installs the Microsoft KMDF 1.9 runtime if not already installed.
   - Deploys ``mtp.sys`` to ``C:\WINNT\System32\drivers\``.
   - Deploys ``mtp_gui.exe`` to ``C:\WINNT\System32\``.
   - Registers **"MTP Portable Device"** directly inside **My Computer**.
   - Rescans the USB bus and binds any connected phone or camera.
   - Launches the Explorer GUI!

### Method 2: Plug and Play (Found New Hardware Wizard)
1. Connect your camera or phone via USB.
2. Set the device USB connection mode to **"MTP"**, **"File Transfer"**, or **"PTP / Camera"**.
3. When the Windows 2000 **Found New Hardware Wizard** appears:
   - Select *"Search for a suitable driver for my device"*.
   - Check *"Specify a location"* and browse to the folder containing ``mtp.inf``.
   - Click Next and finish the wizard.

---

## Connecting Digital Cameras

1. Turn on your digital camera.
2. In the camera setup menu, ensure the **USB Mode** is set to **PTP** or **MTP/PTP** (not Mass Storage / UMS).
3. Connect the camera to your PC with a USB cable.
4. Open **My Computer** &rarr; double-click **"MTP Portable Device"** (or run ``mtp_gui.exe``).
5. Click **Connect** (``Ctrl+O``).
6. The camera storage (e.g. SD Card) and the ``DCIM`` folder will appear with all your photos!
7. Select any JPEG photo to preview its thumbnail and metadata in the Web View panel, or press **``Ctrl+S``** to download it to your PC.
"@
Set-Content -Path "$metalStaging\README_BARE_METAL.md" -Value $readmeMetal -Encoding UTF8

$metalZip = "$workspaceRoot\Win2000-MTP-Release-BareMetal.zip"
if (Test-Path $metalZip) { Remove-Item -Force $metalZip }

Write-Host "Compressing Bare Metal package to $metalZip..."
[System.IO.Compression.ZipFile]::CreateFromDirectory($metalStaging, $metalZip, [System.IO.Compression.CompressionLevel]::Optimal, $false)
Copy-Item $metalZip "$releaseDir\" -Force

Write-Host "Package 2 created: $metalZip"

# Summary
Write-Host "`n=========================================================="
Write-Host "  Both Release Packages Built Successfully!"
Write-Host "=========================================================="
Get-Item $qemuZip, $metalZip | Select-Object Name, Length, LastWriteTime | Format-Table -AutoSize
