@echo off
setlocal ENABLEDELAYEDEXPANSION

echo ====================================================================
echo   Building MTP KMDF 1.9 Driver for Windows 2000
echo ====================================================================

set "SCRIPT_DIR=%~dp0"
set "W2K_DDK=%SCRIPT_DIR%3790.1830"
set "WIN7_DDK=%SCRIPT_DIR%7600.16385.1"
set "BUILD_DIR=%SCRIPT_DIR%objd"
set "RELEASE_DIR=%SCRIPT_DIR%Release"

if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"
if not exist "%RELEASE_DIR%" mkdir "%RELEASE_DIR%"

set "CL_EXE=%WIN7_DDK%\bin\x86\x86\cl.exe"
set "LINK_EXE=%WIN7_DDK%\bin\x86\x86\link.exe"

set DEFINES=/D_X86_=1 /DX86=1 /Di386=1 /DSTD_CALL /DCONDITION_HANDLING=1 /DNT_UP=1 /DNT_INST=0 /DWIN32=100 /D_NT1X_=100 /DWINNT=1 /D_WIN32_WINNT=0x0500 /DWINVER=0x0500 /D_WIN32_IE=0x0600 /DWIN32_LEAN_AND_MEAN=1 /DDEVL=1 /DDBG=1 /DFPO=0 /DDRIVER /DWIN2000 /DDEPRECATE_DDK_FUNCTIONS=1 /DMSC_NOOPT /D_DLL=1 /DNTDDI_VERSION=0x05000000 /D__SPECSTRINGS_STRICT_LEVEL=0

set INCLUDES=/I"." /I"%W2K_DDK%\inc\crt" /I"%W2K_DDK%\inc\ddk\w2k" /I"%W2K_DDK%\inc\ddk\wdm\w2k" /I"%W2K_DDK%\inc\w2k" /I"%WIN7_DDK%\inc\wdf\kmdf\1.9" /I"%WIN7_DDK%\inc\api"

set CFLAGS=/c /Zp8 /Gy /W3 /WX- /Gz /Gm- /GR- /GF /Z7 /Od /Oi /Oy- /GS-

echo [1/3] Compiling source files...
"%CL_EXE%" %CFLAGS% %DEFINES% %INCLUDES% /Fo"%BUILD_DIR%/" Driver.c Device.c Usb.c Mtp.c security_stub.c
if errorlevel 1 (
    echo [ERROR] Compilation failed!
    exit /b 1
)

echo [2/3] Linking mtp.sys with /ENTRY:FxDriverEntry...
set LINKFLAGS=/DRIVER /SUBSYSTEM:NATIVE /ENTRY:FxDriverEntry /DEBUG /MACHINE:X86 /NODEFAULTLIB /RELEASE /INCREMENTAL:NO /FULLBUILD /MERGE:_PAGE=PAGE /MERGE:_TEXT=.text /SECTION:INIT,d /ALIGN:0x80 /OSVERSION:5.0 /STACK:0x40000,0x1000 /IGNORE:4001,4037,4039,4044,4065,4070,4078,4087,4089,4198

set LIBS="%W2K_DDK%\lib\w2k\i386\ntoskrnl.lib" "%W2K_DDK%\lib\w2k\i386\hal.lib" "%W2K_DDK%\lib\w2k\i386\usbd.lib" "%WIN7_DDK%\lib\wdf\kmdf\i386\1.9\WdfDriverEntry.lib" "%WIN7_DDK%\lib\wdf\kmdf\i386\1.9\WdfLdr.lib"

"%LINK_EXE%" %LINKFLAGS% /OUT:"%RELEASE_DIR%\mtp.sys" /PDB:"%RELEASE_DIR%\mtp.pdb" /MAP:"%RELEASE_DIR%\mtp.map" "%BUILD_DIR%\Driver.obj" "%BUILD_DIR%\Device.obj" "%BUILD_DIR%\Usb.obj" "%BUILD_DIR%\Mtp.obj" "%BUILD_DIR%\security_stub.obj" %LIBS%
if errorlevel 1 (
    echo [ERROR] Linking failed!
    exit /b 1
)

echo [3/3] Packaging Release files...
copy /y "%SCRIPT_DIR%mtp.inf" "%RELEASE_DIR%\mtp.inf" >nul

if exist "D:\Users\win2000\Downloads\WdfCoInstaller01009.dll" (
    copy /y "D:\Users\win2000\Downloads\WdfCoInstaller01009.dll" "%RELEASE_DIR%\WdfCoInstaller01009.dll" >nul
) else if exist "C:\Users\Win2000\Desktop\WdfCoInstaller01009.dll" (
    copy /y "C:\Users\Win2000\Desktop\WdfCoInstaller01009.dll" "%RELEASE_DIR%\WdfCoInstaller01009.dll" >nul
)

echo.
echo ====================================================================
echo   BUILD SUCCESSFUL!
echo   Target: %RELEASE_DIR%\mtp.sys
echo ====================================================================
dir "%RELEASE_DIR%\mtp.*"

endlocal
