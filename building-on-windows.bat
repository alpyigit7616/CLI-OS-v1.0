@echo off
:: YIGITUX v1.3
:: Copyright 2026 (c) Yiğit ALP
::
:: This source code is licensed under the MIT License.
:: See the LICENSE file in the project root for full license information.

title YIGITUX - Build

:: Color codes
set "YELLOW=[33m"
set "GREEN=[32m"
set "RED=[31m"
set "RESET=[0m"

echo %YELLOW%Building with gcc...%RESET%
gcc main.c command.c -o cli-os.exe

if %errorlevel% neq 0 (
    echo %RED%Error: Build failed!%RESET%
    pause
    exit /b 1
)

echo %YELLOW%Build finished! Launching YigiTux%RESET%
cli-os.exe