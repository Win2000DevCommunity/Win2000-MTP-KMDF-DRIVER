@echo off
REM Compile for Windows XP (binary will work on Windows 2000 with KMDF 1.9 runtime)
setlocal ENABLEDELAYEDEXPANSION

echo.
echo ====================================================================
echo   MTP Driver - Compile for Windows XP (runs on Windows 2000)
echo ====================================================================
echo.

set W2K_DDK=c:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\3790.1830
set WIN7_DDK=c:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\7600.16385.1

REM Clean previous build
if exist objd rmdir /s /q objd
mkdir objd

REM Use Windows 7 DDK compiler
set CL_EXE=%WIN7_DDK%\bin\x86\x86\cl.exe
set LINK_EXE=%WIN7_DDK%\bin\x86\x86\link.exe

REM Defines for Windows XP (0x0501) - binary compatible with Windows 2000 + KMDF 1.9 runtime
REM __SPECSTRINGS_STRICT_LEVEL=0 disables SAL annotation processing (not supported in non-analyze builds)
set DEFINES=/D_X86_=1 /DX86=1 /Di386=1 /DSTD_CALL /DCONDITION_HANDLING=1 /DNT_UP=1 /DNT_INST=0 /DWIN32=100 /D_NT1X_=100 /DWINNT=1 /D_WIN32_WINNT=0x0501 /DWINVER=0x0501 /D_WIN32_IE=0x0600 /DWIN32_LEAN_AND_MEAN=1 /DDEVL=1 /DDBG=1 /DFPO=0 /DDRIVER /DDEPRECATE_DDK_FUNCTIONS=1 /DMSC_NOOPT /D_DLL=1 /DNTDDI_VERSION=0x05010000 /D__SPECSTRINGS_STRICT_LEVEL=0

REM Include paths - use Windows XP/2003 headers (compatible with Win2K)
set INCLUDES=/I"." /I"%W2K_DDK%\inc\crt" /I"%WIN7_DDK%\inc\ddk" /I"%WIN7_DDK%\inc\api" /I"%WIN7_DDK%\inc\wdf\kmdf\1.9"

REM Compiler flags
set CFLAGS=/c /Zp8 /Gy /W3 /WX- /Gz /Gm- /GR- /GF /Z7 /Od /Oi /Oy-

echo [STAGE 1] Compiling source files...
echo.

echo   Compiling Driver.c...
"%CL_EXE%" %CFLAGS% %DEFINES% %INCLUDES% /Fo"objd\Driver.obj" Driver.c
if %ERRORLEVEL% NEQ 0 goto :error

echo   Compiling Device.c...
"%CL_EXE%" %CFLAGS% %DEFINES% %INCLUDES% /Fo"objd\Device.obj" Device.c
if %ERRORLEVEL% NEQ 0 goto :error

echo   Compiling Usb.c...
"%CL_EXE%" %CFLAGS% %DEFINES% %INCLUDES% /Fo"objd\Usb.obj" Usb.c
if %ERRORLEVEL% NEQ 0 goto :error

echo   Compiling Mtp.c...
"%CL_EXE%" %CFLAGS% %DEFINES% %INCLUDES% /Fo"objd\Mtp.obj" Mtp.c
if %ERRORLEVEL% NEQ 0 goto :error

echo.
echo [STAGE 2] Linking driver...
echo.

REM Linker flags - Target Windows 2000 (5.0)
set LINKFLAGS=/DRIVER /SUBSYSTEM:NATIVE /ENTRY:FxDriverEntry /DEBUG /DEBUGTYPE:CV /MACHINE:X86 /NODEFAULTLIB /RELEASE /INCREMENTAL:NO /FULLBUILD /WX- /MERGE:_PAGE=PAGE /MERGE:_TEXT=.text /SECTION:INIT,d /ALIGN:0x80 /OSVERSION:5.0 /STACK:0x40000,0x1000 /IGNORE:4001,4037,4039,4065,4070,4078,4087,4089,4198

REM Libraries - use Win7 DDK libraries (compatible)
set LIBS="%WIN7_DDK%\lib\win7\i386\ntoskrnl.lib" "%WIN7_DDK%\lib\win7\i386\hal.lib" "%WIN7_DDK%\lib\wxp\i386\usbd.lib" "%WIN7_DDK%\lib\wdf\kmdf\i386\1.9\WdfDriverEntry.lib" "%WIN7_DDK%\lib\wdf\kmdf\i386\1.9\WdfLdr.lib"

"%LINK_EXE%" %LINKFLAGS% /OUT:"objd\mtp.sys" /PDB:"objd\mtp.pdb" /MAP:"objd\mtp.map" objd\Driver.obj objd\Device.obj objd\Usb.obj objd\Mtp.obj %LIBS%

if %ERRORLEVEL% NEQ 0 goto :error

echo.
echo ====================================================================
echo   BUILD SUCCESSFUL!
echo ====================================================================
echo.
echo   Output: objd\mtp.sys
dir objd\mtp.sys
echo.
echo   NOTE: This driver is built for Windows XP but WILL RUN on Windows 2000
echo         when you install the KMDF 1.9 runtime (WdfCoInstaller01009.dll)
echo.
goto :end

:error
echo.
echo [ERROR] Build failed
goto :end

:end
endlocal
