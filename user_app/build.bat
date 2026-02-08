@echo off
REM ============================================================================
REM MTP File Transfer - Build Script for Windows 2000
REM ============================================================================
REM
REM This script compiles the MTP applications using the Windows 2000 DDK.
REM Run this from the user_app directory.
REM
REM Usage: build.bat [clean|release|debug|gui|console|all]
REM   clean   - Remove build artifacts
REM   release - Build optimized release version (default)
REM   debug   - Build with debug symbols
REM   gui     - Build only the GUI application
REM   console - Build only the console application
REM   all     - Build both GUI and console applications
REM
REM ============================================================================

setlocal enabledelayedexpansion

echo.
echo ============================================================================
echo          MTP File Transfer - Windows 2000 Build System
echo ============================================================================
echo.

REM ============================================================================
REM Configuration - Paths relative to user_app folder
REM ============================================================================

set DDKROOT=%~dp0..\..\..
set SDKROOT=%DDKROOT%\..\2000 sdk

REM Normalize paths
pushd %DDKROOT%
set DDKROOT=%CD%
popd
pushd "%SDKROOT%"
set SDKROOT=%CD%
popd

echo DDK Path: %DDKROOT%
echo SDK Path: %SDKROOT%
echo.

REM ============================================================================
REM Verify paths exist
REM ============================================================================

if not exist "%DDKROOT%\bin\x86\cl.exe" (
    echo ERROR: DDK compiler not found at %DDKROOT%\bin\x86\cl.exe
    goto :error
)

if not exist "%SDKROOT%\Include\windows.h" (
    echo ERROR: Windows 2000 SDK headers not found at %SDKROOT%\Include
    goto :error
)

if not exist "%DDKROOT%\lib\w2k\i386\kernel32.lib" (
    echo ERROR: Windows 2000 libraries not found at %DDKROOT%\lib\w2k\i386
    goto :error
)

echo [OK] DDK compiler found
echo [OK] SDK headers found  
echo [OK] W2K libraries found
echo.

REM ============================================================================
REM Set up build environment
REM ============================================================================

set PATH=%DDKROOT%\bin\x86;%PATH%
set INCLUDE=%DDKROOT%\inc\crt;%SDKROOT%\Include
set LIB=%DDKROOT%\lib\w2k\i386;%DDKROOT%\lib\crt\i386

REM Common compiler flags for Windows 2000 targeting
set CFLAGS=/nologo /W3 /D_WIN32_WINNT=0x0500 /DWINVER=0x0500 /D_WIN32_IE=0x0500

REM Libraries
set GUI_LIBS=kernel32.lib user32.lib gdi32.lib comctl32.lib comdlg32.lib shell32.lib advapi32.lib BufferOverflowU.lib
set CON_LIBS=kernel32.lib advapi32.lib BufferOverflowU.lib

REM ============================================================================
REM Parse command line
REM ============================================================================

set BUILD_TYPE=release
set BUILD_TARGET=gui

if "%1"=="" goto :build_gui
if /i "%1"=="clean" goto :clean
if /i "%1"=="debug" (
    set BUILD_TYPE=debug
    if /i "%2"=="all" goto :build_all
    if /i "%2"=="console" goto :build_console
    goto :build_gui
)
if /i "%1"=="release" (
    set BUILD_TYPE=release
    if /i "%2"=="all" goto :build_all
    if /i "%2"=="console" goto :build_console
    goto :build_gui
)
if /i "%1"=="gui" goto :build_gui
if /i "%1"=="console" goto :build_console
if /i "%1"=="all" goto :build_all

echo Unknown option: %1
echo.
echo Usage: build.bat [clean^|release^|debug^|gui^|console^|all]
goto :error

REM ============================================================================
REM Clean build artifacts
REM ============================================================================
:clean
echo Cleaning build artifacts...
if exist mtp_gui.exe del mtp_gui.exe
if exist mtp_gui.obj del mtp_gui.obj
if exist mtp_transfer.exe del mtp_transfer.exe
if exist mtp_transfer.obj del mtp_transfer.obj
if exist *.pdb del *.pdb
if exist *.ilk del *.ilk
echo.
echo Clean complete.
goto :success

