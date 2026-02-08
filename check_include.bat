@echo off
rem check_include.bat - verify Windows 2000 DDK includes are present and preferred
setlocal enabledelayedexpansion
echo Checking INCLUDE for Windows 2000 DDK (3790.1830)...
echo %INCLUDE% | find /I "3790.1830" >nul
if %errorlevel% neq 0 (
  echo ERROR: Windows 2000 include path (3790.1830) NOT found in %%INCLUDE%%.
  echo Please run the W2K DDK setenv.bat (the one in this workspace under \"3790.1830\") before building.
  exit /b 1
)
echo Found 3790.1830 in INCLUDE.
echo Checking whether 7600 (newer) include path is present...
echo %INCLUDE% | find /I "7600.16385.1" >nul
if %errorlevel% equ 0 (
  echo WARNING: A newer SDK (7600.16385.1) appears in %%INCLUDE%%.
  echo Make sure the 3790.1830 include path appears BEFORE the 7600.16385.1 path so W2K headers are used for non-WDF APIs.
) else (
  echo No newer SDK path detected in %%INCLUDE%%.
)
echo Done.
endlocal
exit /b 0
