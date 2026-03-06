# YIGITUX

YIGITUX is a fake CLI terminal project written in C, with Python-powered TUI tools.

Started as a fun learning project — now growing into something bigger!

> ⚠️ YIGITUX is not a real operating system. It is a fake shell designed for learning and experimentation.

---

## 🚀 Features

- Custom terminal prompt
- Modular command system
- Random number & letter generators
- Current time display
- Motivation messages (`fortune`)
- Developer jokes with TUI viewer (`joke`)
- Hidden easter eggs
- Fake hacker mode (`hackmode`)
- In-memory notepad (`notepad`)
- E-mail address generator (`makemailbro`)
- Password generator (`makepasswdbro`)
- TUI help viewer (`help`)
- ASCII art
- Cross-platform support (Linux, Windows, macOS)

---

## 🛠️ Build

Make sure you have GCC installed. Then compile with:

```bash
gcc main.c commands.c -o yigitux
```

Or use the build scripts:

```bash
# Linux
bash building-on-linux.sh

# Windows
building-on-windows.bat
```

---

## ▶️ Run

```bash
./yigitux
```

---

## 🐍 Python Tools

Some commands use Python-powered TUI tools. Make sure Python 3 is installed.

| File | Used by |
|------|---------|
| `yigitux_help.py` | `help` command |
| `yigitux_jokes.py` | `joke` command |
| `yigitux_makebros.py` | `makemailbro`, `makepasswdbro` commands |

No extra packages needed — only built-in Python modules are used!

---

## 💬 Examples

```
yigit-$ help         → Opens TUI help viewer
yigit-$ joke         → Opens TUI joke viewer
yigit-$ hackmode     → Fake hacker logs
yigit-$ echo Hello   → Hello
yigit-$ time         → 14:35:08
yigit-$ random       → Random number: 42
yigit-$ fortune      → Never give up on your projects!
```

---

## 📦 Languages

![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?style=flat&logo=python&logoColor=white)
![Shell](https://img.shields.io/badge/Shell-121011?style=flat&logo=gnu-bash&logoColor=white)

---

## 📄 License

Licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.

---

## 👤 Author

**Yiğit ALP** — 2026 — Version 1.4

🌐 [yigit.phomeds.com](https://yigit.phomeds.com)