REM ============================================================================
REM Build GUI application
REM ============================================================================
:build_gui
echo Building: MTP GUI Application (%BUILD_TYPE%)
echo ----------------------------------------------------------------------------

if /i "%BUILD_TYPE%"=="debug" (
    set CFLAGS=%CFLAGS% /Od /Zi /DDEBUG
    set LFLAGS=/DEBUG
) else (
    set CFLAGS=%CFLAGS% /O2 /DNDEBUG
    set LFLAGS=
)

echo Compiling mtp_gui.c...
cl %CFLAGS% /MD mtp_gui.c /link /subsystem:windows %GUI_LIBS% %LFLAGS% /out:mtp_gui.exe

if errorlevel 1 (
    echo.
    echo *** GUI BUILD FAILED ***
    goto :error
)

echo.
echo [SUCCESS] mtp_gui.exe built successfully!
for %%F in (mtp_gui.exe) do echo           Size: %%~zF bytes
echo.
goto :success

REM ============================================================================
REM Build Console application
REM ============================================================================
:build_console
echo Building: MTP Console Application (%BUILD_TYPE%)
echo ----------------------------------------------------------------------------

if /i "%BUILD_TYPE%"=="debug" (
    set CFLAGS=%CFLAGS% /Od /Zi /DDEBUG
    set LFLAGS=/DEBUG
) else (
    set CFLAGS=%CFLAGS% /O2 /DNDEBUG
    set LFLAGS=
)

echo Compiling mtp_transfer.c...
cl %CFLAGS% /MD mtp_transfer.c /link /subsystem:console %CON_LIBS% %LFLAGS% /out:mtp_transfer.exe

if errorlevel 1 (
    echo.
    echo *** CONSOLE BUILD FAILED ***
    goto :error
)

echo.
echo [SUCCESS] mtp_transfer.exe built successfully!
for %%F in (mtp_transfer.exe) do echo           Size: %%~zF bytes
echo.
goto :success

REM ============================================================================
REM Build all applications
REM ============================================================================
:build_all
echo Building: ALL MTP Applications (%BUILD_TYPE%)
echo ----------------------------------------------------------------------------
echo.

if /i "%BUILD_TYPE%"=="debug" (
    set CFLAGS=%CFLAGS% /Od /Zi /DDEBUG
    set LFLAGS=/DEBUG
) else (
    set CFLAGS=%CFLAGS% /O2 /DNDEBUG
    set LFLAGS=
)

REM Build GUI
echo [1/2] Compiling mtp_gui.c...
cl %CFLAGS% /MD mtp_gui.c /link /subsystem:windows %GUI_LIBS% %LFLAGS% /out:mtp_gui.exe
if errorlevel 1 (
    echo *** GUI build failed ***
    goto :error
)
echo      Done.
echo.

REM Build Console
echo [2/2] Compiling mtp_transfer.c...
cl %CFLAGS% /MD mtp_transfer.c /link /subsystem:console %CON_LIBS% %LFLAGS% /out:mtp_transfer.exe
if errorlevel 1 (
    echo *** Console build failed ***
    goto :error
)
echo      Done.
echo.

echo ============================================================================
echo                        ALL BUILDS SUCCESSFUL!
echo ============================================================================
echo.
echo Output files:
echo.
echo   mtp_gui.exe      - GUI application with Windows Explorer-style interface
for %%F in (mtp_gui.exe) do echo                      Size: %%~zF bytes
echo.
echo   mtp_transfer.exe - Console application with command-line interface
for %%F in (mtp_transfer.exe) do echo                      Size: %%~zF bytes
echo.
echo Both applications require the MTP KMDF driver to be installed.
echo.
goto :success

REM ============================================================================
REM Exit handlers
REM ============================================================================
:error
echo.
echo Build failed with errors.
endlocal
exit /b 1

:success
endlocal
exit /b 0
