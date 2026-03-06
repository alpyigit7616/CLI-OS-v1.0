# YIGITUX v1.3
# Copyright 2026 (c) Yiğit ALP
#
# This source code is licensed under the MIT License.
# See the LICENSE file in the project root for full license information.

#!/bin/bash

# Colors
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
RESET="\033[0m"

echo -e "${GREEN}---------------------------- YIGITUX INSTALLING GCC ----------------------------${RESET}"
# 1st question
echo -e "${RED}Question 1${RESET} Which distro do you use? (arch, fedora, debian, ubuntu)"
read -p "> " DISTRO

# Loop
while true; do
# Downloading gcc for arch
if [[ "$DISTRO" == "arch" ]]; then
    echo -e "${YELLOW}Downloading gcc with pacman...${RESET}"
    sudo pacman -S base-devel
    echo -e "${GREEN}OK: Successfully installed gcc for Arch Linux!${RESET}"
    break

# Downloading gcc for fedora
elif [[ "$DISTRO" == "fedora" ]]; then
    echo -e "${YELLOW}Downloading gcc with dnf...${RESET}"
    sudo dnf install gcc
    echo -e "${GREEN}OK: Successfully installed gcc for Fedora!${RESET}"
    break

# Downloading gcc for debian and ubuntu systems
elif [[ "$DISTRO" == "debian" ]] || [[ "$DISTRO" == "ubuntu" ]]; then
    echo -e "${YELLOW}Downloading gcc with apt...${RESET}"
    sudo apt install gcc
    echo -e "${GREEN}OK: Successfully installed gcc for Ubuntu/Debian!${RESET}"
    break

else
    echo -e "${RED}Error: Please type a valid option!${RESET}"
fi

done