# MTP File Transfer Application for Windows 2000

This is a user-mode application that communicates with the MTP KMDF driver
to browse and transfer files between a Windows 2000 PC and MTP devices
(smartphones, digital cameras, etc.).

## Features

- **Interactive Mode**: Menu-driven interface for browsing and file transfer
- **Command-Line Mode**: Scriptable commands for automation
- **Device Info**: Retrieve MTP device information
- **Storage Listing**: List available storage volumes on the device
- **Object Browsing**: List files and folders on the device
- **File Download**: Transfer files from device to PC
- **File Upload**: Transfer files from PC to device

## Building

### Prerequisites

1. Windows 2000 SDK (included in workspace at `2000 sdk` folder)
2. Visual C++ 6.0 or compatible compiler
3. Run from DDK/SDK command prompt with environment set up

### Compilation

```batch
cd user_app
build.bat
```

Or manually compile:

```batch
cl /O2 /W3 /D_WIN32_WINNT=0x0500 mtp_transfer.c /link kernel32.lib user32.lib
```

## Usage

### Interactive Mode

```batch
mtp_transfer.exe
```

This starts an interactive menu where you can:
1. Open an MTP session with the device
2. Browse device info and storage
3. List files and folders
4. Download and upload files
5. Close the session

### Command-Line Mode

**List all objects:**
```batch
mtp_transfer.exe list
```

**Get info about a specific object:**
```batch
mtp_transfer.exe info <handle>
```
Example: `mtp_transfer.exe info 0x00000001`

**Download a file:**
```batch
mtp_transfer.exe download <handle> <local_filename>
```
Example: `mtp_transfer.exe download 0x00000005 photo.jpg`

**Upload a file:**
```batch
mtp_transfer.exe upload <local_filename>
```
Example: `mtp_transfer.exe upload document.txt`

### Options

- `-d <device>` - Use a custom device name (default: `\\.\MtpDevice`)
- `-h` - Show help

## Requirements

1. **MTP Driver**: The MTP KMDF driver (`mtp.sys`) must be installed
2. **Device Connected**: An MTP-compatible device must be connected via USB
3. **KMDF Runtime**: WdfCoInstaller01009.dll must be installed (for KMDF 1.9)

## MTP Operations Used

| Operation | Code | Description |
|-----------|------|-------------|
| GetDeviceInfo | 0x1001 | Get device capabilities and info |
| OpenSession | 0x1002 | Open MTP session |
| CloseSession | 0x1003 | Close MTP session |
| GetStorageIDs | 0x1004 | List storage volumes |
| GetObjectHandles | 0x1007 | List object handles |
| GetObjectInfo | 0x1008 | Get object metadata |
| GetObject | 0x1009 | Download object data |
| SendObjectInfo | 0x100C | Send object metadata |
| SendObject | 0x100D | Upload object data |

## IOCTLs Used

| IOCTL | Code | Description |
|-------|------|-------------|
| IOCTL_MTP_GET_DEVICE_INFO | 0x800 | Get device info |
| IOCTL_MTP_LIST_OBJECTS | 0x801 | List objects |
| IOCTL_MTP_GET_OBJECT_PART | 0x802 | Download chunk |
| IOCTL_MTP_SEND_OBJECT_PART | 0x803 | Upload chunk |
| IOCTL_MTP_SESSION_OPEN | 0x810 | Open session |
| IOCTL_MTP_SESSION_CLOSE | 0x811 | Close session |
| IOCTL_MTP_OPERATION | 0x812 | Generic operation |

## Troubleshooting

### "Failed to open device"

- Ensure the MTP driver is installed (`mtp.sys` loaded)
- Check device is connected and recognized by Windows
- Run the application as Administrator if needed

### "Failed to open MTP session"

- Device may be busy (close other MTP applications)
- Try disconnecting and reconnecting the device
- Check device is in MTP mode (not PTP or Mass Storage)

### Slow transfers

- MTP has higher overhead than Mass Storage
- Large files are transferred in chunks for reliability
- USB 1.1 ports will be significantly slower than USB 2.0

## File Format Support

The application displays the MTP format code for each object:
- **0x3001** - Folder (Association)
- **0x3008** - WAV Audio
- **0x3009** - MP3 Audio  
- **0x300B** - MPEG Video
- **0x3801** - JPEG Image
- **0x380B** - PNG Image
- **0xB901** - WMA Audio
- **0xB981** - WMV Video

## License

This software is provided for educational and development purposes.
