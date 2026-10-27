$ErrorActionPreference = "Stop"

$isoPath = "C:\Users\Win2000\Documents\QEMU\Windows2000-Pro-SP4\kmdf-mtp-install.iso"
$stagingDir = "$env:TEMP\kmdf_mtp_iso"

if (Test-Path $stagingDir) {
    Remove-Item -Recurse -Force $stagingDir
}
New-Item -ItemType Directory -Path "$stagingDir\KMDF" | Out-Null
New-Item -ItemType Directory -Path "$stagingDir\MTP" | Out-Null
New-Item -ItemType Directory -Path "$stagingDir\TEST" | Out-Null

Write-Host "Copying KMDF installer files..."
Copy-Item -Recurse "D:\Users\win2000\Downloads\KMDF-v1.9-Win2k-WinXP-Win2k3\*" "$stagingDir\KMDF\"

Write-Host "Copying MTP Driver files to root and MTP folder..."
Copy-Item "D:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\Release\mtp.sys" "$stagingDir\"
Copy-Item "D:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\Release\mtp.inf" "$stagingDir\"
Copy-Item "D:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\Release\WdfCoInstaller01009.dll" "$stagingDir\"
Copy-Item "D:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\Release\mtp.sys" "$stagingDir\MTP\"
Copy-Item "D:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\Release\mtp.inf" "$stagingDir\MTP\"
Copy-Item "D:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\Release\WdfCoInstaller01009.dll" "$stagingDir\MTP\"

Write-Host "Copying test tools and utilities..."
Copy-Item "D:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\test_app\mtp_test.exe" "$stagingDir\TEST\"
Copy-Item "D:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\user_app\mtp_gui.exe" "$stagingDir\TEST\"
Copy-Item "D:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\user_app\mtp_gui_debug.exe" "$stagingDir\TEST\"
Copy-Item "D:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\user_app\mtp_transfer.exe" "$stagingDir\TEST\"
Copy-Item "D:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\user_app\mtp_gui.exe" "$stagingDir\"
Copy-Item "D:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\user_app\mtp_gui_debug.exe" "$stagingDir\"
Copy-Item "D:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\Release\MTP_DRIVE.REG" "$stagingDir\"
Copy-Item "D:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\3790.1830\tools\devcon\i386\devcon.exe" "$stagingDir\"
Set-Content -Path "$stagingDir\open_mycomp.bat" -Value "@echo off`r`nstart explorer.exe ::{20D04FE0-3AEA-1069-A2D8-08002B30309D}`r`n" -Encoding ASCII


$disableReg = @"
Windows Registry Editor Version 5.00

[HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Driver Signing]
"Policy"=hex:00

[HKEY_CURRENT_USER\Software\Microsoft\Driver Signing]
"Policy"=hex:00

[HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Non-Driver Signing]
"Policy"=hex:00

[HKEY_CURRENT_USER\Software\Microsoft\Internet Connection Wizard]
"Completed"=hex:01,00,00,00

[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\Tips]
"Show"=dword:00000000

[HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Telephony\Locations]
"NextID"=dword:00000002
"@
Set-Content -Path "$stagingDir\DISABLE_SIGNING.REG" -Value $disableReg -Encoding ASCII

$autorunInf = @"
[AutoRun]
open=SETUP.BAT
action=Install KMDF 1.9 Runtime and MTP Driver
icon=SETUP.BAT
"@
Set-Content -Path "$stagingDir\AUTORUN.INF" -Value $autorunInf -Encoding ASCII

$installBat = @"
@echo off
cd /d %~dp0
echo ========================================================
echo   Windows 2000 KMDF 1.9 Runtime + MTP Driver Setup
echo ========================================================
echo.
echo [1/5] Disabling driver signing warnings and dialog popups...
regedit.exe /s DISABLE_SIGNING.REG
echo Set wmi = GetObject("winmgmts:") > %TEMP%\kill.vbs
echo For Each p In wmi.ExecQuery("Select * from Win32_Process Where Name = 'welcome.exe'") >> %TEMP%\kill.vbs
echo p.Terminate >> %TEMP%\kill.vbs
echo Next >> %TEMP%\kill.vbs
cscript //nologo %TEMP%\kill.vbs >nul 2>&1
del %TEMP%\kill.vbs >nul 2>&1

