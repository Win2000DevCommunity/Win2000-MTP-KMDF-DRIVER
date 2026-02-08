@echo off
REM ====================================================================
REM   MTP Driver - Windows 7 DDK Direct Compilation (W2K Target)
REM   Based on user's working command line from years ago
REM ====================================================================

setlocal

echo.
echo ====================================================================
echo   MTP Driver - Win7 DDK Compiler, W2K Target
echo ====================================================================
echo.

set WIN7_DDK=C:\WinDDK\7600.16385.1
set OUTPUT_DIR=objchk_w2k_x86\i386

echo [SETUP]
echo   DDK: %WIN7_DDK%
echo   Output: %OUTPUT_DIR%
echo.

REM Clean and create output
if exist %OUTPUT_DIR% rmdir /s /q %OUTPUT_DIR%
mkdir %OUTPUT_DIR%

REM Use Win7 DDK compiler
set PATH=%WIN7_DDK%\bin\x86;%WIN7_DDK%\bin\x86\x86;%PATH%

echo [COMPILE] Using exact flags from your working build...
echo.

cl -nologo ^
 -Ii386\ -I. ^
 -I%WIN7_DDK%\inc\mfc42 ^
 -I%WIN7_DDK%\inc ^
 -I%WIN7_DDK%\inc\api ^
 -I%WIN7_DDK%\inc\ddk ^
 -I%WIN7_DDK%\inc\crt ^
 -I%WIN7_DDK%\inc\wdf\kmdf\1.9 ^
 -I%OUTPUT_DIR% ^
 -D_X86_=1 -DX86=1 -Di386=1 ^
 -DSTD_CALL -DCONDITION_HANDLING=1 ^
 -DNT_UP=1 -DNT_INST=0 -DWIN32=100 -D_NT1X_=100 -DWINNT=1 ^
 -D_WIN32_WINNT=0x0500 /DWINVER=0x0500 -D_WIN32_IE=0x0600 ^
 -DWIN32_LEAN_AND_MEAN=1 -DDEVL=1 -DBUILDMACHINE=WinDDK -DFPO=0 ^
 -DNDEBUG -D_DLL=1 /DDRIVER ^
 /c /Zp8 /Gy -cbstring /W3 /Gz /Gm- /GR- /GF /Gs- -Z7 /Od /Oi /Oy- ^
 -FI%WIN7_DDK%\inc\api\warning.h ^
 .\Driver.c .\Device.c .\Usb.c .\Mtp.c

if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] Compilation failed!
    pause
    exit /b 1
)

echo.
echo [LINK] Linking driver...

REM Create library list file
echo %WIN7_DDK%\lib\win7\i386\wdm.lib > link.tmp
echo %WIN7_DDK%\lib\win7\i386\ntoskrnl.lib >> link.tmp
echo %WIN7_DDK%\lib\win7\i386\hal.lib >> link.tmp
echo %WIN7_DDK%\lib\win7\i386\BufferOverflowK.lib >> link.tmp
echo %WIN7_DDK%\lib\win7\i386\ntstrsafe.lib >> link.tmp
echo %WIN7_DDK%\lib\win7\i386\usbd.lib >> link.tmp
echo %WIN7_DDK%\lib\wdf\kmdf\i386\1.9\WdfDriverEntry.lib >> link.tmp
echo %WIN7_DDK%\lib\wdf\kmdf\i386\1.9\WdfLdr.lib >> link.tmp

link -out:%OUTPUT_DIR%\mtp.sys -machine:ix86 ^
 /DRIVER /SUBSYSTEM:NATIVE /ENTRY:FxDriverEntry ^
 /DEBUG /DEBUGTYPE:CV /NODEFAULTLIB ^
 /RELEASE /INCREMENTAL:NO /FULLBUILD /WX- ^
 /MERGE:_PAGE=PAGE /MERGE:_TEXT=.text /SECTION:INIT,d ^
 /ALIGN:0x80 /OSVERSION:5.0 ^
 /IGNORE:4001,4037,4039,4065,4070,4078,4087,4089,4198 ^
 @link.tmp ^
 Driver.obj Device.obj Usb.obj Mtp.obj

if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] Linking failed!
    pause
    exit /b 1
)

echo.
echo ====================================================================
echo   BUILD SUCCESSFUL!
echo ====================================================================
echo.
dir %OUTPUT_DIR%\mtp.sys
echo.

pause
