@echo off
REM ====================================================================
REM   Direct compilation - Bypass build.exe completely
REM   Compile each .c file directly with cl.exe, then link with link.exe
REM ====================================================================

setlocal ENABLEDELAYEDEXPANSION

echo.
echo ====================================================================
echo   MTP Driver - Direct Compilation (No BUILD.EXE)
echo ====================================================================
echo.

set SCRIPT_DIR=%~dp0
set W2K_DDK=c:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\3790.1830
set WIN7_DDK=c:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\7600.16385.1

echo [PATHS]
echo   W2K DDK: %W2K_DDK%
echo   WIN7 DDK (Compiler): %WIN7_DDK%
echo   Source: %SCRIPT_DIR%
echo.

REM Clean previous build
if exist objd rmdir /s /q objd
mkdir objd

REM Use Windows 2000 DDK compiler for guaranteed compatibility
set CL_EXE=%W2K_DDK%\bin\x86\cl.exe
set LINK_EXE=%W2K_DDK%\bin\x86\link.exe
set PATH=%W2K_DDK%\bin\x86;%W2K_DDK%\bin;%PATH%

REM Compiler flags - based on your working command line for W2K target
set CFLAGS=/c /Zp8 /Gy /W3 /Gz /Gm- /GR- /GF /Gs- /Z7 /Od /Oi /Oy- /D_X86_=1 /DX86=1 /Di386=1 /DSTD_CALL /DCONDITION_HANDLING=1 /DNT_UP=1 /DNT_INST=0 /DWIN32=100 /D_NT1X_=100 /DWINNT=1 /D_WIN32_WINNT=0x0500 /DWINVER=0x0500 /D_WIN32_IE=0x0600 /DWIN32_LEAN_AND_MEAN=1 /DDEVL=1 /DDBG=1 /DFPO=0 /DDRIVER /DWIN2000 /DDEPRECATE_DDK_FUNCTIONS=1 /DMSC_NOOPT /D_DLL=1 /DNTDDI_VERSION=0x05000000 /DOSVER=1

REM Include paths - Use W2K DDK headers + KMDF 1.9 headers
set INCLUDES=/I"." /I"%W2K_DDK%\inc\crt" /I"%W2K_DDK%\inc\ddk\w2k" /I"%W2K_DDK%\inc\w2k" /I"%WIN7_DDK%\inc\wdf\kmdf\1.9"

REM Warning level
set WARNINGS=/W3 /WX-

echo [COMPILE] Starting compilation...
echo   Compiler: Windows 2000 DDK cl.exe (Native W2K compiler)
echo   Headers: Windows 2000 DDK + KMDF 1.9
echo   Target: Windows 2000 (5.0)
echo   Flags: Debug symbols, optimized
echo.

REM Compile each source file
echo [1/4] Compiling Driver.c...
"%CL_EXE%" %CFLAGS% %INCLUDES% %WARNINGS% /Fo"objd\Driver.obj" Driver.c
if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] Driver.c compilation failed!
    pause
    exit /b 1
)

echo [2/4] Compiling Device.c...
"%CL_EXE%" %CFLAGS% %INCLUDES% %WARNINGS% /Fo"objd\Device.obj" Device.c
if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] Device.c compilation failed!
    pause
    exit /b 1
)

echo [3/4] Compiling Usb.c...
"%CL_EXE%" %CFLAGS% %INCLUDES% %WARNINGS% /Fo"objd\Usb.obj" Usb.c
if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] Usb.c compilation failed!
    pause
    exit /b 1
)

echo [4/4] Compiling Mtp.c...
"%CL_EXE%" %CFLAGS% %INCLUDES% %WARNINGS% /Fo"objd\Mtp.obj" Mtp.c
if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] Mtp.c compilation failed!
    pause
    exit /b 1
)

echo.
echo [LINK] Linking driver...

REM Linker flags - target Windows 2000 (5.0)
set LINKFLAGS=/DRIVER /SUBSYSTEM:NATIVE /ENTRY:FxDriverEntry /DEBUG /DEBUGTYPE:CV /MACHINE:X86 /NODEFAULTLIB /RELEASE /INCREMENTAL:NO /FULLBUILD /WX- /MERGE:_PAGE=PAGE /MERGE:_TEXT=.text /SECTION:INIT,d /ALIGN:0x80 /OSVERSION:5.0 /STACK:0x40000,0x1000 /IGNORE:4001,4037,4039,4065,4070,4078,4087,4089,4198

REM Library paths - W2K DDK libraries + KMDF 1.9 libraries
set LIBS="%W2K_DDK%\lib\i386\free\wdm.lib" "%W2K_DDK%\lib\i386\free\ntoskrnl.lib" "%W2K_DDK%\lib\i386\free\hal.lib" "%W2K_DDK%\lib\i386\free\usbd.lib" "%WIN7_DDK%\lib\wdf\kmdf\i386\1.9\WdfDriverEntry.lib" "%WIN7_DDK%\lib\wdf\kmdf\i386\1.9\WdfLdr.lib"

"%LINK_EXE%" %LINKFLAGS% /OUT:"objd\mtp.sys" /PDB:"objd\mtp.pdb" /MAP:"objd\mtp.map" objd\Driver.obj objd\Device.obj objd\Usb.obj objd\Mtp.obj %LIBS%

if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] Linking failed!
    pause
    exit /b 1
)

echo.
echo ====================================================================
echo   BUILD SUCCESSFUL!
echo ====================================================================
echo.
echo   Output: objd\mtp.sys
dir objd\mtp.sys
echo.
echo   Symbols: objd\mtp.pdb
dir objd\mtp.pdb
echo.

pause