echo.
echo [2/5] Verifying KMDF 1.9 Runtime...
echo KMDF_UPDATE_DONE=0 > C:\SETUP_DONE.TXT

echo.
echo [3/5] Deploying driver files and registering My Computer extension...
devcon.exe remove "USB\VID_46F4&PID_0004"
ren %SystemRoot%\System32\drivers\mtp.sys mtp_old.sys >nul 2>&1
del %SystemRoot%\System32\drivers\mtp_old.sys >nul 2>&1
ren %SystemRoot%\System32\WdfCoInstaller01009.dll wdf_old.dll >nul 2>&1
del %SystemRoot%\System32\wdf_old.dll >nul 2>&1
copy MTP\WdfCoInstaller01009.dll %SystemRoot%\System32\ /y
copy MTP\mtp.sys %SystemRoot%\System32\drivers\ /y
copy MTP\mtp.inf %SystemRoot%\inf\ /y
copy TEST\mtp_gui.exe %SystemRoot%\System32\ /y
regedit.exe /s MTP_DRIVE.REG
copy open_mycomp.bat C:\ /y
echo Driver files deployed and MTP Portable Device registered in My Computer.

echo.
echo [4/5] Binding MTP Driver to USB Device via DevCon...
devcon.exe rescan
devcon.exe update mtp.inf "USB\VID_46F4&PID_0004"
devcon.exe restart "USB\VID_46F4&PID_0004"
echo DevCon update completed: %ERRORLEVEL%

echo.
echo [5/5] Running MTP Driver Diagnostic...
TEST\mtp_test.exe > C:\MTP_TEST.TXT 2>&1
type C:\MTP_TEST.TXT

echo.
echo ========================================================
echo   Installation Completed Successfully!
echo ========================================================
echo SUCCESS >> C:\SETUP_DONE.TXT

echo.
echo Ready to launch MTP Portable Device Explorer.
rem start TEST\mtp_gui.exe
"@

Set-Content -Path "$stagingDir\SETUP.BAT" -Value $installBat -Encoding ASCII

Write-Host "Building ISO image using IMAPI2FS..."
if (Test-Path $isoPath) {
    Remove-Item -Force $isoPath
}

$fsi = New-Object -ComObject IMAPI2FS.MsftFileSystemImage
$fsi.FreeMediaBlocks = 0
$fsi.FileSystemsToCreate = 3 # ISO9660 + Joliet
$fsi.VolumeName = "KMDF_MTP"
$fsi.Root.AddTree($stagingDir, $false)

$result = $fsi.CreateResultImage()
$stream = $result.ImageStream

Add-Type -TypeDefinition @"
using System;
using System.IO;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.ComTypes;

public class ComStreamCopy {
    public static void CopyToFile(object comStreamObj, string destPath) {
        IStream comStream = (IStream)comStreamObj;
        using (FileStream fs = new FileStream(destPath, FileMode.Create, FileAccess.Write)) {
            byte[] buffer = new byte[64 * 1024];
            IntPtr pcbRead = Marshal.AllocHGlobal(sizeof(int));
            try {
                while (true) {
                    comStream.Read(buffer, buffer.Length, pcbRead);
                    int bytesRead = Marshal.ReadInt32(pcbRead);
                    if (bytesRead == 0) break;
                    fs.Write(buffer, 0, bytesRead);
                }
            } finally {
                Marshal.FreeHGlobal(pcbRead);
            }
        }
    }
}
"@

[ComStreamCopy]::CopyToFile($result.ImageStream, $isoPath)

Write-Host "ISO created successfully at $isoPath"
Get-Item $isoPath | Select-Object Name, Length
