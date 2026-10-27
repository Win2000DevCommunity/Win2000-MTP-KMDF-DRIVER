@echo off
setlocal
set DDKROOT=%~dp0..\3790.1830
set SDKROOT=%~dp0..\2000 sdk

set PATH=%DDKROOT%\bin\x86;%PATH%
set INCLUDE=%SDKROOT%\Include;%DDKROOT%\inc\crt
set LIB=%SDKROOT%\Lib;%DDKROOT%\lib\w2k\i386;%DDKROOT%\lib\crt\i386

set CFLAGS=/nologo /O2 /W3 /D_WIN32_WINNT=0x0500 /DWINVER=0x0500 /D_WIN32_IE=0x0500
set GUI_LIBS=kernel32.lib user32.lib gdi32.lib comctl32.lib comdlg32.lib shell32.lib advapi32.lib ole32.lib oleaut32.lib uuid.lib BufferOverflowU.lib
set CONSOLE_LIBS=kernel32.lib user32.lib advapi32.lib BufferOverflowU.lib

cd /d "%~dp0"

echo ====================================================================
echo   Building mtp_gui.exe (Windows 2000 Explorer GUI - Release)
echo ====================================================================
cl %CFLAGS% /MD mtp_gui.c /link /subsystem:windows %GUI_LIBS% /out:mtp_gui.exe
if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] mtp_gui.exe build failed!
    goto :error
)
echo [SUCCESS] mtp_gui.exe built successfully!

echo.
echo ====================================================================
echo   Building mtp_gui_debug.exe (Diagnostics GUI with Live Console)
echo ====================================================================
cl %CFLAGS% /DMTP_DEBUG_CONSOLE=1 /MD mtp_gui.c /link /subsystem:windows %GUI_LIBS% /out:mtp_gui_debug.exe
if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] mtp_gui_debug.exe build failed!
    goto :error
)
echo [SUCCESS] mtp_gui_debug.exe built successfully!

echo.
echo ====================================================================
echo   Building mtp_transfer.exe (Console CLI Tool)
echo ====================================================================
cl %CFLAGS% /MD mtp_transfer.c /link /subsystem:console %CONSOLE_LIBS% /out:mtp_transfer.exe
if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] mtp_transfer.exe build failed!
    goto :error
)
echo [SUCCESS] mtp_transfer.exe built successfully!

echo.
echo ====================================================================
echo   Copying binaries to Release folder
echo ====================================================================
if not exist "..\Release" mkdir "..\Release"
copy /y mtp_gui.exe "..\Release\mtp_gui.exe"
copy /y mtp_gui_debug.exe "..\Release\mtp_gui_debug.exe"
copy /y mtp_transfer.exe "..\Release\mtp_transfer.exe"

echo.
echo [ALL BUILDS SUCCESSFUL]
dir mtp_gui.exe mtp_gui_debug.exe mtp_transfer.exe
goto :end

:error
echo.
echo [ERROR] One or more builds failed!
exit /b 1

:end
endlocal
