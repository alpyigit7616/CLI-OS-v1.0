@echo off
:: YIGITUX v1.3
:: Copyright 2026 (c) Yiğit ALP
::
:: This source code is licensed under the MIT License.
:: See the LICENSE file in the project root for full license information.

title YIGITUX - GCC Installer

:: Enable ANSI colors (Windows 10+)
reg query HKCU\Console /v VirtualTerminalLevel >nul 2>&1 || reg add HKCU\Console /v VirtualTerminalLevel /t REG_DWORD /d 1 /f >nul 2>&1

:: Color codes
set "GREEN=[32m"
set "RED=[31m"
set "YELLOW=[33m"
set "RESET=[0m"

echo %GREEN%---------------------------- YIGITUX INSTALLING GCC ----------------------------%RESET%

:: 1st question
echo %RED%Question 1%RESET% Which package manager do you use? (choco, scoop, winget)
set /p DISTRO="> "

:: Loop
:loop

if /i "%DISTRO%"=="choco" (
    echo %YELLOW%Downloading gcc with Chocolatey...%RESET%
    choco install mingw -y
    if %errorlevel% equ 0 (
        echo %GREEN%OK: Successfully installed gcc via Chocolatey!%RESET%
    ) else (
        echo %RED%Error: Installation failed. Make sure Chocolatey is installed.%RESET%
    )
    goto end
)

if /i "%DISTRO%"=="scoop" (
    echo %YELLOW%Downloading gcc with Scoop...%RESET%
    scoop install gcc
    if %errorlevel% equ 0 (
        echo %GREEN%OK: Successfully installed gcc via Scoop!%RESET%
    ) else (
        echo %RED%Error: Installation failed. Make sure Scoop is installed.%RESET%
    )
    goto end
)

if /i "%DISTRO%"=="winget" (
    echo %YELLOW%Downloading gcc with WinGet...%RESET%
    winget install -e --id StrawberryPerl.StrawberryPerl
    winget install -e --id MSYS2.MSYS2
    if %errorlevel% equ 0 (
        echo %GREEN%OK: Successfully installed gcc via WinGet (MSYS2)!%RESET%
        echo %YELLOW%Note: Run MSYS2 and execute: pacman -S mingw-w64-ucrt-x86_64-gcc%RESET%
    ) else (
        echo %RED%Error: Installation failed. Make sure WinGet is installed.%RESET%
    )
    goto end
)

echo %RED%Error: Please type a valid option! (choco, scoop, winget)%RESET%
set /p DISTRO="> "
goto loop

:end
pause