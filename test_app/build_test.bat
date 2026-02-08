@echo off
REM ====================================================================
REM  Build MTP Test Application for Windows 2000
REM ====================================================================

echo.
echo ====================================================================
echo  Building MTP Test Application
echo ====================================================================
echo.

REM Set paths - use DDK headers for both kernel and user mode
set DDK_BASE=C:\Users\win2000\Downloads\WinDDK-1ed3987db6e72d1fb9c6298fddf0c080b8f591e1\3790.1830
set DDK_BIN=%DDK_BASE%\bin\x86
set DDK_INC=%DDK_BASE%\inc\w2k
set DDK_CRT=%DDK_BASE%\inc\crt
set DDK_LIB=%DDK_BASE%\lib\w2k\i386
set PATH=%DDK_BIN%;%PATH%

REM Clean previous build
if exist mtp_test.exe del mtp_test.exe
if exist mtp_test.obj del mtp_test.obj

REM Compile with DDK cl.exe and DDK headers
echo Compiling mtp_test.c...
"%DDK_BIN%\cl.exe" /nologo /W3 /O2 /I"%DDK_INC%" /I"%DDK_CRT%" /D_WIN32_WINNT=0x0500 /DWINVER=0x0500 mtp_test.c security_cookie.c /link /LIBPATH:"%DDK_LIB%" kernel32.lib

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo ====================================================================
    echo  BUILD FAILED
    echo ====================================================================
    pause
    exit /b 1
)

REM Check output
if not exist mtp_test.exe (
    echo.
    echo ====================================================================
    echo  ERROR: Executable not created!
    echo ====================================================================
    pause
    exit /b 1
)

echo.
echo ====================================================================
echo  BUILD SUCCESSFUL!
echo  Output: mtp_test.exe
echo ====================================================================
echo.
echo To run: mtp_test.exe
echo With custom device: mtp_test.exe \\.\YourDeviceName
echo.

pause
