@echo off
REM Compile using Windows 7 DDK compiler targeting Windows 2000
setlocal ENABLEDELAYEDEXPANSION

echo.
echo ====================================================================
echo   MTP Driver - Windows 7 DDK Compiler for Windows 2000
echo ====================================================================
echo.

set W2K_DDK=c:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\3790.1830
set WIN7_DDK=c:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\7600.16385.1

REM Clean previous build
if exist objd rmdir /s /q objd
mkdir objd

REM Use Windows 7 DDK compiler (supports C99)
set CL_EXE=%WIN7_DDK%\bin\x86\x86\cl.exe
set LINK_EXE=%WIN7_DDK%\bin\x86\x86\link.exe

REM Common defines - TARGET WINDOWS 2000
set DEFINES=/D_X86_=1 /DX86=1 /Di386=1 /DSTD_CALL /DCONDITION_HANDLING=1 /DNT_UP=1 /DNT_INST=0 /DWIN32=100 /D_NT1X_=100 /DWINNT=1 /D_WIN32_WINNT=0x0500 /DWINVER=0x0500 /D_WIN32_IE=0x0600 /DWIN32_LEAN_AND_MEAN=1 /DDEVL=1 /DDBG=1 /DFPO=0 /DDRIVER /DWIN2000 /DDEPRECATE_DDK_FUNCTIONS=1 /DMSC_NOOPT /D_DLL=1 /DNTDDI_VERSION=0x05000000

REM Include paths - USE WINDOWS 2000 HEADERS
set INCLUDES=/I"." /I"%W2K_DDK%\inc\crt" /I"%W2K_DDK%\inc\ddk\w2k" /I"%W2K_DDK%\inc\w2k" /I"%WIN7_DDK%\inc\wdf\kmdf\1.9"

REM Compiler flags - ADD /TP to compile as C++ which allows C99-style declarations
set CFLAGS=/TP /c /Zp8 /Gy /W3 /WX- /Gz /Gm- /GR- /GF /Z7 /Od /Oi /Oy-

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

REM Linker flags
set LINKFLAGS=/DRIVER /SUBSYSTEM:NATIVE /ENTRY:FxDriverEntry /DEBUG /DEBUGTYPE:CV /MACHINE:X86 /NODEFAULTLIB /RELEASE /INCREMENTAL:NO /FULLBUILD /WX- /MERGE:_PAGE=PAGE /MERGE:_TEXT=.text /SECTION:INIT,d /ALIGN:0x80 /OSVERSION:5.0 /STACK:0x40000,0x1000 /IGNORE:4001,4037,4039,4065,4070,4078,4087,4089,4198

REM Library paths - USE WINDOWS 2000 LIBRARIES
set LIBS="%W2K_DDK%\lib\i386\free\wdm.lib" "%W2K_DDK%\lib\i386\free\ntoskrnl.lib" "%W2K_DDK%\lib\i386\free\hal.lib" "%W2K_DDK%\lib\i386\free\usbd.lib" "%WIN7_DDK%\lib\wdf\kmdf\i386\1.9\WdfDriverEntry.lib" "%WIN7_DDK%\lib\wdf\kmdf\i386\1.9\WdfLdr.lib"

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
echo   Symbols: objd\mtp.pdb
echo.
goto :end

:error
echo.
echo [ERROR] Build failed
goto :end

:end
endlocal
