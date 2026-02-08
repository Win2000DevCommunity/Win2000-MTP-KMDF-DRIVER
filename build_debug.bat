@echo off
REM ============================================================================
REM  MTP KMDF Driver DEBUG Build Script for Windows 2000
REM  INTELLIGENT AUTO-DETECTION - No manual configuration needed
REM ============================================================================

echo.
echo ====================================================================
echo   Building MTP KMDF Driver for Windows 2000 (DEBUG BUILD)
echo ====================================================================
echo.

REM ============================================================================
REM  STEP 1: Auto-detect DDK paths intelligently
REM ============================================================================

REM Try to detect DDK root from this script's location
set SCRIPT_DIR=%~dp0
set DRIVER_SRC=%SCRIPT_DIR%

REM Navigate up to find DDK root (this script is in DDK\src\mtp_kmdf_w2k)
for %%I in ("%SCRIPT_DIR%..\..") do set DDK_ROOT=%%~fI

echo [AUTO-DETECT] Script location: %SCRIPT_DIR%
echo [AUTO-DETECT] Detected DDK root: %DDK_ROOT%

REM Verify DDK structure
if not exist "%DDK_ROOT%\bin\setenv.bat" (
    echo [AUTO-DETECT] setenv.bat not found in standard location
    echo [AUTO-DETECT] Trying alternative detection...
    
    REM Try alternative paths
    if exist "C:\WINDDK\3790.1830\bin\setenv.bat" (
        set DDK_ROOT=C:\WINDDK\3790.1830
        echo [AUTO-DETECT] Found DDK at: %DDK_ROOT%
    ) else if exist "C:\WinDDK\3790.1830\bin\setenv.bat" (
        set DDK_ROOT=C:\WinDDK\3790.1830
        echo [AUTO-DETECT] Found DDK at: %DDK_ROOT%
    ) else (
        echo [ERROR] Cannot locate Windows 2000 DDK
        echo Please ensure DDK is installed or modify DDK_ROOT in this script
        pause
        exit /b 1
    )
)

REM Verify critical paths exist
if not exist "%DDK_ROOT%\bin" (
    echo [ERROR] DDK bin directory not found: %DDK_ROOT%\bin
    pause
    exit /b 1
)

if not exist "%DDK_ROOT%\inc\ddk\w2k\ntddk.h" (
    echo [ERROR] Windows 2000 headers not found: %DDK_ROOT%\inc\ddk\w2k\
    pause
    exit /b 1
)

echo [AUTO-DETECT] ✓ DDK structure verified

REM ============================================================================
REM  STEP 2: Set up build environment using DDK's setenv.bat
REM ============================================================================

echo.
echo [BUILD-ENV] Setting up Windows 2000 DDK build environment...
echo [BUILD-ENV] DDK Path: %DDK_ROOT%
echo [BUILD-ENV] Target: Windows 2000 Checked Build (x86 DEBUG)
echo.

REM Auto-detect KMDF path for later reference
set KMDF_ROOT=
for %%I in ("%DDK_ROOT%\..\7600.16385.1") do set KMDF_ROOT=%%~fI
if not exist "%KMDF_ROOT%\inc\wdf\kmdf\1.9\wdf.h" (
    REM Try alternative locations
    for %%I in ("%DDK_ROOT%\..\..\7600.16385.1") do set KMDF_ROOT=%%~fI
    if not exist "%KMDF_ROOT%\inc\wdf\kmdf\1.9\wdf.h" (
        echo [ERROR] KMDF 1.9 headers not found
        echo Expected: %KMDF_ROOT%\inc\wdf\kmdf\1.9\wdf.h
        pause
        exit /b 1
    )
)

echo [BUILD-ENV] KMDF 1.9 Path: %KMDF_ROOT%

REM Use DDK's own environment setup (it knows how to configure everything correctly)
echo [BUILD-ENV] Calling DDK setenv.bat for proper environment configuration...
call "%DDK_ROOT%\bin\setenv.bat" "%DDK_ROOT%" chk w2k

if errorlevel 1 (
    echo [ERROR] DDK environment setup failed
    pause
    exit /b 1
)

echo [BUILD-ENV] ✓ Environment configured (DEBUG MODE)
echo [BUILD-ENV]   Using DDK environment from setenv.bat
echo [BUILD-ENV]   KMDF 1.9 paths in sources file
echo [BUILD-ENV]   Compiler: cl.exe (from PATH)
echo [BUILD-ENV]   Debug: Enabled (DbgPrint, ASSERT, full symbols)

REM ============================================================================
REM  STEP 3: Prepare build directory
REM ============================================================================

echo.
echo [PREPARE] Navigating to driver source directory...
echo [PREPARE] Source: %DRIVER_SRC%
cd /d "%DRIVER_SRC%"

if errorlevel 1 (
    echo [ERROR] Cannot find driver source at %DRIVER_SRC%
    pause
    exit /b 1
)
REM ============================================================================
REM  STEP 4: Execute build with intelligent error handling (DEBUG)
REM ============================================================================

echo.
echo [BUILD] Starting compilation (DEBUG MODE)...
echo [BUILD] Compiler: Microsoft C/C++ Compiler (cl.exe from W2K DDK)
echo [BUILD] Sources: Driver.c Device.c Usb.c Mtp.c
echo [BUILD] Target: mtp.sys (kernel-mode driver with debug symbols)
echo [BUILD] Debug Features: DbgPrint enabled, assertions enabled
echo [BUILD] Options: Checked build (no optimizations, full debugging)
echo.
echo ────────────────────────────────────────────────────────────────────
echo.

