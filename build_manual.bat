@echo off
REM ====================================================================
REM   Manual Build Script - Bypass setenv.bat completely
REM   Sets all environment variables manually
REM ====================================================================

setlocal ENABLEDELAYEDEXPANSION

echo.
echo ====================================================================
echo   MTP KMDF W2K Driver - Manual Build (DEBUG)
echo ====================================================================
echo.

REM Detect DDK root from script location
set SCRIPT_DIR=%~dp0
set DDK_ROOT=%SCRIPT_DIR%..\..
set KMDF_ROOT=%SCRIPT_DIR%..\..\..\7600.16385.1

echo [SETUP] DDK Root: %DDK_ROOT%
echo [SETUP] KMDF Root: %KMDF_ROOT%
echo.

REM Set BASEDIR without quotes
set BASEDIR=%DDK_ROOT%

REM Set target platform
set _BUILDARCH=x86
set _BUILDTYPE=chk
set _NT_TARGET_VERSION=0x500
set NTDEBUG=ntsd
set NTDEBUGTYPE=both
set MSC_OPTIMIZATION=/Od

REM Compiler paths
set PATH=%DDK_ROOT%\bin\x86;%DDK_ROOT%\bin\x86\x86;%DDK_ROOT%\bin;%PATH%

REM Include paths (NO QUOTES, use semicolons)
set INCLUDE=%DDK_ROOT%\inc\ddk\w2k;%DDK_ROOT%\inc\w2k;%DDK_ROOT%\inc\crt;%KMDF_ROOT%\inc\wdf\kmdf\1.9;%KMDF_ROOT%\inc\api

REM Library paths
set LIB=%DDK_ROOT%\lib\w2k\i386;%KMDF_ROOT%\lib\wdf\kmdf\i386\1.9

REM DDK-specific variables
set DDK_INC_PATH=%DDK_ROOT%\inc\ddk\w2k
set DDK_LIB_PATH=%DDK_ROOT%\lib\w2k\i386
set CRT_INC_PATH=%DDK_ROOT%\inc\crt
set CRT_LIB_PATH=%DDK_ROOT%\lib\crt\i386
set SDK_INC_PATH=%DDK_ROOT%\inc\w2k
set SDK_LIB_PATH=%DDK_ROOT%\lib\w2k\i386
set WDF_INC_PATH=%KMDF_ROOT%\inc\wdf\kmdf\1.9
set WDF_LIB_PATH=%KMDF_ROOT%\lib\wdf\kmdf\i386\1.9

REM Build environment - CRITICAL: NTMAKEENV must point to bin directory
set NTMAKEENV=%DDK_ROOT%\bin
set BUILD_DEFAULT_TARGETS=-386
set 386=1
set _NT_TOOLS_VERSION=0x600
set COPYCMD=/Y
set BUILD_ALT_DIR=d

echo [ENV] Environment configured:
echo   BASEDIR=%BASEDIR%
echo   DDK_INC_PATH=%DDK_INC_PATH%
echo   DDK_LIB_PATH=%DDK_LIB_PATH%
echo   INCLUDE=%INCLUDE%
echo   LIB=%LIB%
echo   PATH (first)=%DDK_ROOT%\bin\x86
echo.

echo [BUILD] Starting build.exe...
echo.

REM Navigate to source directory
cd /d "%SCRIPT_DIR%"

REM Run build.exe
"%DDK_ROOT%\bin\x86\build.exe" -cZg

set BUILD_EXIT=%ERRORLEVEL%

echo.
echo ====================================================================
echo   BUILD COMPLETE - Exit Code: %BUILD_EXIT%
echo ====================================================================
echo.

if exist buildchk_w2k_x86.err (
    echo [ERRORS] Contents of buildchk_w2k_x86.err:
    echo ========================================
    type buildchk_w2k_x86.err
    echo ========================================
    echo.
)

if exist buildchk_w2k_x86.log (
    echo [LOG] Full build log:
    echo ========================================
    type buildchk_w2k_x86.log
    echo ========================================
    echo.
)

if exist buildchk_w2k_x86.wrn (
    echo [WARNINGS] Contents of buildchk_w2k_x86.wrn:
    echo ========================================
    type buildchk_w2k_x86.wrn
    echo ========================================
)

if %BUILD_EXIT%==0 (
    echo [SUCCESS] Build completed successfully!
    if exist objchk_w2k_x86\i386\mtp.sys (
        echo [OUTPUT] Driver created: objchk_w2k_x86\i386\mtp.sys
        dir objchk_w2k_x86\i386\mtp.sys
    )
) else (
    echo [FAILED] Build failed with exit code %BUILD_EXIT%
    echo.
    echo Possible issues:
    echo   - Check if sources file is properly formatted
    echo   - Verify all source files exist (Driver.c Device.c Usb.c Mtp.c)
    echo   - Check for syntax errors in .err file above
)

echo.
pause
