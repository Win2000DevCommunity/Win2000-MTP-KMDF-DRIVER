@echo off
REM ============================================================
REM Build script for MTP Transfer GUI Application
REM Uses Windows 2000 SDK
REM ============================================================

setlocal

REM Path to Windows 2000 SDK (adjust if needed)
set SDK_PATH=..\..\..\..\..\2000 sdk

REM Check if SDK exists
if not exist "%SDK_PATH%\Include" (
    echo ERROR: Windows 2000 SDK not found at %SDK_PATH%
    echo Please adjust SDK_PATH in this script.
    goto :error
)

REM Set up paths
set INCLUDE=%SDK_PATH%\Include;%INCLUDE%
set LIB=%SDK_PATH%\Lib;%LIB%

REM Check for compiler
where cl >nul 2>&1
if errorlevel 1 (
    echo ERROR: Visual C++ compiler (cl.exe) not found.
    echo Please run this from a Visual Studio or DDK command prompt.
    echo Or run SetEnv.Bat from the SDK first.
    goto :error
)

echo ============================================================
echo Building MTP Transfer GUI Application for Windows 2000
echo ============================================================
echo.

REM Compile the GUI application
echo Compiling mtp_gui.c...
cl /nologo /O2 /W3 /D_WIN32_WINNT=0x0500 /DWINVER=0x0500 /D_WIN32_IE=0x0500 ^
   /I"%SDK_PATH%\Include" ^
   mtp_gui.c ^
   /link /LIBPATH:"%SDK_PATH%\Lib" ^
   /subsystem:windows ^
   kernel32.lib user32.lib gdi32.lib comctl32.lib comdlg32.lib shell32.lib advapi32.lib ^
   /out:mtp_gui.exe

if errorlevel 1 (
    echo.
    echo ERROR: Compilation failed!
    goto :error
)

echo.
echo ============================================================
echo Build successful!
echo Output: mtp_gui.exe
echo ============================================================
echo.
echo Features:
echo   - Classic Windows 2000 GUI interface
echo   - ListView with file/folder icons
echo   - Toolbar with common actions
echo   - Menu bar with keyboard shortcuts
echo   - Status bar showing connection state
echo   - Open/Save dialogs for file transfer
echo.

goto :end

:error
echo.
echo Build failed.
exit /b 1

:end
endlocal
