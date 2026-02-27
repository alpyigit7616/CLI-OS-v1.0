# CLI-OS
CLI-OS is a simple command-line interface project written in C.

This project was created for learning purposes.
It focuses on basic input handling and simple command logic.

It is not a real operating system.

## 🚀 Features:

- Custom terminal prompt

- Basic command system

- **Built-in commands: help, about, exit, echo, clear, time, random**

- Easy to extend with new commands

## Build:
Compile with both source files:
```bash
gcc main.c commands.c -o cli-os
```
## Run:
```bash
./cli-os
```

## Examples:
```
yigit-$ help
Available commands: help, about, exit, echo, clear, time, random

yigit-$ echo Hello CLI-OS
Hello CLI-OS

yigit-$ time
14:35:08

yigit-$ random
Random number: 42
```
## License:
Licensed under the MIT License.
See the LICENSE file for more information.

## Author:
Yiğit ALP — 2026
Version 1.1