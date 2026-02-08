================================================================================
  MTP KMDF Driver - User Mode Test Application
  Windows 2000 Compatible
================================================================================

QUICK START
-----------
1. Double-click: build_test.bat
2. Run: mtp_test.exe

This will test the MTP driver by sending IOCTLs:
  - Get Device Info
  - Open MTP Session
  - List Objects
  - Close Session

REQUIREMENTS
------------
- MTP driver (mtp.sys) must be installed and device connected
- Windows 2000 SDK (already configured)
- Visual C++ compiler (from Windows 2000 SDK or DDK)

USAGE
-----
Default device name:
  mtp_test.exe

Custom device name:
  mtp_test.exe \\.\YourDeviceName

OUTPUT
------
The test app will:
  - Open the driver device
  - Send test IOCTLs
  - Display responses in hex format
  - Show success/failure for each test
  - Print error codes if operations fail

TROUBLESHOOTING
---------------
"Failed to open device" errors:
  - Check driver is installed: Device Manager
  - Verify device name matches driver's symbolic link
  - Ensure phone is connected via USB
  - Check driver is started (sc query mtp)

"DeviceIoControl failed" errors:
  - Use DebugView to see driver KdPrint messages
  - Check if phone supports MTP protocol
  - Verify IOCTL codes match driver's Mtp.h

DEVICE NAME
-----------
The device name depends on how the driver creates symbolic link.
Check Device.c -> MtpEvtDeviceAdd() for the actual device name.

Common names:
  \\.\MtpDevice
  \\.\Global\MtpDevice
  \\.\PhysicalDrive0  (if using default)

TESTING FLOW
------------
1. Build test app: build_test.bat
2. Install driver: Copy mtp.sys to system32\drivers
3. Install INF file (if you have one)
4. Connect phone
5. Run: mtp_test.exe
6. Watch output and DebugView for debug logs

================================================================================
