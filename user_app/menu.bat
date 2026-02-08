@echo off
REM ============================================================================
REM MTP File Transfer - Interactive Build Menu for Windows 2000
REM ============================================================================

setlocal enabledelayedexpansion

:menu
cls
echo.
echo  ============================================================================
echo                MTP File Transfer - Windows 2000 Build System
echo  ============================================================================
echo.
echo                            BUILD OPTIONS
echo.
echo      [1]  Build GUI Application          (mtp_gui.exe)
echo      [2]  Build Console Application      (mtp_transfer.exe)
echo      [3]  Build ALL Applications         (both)
echo.
echo      [4]  Build GUI (Debug)
echo      [5]  Build Console (Debug)
echo      [6]  Build ALL (Debug)
echo.
echo      [7]  Clean Build Artifacts
echo.
echo      [0]  Exit
echo.
echo  ============================================================================
echo.

set /p choice="  Select option [0-7]: "

if "%choice%"=="1" call :run_build gui
if "%choice%"=="2" call :run_build console
if "%choice%"=="3" call :run_build all
if "%choice%"=="4" call :run_build debug gui
if "%choice%"=="5" call :run_build debug console
if "%choice%"=="6" call :run_build debug all
if "%choice%"=="7" call :run_build clean
if "%choice%"=="0" goto :exit

goto :menu

:run_build
echo.
echo  Running: build.bat %*
echo  ----------------------------------------------------------------------------
echo.
call build.bat %*
echo.
echo  ----------------------------------------------------------------------------
echo  Press any key to return to menu...
pause >nul
goto :eof

:exit
echo.
echo  Goodbye!
echo.
endlocal
exit /b 0
