$ErrorActionPreference = "Stop"

$workspaceRoot = "D:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1"
$staging = "$env:TEMP\MTP_Release_Package"

if (Test-Path $staging) {
    Remove-Item -Recurse -Force $staging
}
New-Item -ItemType Directory -Path "$staging\MTP" | Out-Null
New-Item -ItemType Directory -Path "$staging\TEST" | Out-Null
New-Item -ItemType Directory -Path "$staging\KMDF" | Out-Null

Write-Host "Staging driver files..."
Copy-Item "$workspaceRoot\Release\mtp.sys" "$staging\"
Copy-Item "$workspaceRoot\Release\mtp.inf" "$staging\"
Copy-Item "$workspaceRoot\Release\WdfCoInstaller01009.dll" "$staging\"
Copy-Item "$workspaceRoot\Release\mtp.sys" "$staging\MTP\"
Copy-Item "$workspaceRoot\Release\mtp.inf" "$staging\MTP\"
Copy-Item "$workspaceRoot\Release\WdfCoInstaller01009.dll" "$staging\MTP\"

Write-Host "Staging tools and applications..."
Copy-Item "$workspaceRoot\user_app\mtp_gui.exe" "$staging\"
Copy-Item "$workspaceRoot\user_app\mtp_gui_debug.exe" "$staging\"
Copy-Item "$workspaceRoot\test_app\mtp_test.exe" "$staging\"
Copy-Item "$workspaceRoot\user_app\mtp_transfer.exe" "$staging\"
Copy-Item "$workspaceRoot\user_app\mtp_gui.exe" "$staging\TEST\"
Copy-Item "$workspaceRoot\user_app\mtp_gui_debug.exe" "$staging\TEST\"
Copy-Item "$workspaceRoot\test_app\mtp_test.exe" "$staging\TEST\"
Copy-Item "$workspaceRoot\user_app\mtp_transfer.exe" "$staging\TEST\"
Copy-Item "$workspaceRoot\Release\MTP_DRIVE.REG" "$staging\"
Copy-Item "$workspaceRoot\3790.1830\tools\devcon\i386\devcon.exe" "$staging\"

Write-Host "Staging KMDF installer files..."
Copy-Item -Recurse "D:\Users\win2000\Downloads\KMDF-v1.9-Win2k-WinXP-Win2k3\*" "$staging\KMDF\"

Write-Host "Staging ISO image..."
$isoFile = "C:\Users\Win2000\Documents\QEMU\Windows2000-Pro-SP4\kmdf-mtp-install.iso"
if (Test-Path $isoFile) {
    Copy-Item $isoFile "$staging\"
}

Write-Host "Staging documentation..."
Copy-Item "$workspaceRoot\README.md" "$staging\"

Write-Host "Creating SETUP.BAT and DISABLE_SIGNING.REG..."
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
Set-Content -Path "$staging\DISABLE_SIGNING.REG" -Value $disableReg -Encoding ASCII

$autorunInf = @"
[AutoRun]
open=SETUP.BAT
action=Install KMDF 1.9 Runtime and MTP Driver
icon=SETUP.BAT
"@
Set-Content -Path "$staging\AUTORUN.INF" -Value $autorunInf -Encoding ASCII

$setupBat = @"
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
echo [2/5] Installing KMDF 1.9 Runtime if needed...
if exist KMDF\update\update.exe (
    KMDF\update\update.exe /quiet /norestart
)
echo KMDF_UPDATE_DONE=0 > C:\SETUP_DONE.TXT

echo.
echo [3/5] Deploying driver files and registering My Computer extension...
devcon.exe remove "USB\VID_46F4&PID_0004" >nul 2>&1
ren %SystemRoot%\System32\drivers\mtp.sys mtp_old.sys >nul 2>&1
del %SystemRoot%\System32\drivers\mtp_old.sys >nul 2>&1
ren %SystemRoot%\System32\WdfCoInstaller01009.dll wdf_old.dll >nul 2>&1
del %SystemRoot%\System32\wdf_old.dll >nul 2>&1
copy WdfCoInstaller01009.dll %SystemRoot%\System32\ /y
copy mtp.sys %SystemRoot%\System32\drivers\ /y
copy mtp.inf %SystemRoot%\inf\ /y
copy mtp_gui.exe %SystemRoot%\System32\ /y
regedit.exe /s MTP_DRIVE.REG
echo Driver files deployed and MTP Portable Device registered in My Computer.

echo.
echo [4/5] Binding MTP Driver to USB Device via DevCon...
devcon.exe rescan
devcon.exe update mtp.inf "USB\VID_46F4&PID_0004"
devcon.exe restart "USB\VID_46F4&PID_0004"
echo DevCon update completed: %ERRORLEVEL%

echo.
echo [5/5] Running MTP Driver Diagnostic...
if exist mtp_test.exe (
    mtp_test.exe > C:\MTP_TEST.TXT 2>&1
    type C:\MTP_TEST.TXT
)

echo.
echo ========================================================
echo   Installation Completed Successfully!
echo ========================================================
echo SUCCESS >> C:\SETUP_DONE.TXT

echo.
echo Launching MTP Portable Device Explorer...
if exist mtp_gui.exe (
    start mtp_gui.exe
) else if exist TEST\mtp_gui.exe (
    start TEST\mtp_gui.exe
)
"@
Set-Content -Path "$staging\SETUP.BAT" -Value $setupBat -Encoding ASCII

$zipDest = "$workspaceRoot\Win2000-MTP-KMDF-Driver-Release.zip"
if (Test-Path $zipDest) {
    Remove-Item -Force $zipDest
}

Write-Host "Compressing release package to $zipDest..."
Add-Type -AssemblyName System.IO.Compression.FileSystem
[System.IO.Compression.ZipFile]::CreateFromDirectory($staging, $zipDest, [System.IO.Compression.CompressionLevel]::Optimal, $false)

# Also create a copy in Release folder
Copy-Item $zipDest "$workspaceRoot\Release\" -Force

Write-Host "Release ZIP created successfully!"
Get-Item $zipDest | Select-Object Name, Length, LastWriteTime | Format-Table -AutoSize
