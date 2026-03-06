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

echo -e "${YELLOW}Building with gcc...${RESET}"
gcc main.c command.c -o cli-os
echo -e ${YELLOW}Build finished! Launching YigiTux${RESET}"
./cli-os
