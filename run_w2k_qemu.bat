@echo off
setlocal

set "PATH=C:\Users\Win2000\msys64\mingw64\bin;C:\Users\Win2000\msys64\usr\bin;%PATH%"

set "QEMU_EXE=C:\Users\Win2000\Downloads\qemu\build\qemu-system-i386.exe"
set "QEMU_DIR=C:\Users\Win2000\Downloads\qemu"
set "DISK_IMG=C:\Users\Win2000\Documents\QEMU\Windows2000-Pro-SP4\win2000-pro-sp4.img"
set "CD_IMG=C:\Users\Win2000\Documents\QEMU\Windows2000-Pro-SP4\kmdf-mtp-install.iso"

set "PHONE_DIR=C:/Users/Win2000/Documents/QEMU/mtp_phone_storage"

echo Starting Windows 2000 QEMU with MTP Installation CD and Emulated MTP Phone...
echo VNC: 127.0.0.1:5900 (display :0)
echo Telnet Monitor: 127.0.0.1:4445
echo Phone Storage: %PHONE_DIR%

"%QEMU_EXE%" ^
  -name "W2K - MTP KMDF Driver Test" ^
  -machine pc-i440fx-9.2,accel=tcg ^
  -cpu pentium3 ^
  -smp 2,sockets=1,cores=2,threads=1 ^
  -m 2048 ^
  -L "%QEMU_DIR%" ^
  -drive "file=%DISK_IMG%,format=raw,if=ide,index=0,media=disk" ^
  -cdrom "%CD_IMG%" ^
  -boot order=c,menu=off ^
  -nic none ^
  -device piix3-usb-uhci,id=uhci ^
  -device "usb-mtp,bus=uhci.0,rootdir=%PHONE_DIR%,desc=Android Phone (MTP),readonly=off" ^
  -display vnc=127.0.0.1:0 ^
  -monitor telnet:127.0.0.1:4445,server=on,wait=off