REM Intelligently locate build.exe (can be in bin\, bin\x86\, or bin\win64\x86\)
set BUILD_EXE=
if exist "%DDK_ROOT%\bin\x86\build.exe" (
    set BUILD_EXE=%DDK_ROOT%\bin\x86\build.exe
    echo [BUILD] Found build.exe: bin\x86\build.exe
) else if exist "%DDK_ROOT%\bin\build.exe" (
    set BUILD_EXE=%DDK_ROOT%\bin\build.exe
    echo [BUILD] Found build.exe: bin\build.exe
) else if exist "%DDK_ROOT%\bin\win64\x86\build.exe" (
    set BUILD_EXE=%DDK_ROOT%\bin\win64\x86\build.exe
    echo [BUILD] Found build.exe: bin\win64\x86\build.exe
) else (
    echo [ERROR] build.exe not found in any expected location:
    echo   - %DDK_ROOT%\bin\x86\build.exe
    echo   - %DDK_ROOT%\bin\build.exe
    echo   - %DDK_ROOT%\bin\win64\x86\build.exe
    echo [ERROR] This is a critical DDK component
    pause
    exit /b 1
)

REM Build with verbose output
echo [BUILD] Executing: "%BUILD_EXE%" -cZg
echo [BUILD] Working directory: %CD%
echo [BUILD] Looking for build output in:
echo         - Current dir: buildchk_w2k_x86.err / .log / .wrn
echo         - objchk_w2k_x86 subdirectories
echo.
"%BUILD_EXE%" -cZg

set BUILD_RESULT=%ERRORLEVEL%

echo.
echo [BUILD] Build command finished with exit code: %BUILD_RESULT%
echo.

REM Always show what files were created, regardless of error
echo [BUILD] Searching for build output files...
if exist "buildchk_w2k_x86.log" echo   Found: buildchk_w2k_x86.log
if exist "buildchk_w2k_x86.err" echo   Found: buildchk_w2k_x86.err  
if exist "buildchk_w2k_x86.wrn" echo   Found: buildchk_w2k_x86.wrn
if exist "objchk_w2k_x86" echo   Found: objchk_w2k_x86 directory
echo.

if %BUILD_RESULT% NEQ 0 (
    echo.
    echo ====================================================================
    echo   BUILD FAILED - DETAILED ERROR REPORT
    echo ====================================================================
    echo.
    
    REM Display detailed errors from build error log
    if exist "buildchk_w2k_x86.err" (
        echo [COMPILATION ERRORS] Contents of buildchk_w2k_x86.err:
        echo ────────────────────────────────────────────────────────────────────
        type "buildchk_w2k_x86.err"
        echo ────────────────────────────────────────────────────────────────────
        echo.
    ) else (
        echo [NO ERROR FILE] buildchk_w2k_x86.err was not created
        echo This means the error occurred before compilation started
        echo.
    )
    
    REM Display warnings if any
    if exist "buildchk_w2k_x86.wrn" (
        echo [COMPILATION WARNINGS] Contents of buildchk_w2k_x86.wrn:
        echo ────────────────────────────────────────────────────────────────────
        type "buildchk_w2k_x86.wrn"
        echo ────────────────────────────────────────────────────────────────────
        echo.
    )
    
    REM Always show full build log when there's an error
    if exist "buildchk_w2k_x86.log" (
        echo [FULL BUILD LOG] Complete contents of buildchk_w2k_x86.log:
        echo ────────────────────────────────────────────────────────────────────
        type "buildchk_w2k_x86.log"
        echo ────────────────────────────────────────────────────────────────────
        echo.
    ) else (
        echo [NO LOG FILE] buildchk_w2k_x86.log was not created
        echo This indicates build.exe failed to start or sources file is missing
        echo.
        if not exist "sources" (
            echo [CRITICAL] sources file not found in current directory!
            echo Build cannot proceed without sources file
        )
        echo.
    )
    
    echo ====================================================================
    echo   POSSIBLE CAUSES:
    echo ====================================================================
    echo   Error1 = General build failure (check build log above)
    echo   Error3 = Compilation errors (check .err file above)
    echo.
    echo   If no log files exist:
    echo   - Check that 'sources' file exists in this directory
    echo   - Verify PATH environment variable includes DDK tools
    echo   - Ensure headers are accessible (INCLUDE path)
    echo.
    echo   If you see actual errors above:
    echo   - Fix the syntax errors shown
    echo   - Check for missing headers or wrong paths
    echo   - Run clean.bat and try again
    echo ====================================================================
    echo.
    pause
    exit /b 1
)

echo.
echo ====================================================================
echo   DEBUG BUILD SUCCESSFUL!
echo ====================================================================
echo.
echo Driver Output: %DRIVER_SRC%\objchk_w2k_x86\i386\mtp.sys
echo.

REM Check if driver file was actually created
if exist "objchk_w2k_x86\i386\mtp.sys" (
    echo File Size: 
    dir "objchk_w2k_x86\i386\mtp.sys" | find "mtp.sys"
    echo.
    echo Additional files:
    dir "objchk_w2k_x86\i386\mtp.*" /b
    echo.
    echo ====================================================================
    echo   DEBUG BUILD READY FOR TESTING
    echo ====================================================================
    echo.
    echo This debug build includes:
    echo   - DbgPrint messages visible in DebugView
    echo   - ASSERT checks enabled
    echo   - Full debug symbols (mtp.pdb)
    echo   - No optimizations
    echo.
    echo Use this build for development and debugging only
    echo Use build_driver.bat for production/release builds
    echo.
) else (
    echo WARNING: mtp.sys was not found in output directory
    echo Build may have completed but driver file is missing
    echo.
)

pause
