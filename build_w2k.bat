@echo off
REM Build MTP driver for Windows 2000 using DDK build environment
setlocal

echo.
echo ====================================================================
echo   Building MTP KMDF 1.9 Driver for Windows 2000
echo ====================================================================
echo.

set DDK_ROOT=C:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\3790.1830

REM Set up DDK build environment for Windows 2000 checked (debug) build
call "%DDK_ROOT%\bin\setenv.bat" %DDK_ROOT% w2k chk

REM Navigate to source directory
cd /d "%~dp0"

echo.
echo Building driver...
echo.

REM Clean previous build
if exist objchk_w2k_x86 rmdir /s /q objchk_w2k_x86

REM Run DDK build
build -cZ

if %ERRORLEVEL% EQU 0 (
    echo.
    echo ====================================================================
    echo   BUILD SUCCESSFUL!!!
    echo   Driver: objchk_w2k_x86\i386\mtp.sys
    echo ====================================================================
    echo.
    dir objchk_w2k_x86\i386\mtp.sys
) else (
    echo.
    echo ====================================================================
    echo   BUILD FAILED - Error code: %ERRORLEVEL%
    echo ====================================================================
    echo.
)

endlocal
