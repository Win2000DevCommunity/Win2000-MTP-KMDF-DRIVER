@echo off
REM Build test app using the Windows 2000 SDK located in the workspace ('2000 sdk').
REM This forces the compiler to use legacy Windows 2000 headers and libs only.

SET SDKROOT=%~dp0..\..\..\2000 sdk
SET SDKINC=%SDKROOT%\Include
SET SDKLIB=%SDKROOT%\Lib

nREM Verify SDK include exists
IF NOT EXIST "%SDKINC%\Windows.h" (
  echo ERROR: Windows 2000 SDK headers not found at "%SDKINC%".
  echo Please ensure the '2000 sdk' folder is present in the workspace root.
  pause
  exit /b 1
)

necho Using Windows 2000 SDK from: %SDKROOT%

nREM Build and link using the 2000 SDK include/lib paths (puts SDKINC first)
cl /W3 /nologo /O2 /I "%SDKINC%" mtp_test.c /link /LIBPATH:"%SDKLIB%" /out:mtp_test.exe
if %errorlevel% equ 0 (
  echo Build succeeded: mtp_test.exe
) else (
  echo Build failed
)
pause
