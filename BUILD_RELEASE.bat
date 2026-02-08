@echo off
REM ====================================================================
REM  Automated Build Script for MTP KMDF 1.9 Driver (Windows 2000)
REM  For presentation - February 2, 2026
REM ====================================================================

echo.
echo ====================================================================
echo  AUTOMATED BUILD - MTP KMDF 1.9 Driver for Windows 2000
echo  Build Date: %DATE% %TIME%
echo ====================================================================
echo.

REM Clean previous build artifacts
if exist objchk_w2k_x86 (
    echo Cleaning previous build artifacts...
    rmdir /S /Q objchk_w2k_x86 2>NUL
)

REM Run the build
echo Starting build process...
echo.
call "%~dp0build_w2k.bat"

REM Check build result
if %ERRORLEVEL% NEQ 0 (
    echo.
    echo ====================================================================
    echo  BUILD FAILED - Error code: %ERRORLEVEL%
    echo ====================================================================
    pause
    exit /b %ERRORLEVEL%
)

REM Verify driver exists
if not exist "objchk_w2k_x86\i386\mtp.sys" (
    echo.
    echo ====================================================================
    echo  ERROR: Driver file not found!
    echo ====================================================================
    pause
    exit /b 1
)

REM Create release directory
if not exist "Release" mkdir Release

REM Copy driver to release directory
echo.
echo Copying driver to Release directory...
copy /Y "objchk_w2k_x86\i386\mtp.sys" "Release\mtp.sys" >NUL
copy /Y "objchk_w2k_x86\i386\mtp.pdb" "Release\mtp.pdb" 2>NUL

REM Get file size
for %%A in ("Release\mtp.sys") do set SIZE=%%~zA

echo.
echo ====================================================================
echo  BUILD SUCCESSFUL - Ready for presentation!
echo ====================================================================
echo  Driver: Release\mtp.sys
echo  Size: %SIZE% bytes
echo  Build: Windows 2000 Checked (Debug)
echo  KMDF: Version 1.9
echo ====================================================================
echo.
echo Driver is ready to deploy on Windows 2000 systems!
echo.
pause
