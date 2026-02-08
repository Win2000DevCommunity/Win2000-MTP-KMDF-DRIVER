@echo off
REM ============================================================================
REM  Clean all build artifacts
REM ============================================================================

echo.
echo Cleaning all build artifacts...
echo.

if exist objfre_w2k_x86 (
    echo Removing objfre_w2k_x86 (Release build)...
    rd /s /q objfre_w2k_x86
)

if exist objchk_w2k_x86 (
    echo Removing objchk_w2k_x86 (Debug build)...
    rd /s /q objchk_w2k_x86
)

if exist buildchk_w2k_x86.log (
    echo Removing build logs...
    del buildchk_w2k_x86.log
)

if exist buildfre_w2k_x86.log (
    del buildfre_w2k_x86.log
)

if exist buildchk_w2k_x86.wrn (
    del buildchk_w2k_x86.wrn
)

if exist buildfre_w2k_x86.wrn (
    del buildfre_w2k_x86.wrn
)

if exist buildchk_w2k_x86.err (
    del buildchk_w2k_x86.err
)

if exist buildfre_w2k_x86.err (
    del buildfre_w2k_x86.err
)

echo.
echo ====================================================================
echo   All build artifacts cleaned
echo ====================================================================
echo.
echo Run build_driver.bat to create a new release build
echo Run build_debug.bat to create a new debug build
echo.

pause
