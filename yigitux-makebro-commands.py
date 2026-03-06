# YIGITUX v1.4
# Copyright (c) 2026 Yiğit ALP
#
# This source code is licensed under the MIT License.
# See the LICENSE file in the project root for full license information.

import curses
import random
import string
import sys

def draw_box(stdscr, y, x, h, w, title=""):
    stdscr.attron(curses.color_pair(2))
    stdscr.addstr(y, x, "┌" + "─" * (w - 2) + "┐")
    for i in range(1, h - 1):
        stdscr.addstr(y + i, x, "│" + " " * (w - 2) + "│")
    stdscr.addstr(y + h - 1, x, "└" + "─" * (w - 2) + "┘")
    if title:
        stdscr.attron(curses.color_pair(2) | curses.A_BOLD)
        stdscr.addstr(y, x + 2, f" {title} ")
    stdscr.attroff(curses.color_pair(2) | curses.A_BOLD)

def input_field(stdscr, y, x, max_w, secret=False):
    curses.curs_set(1)
    text = ""
    while True:
        stdscr.attron(curses.color_pair(3))
        display = "*" * len(text) if secret else text
        stdscr.addstr(y, x, (display + " " * max_w)[:max_w])
        stdscr.move(y, x + len(text))
        stdscr.attroff(curses.color_pair(3))
        stdscr.refresh()
        key = stdscr.getch()
        if key in (10, 13):
            break
        elif key in (127, curses.KEY_BACKSPACE):
            text = text[:-1]
        elif 32 <= key <= 126 and len(text) < max_w - 1:
            text += chr(key)
    curses.curs_set(0)
    return text

def make_mail(stdscr):
    h, w = stdscr.getmaxyx()
    bh, bw = 16, 50
    by, bx = (h - bh) // 2, (w - bw) // 2

    stdscr.clear()
    draw_box(stdscr, by, bx, bh, bw, "MAKEMAILBRO")

    stdscr.attron(curses.color_pair(4) | curses.A_BOLD)
    stdscr.addstr(by + 2, bx + 2, "Create your e-mail address!")
    stdscr.attroff(curses.color_pair(4) | curses.A_BOLD)

    stdscr.attron(curses.color_pair(3))
    stdscr.addstr(by + 4, bx + 2, "Username:")
    stdscr.attroff(curses.color_pair(3))
    stdscr.refresh()
    username = input_field(stdscr, by + 5, bx + 2, bw - 4)

    # Service selection
    services = ["gmail", "outlook", "proton"]
    domains  = {"gmail": "@gmail.com", "outlook": "@outlook.com", "proton": "@proton.me"}
    sel = 0

    while True:
        stdscr.attron(curses.color_pair(3))
        stdscr.addstr(by + 7, bx + 2, "Select service (←→ to choose, Enter to confirm):")
        stdscr.attroff(curses.color_pair(3))

        for i, svc in enumerate(services):
            if i == sel:
                stdscr.attron(curses.color_pair(1) | curses.A_BOLD)
                stdscr.addstr(by + 8, bx + 2 + i * 12, f" {svc} ")
                stdscr.attroff(curses.color_pair(1) | curses.A_BOLD)
            else:
                stdscr.attron(curses.color_pair(3))
                stdscr.addstr(by + 8, bx + 2 + i * 12, f" {svc} ")
                stdscr.attroff(curses.color_pair(3))

        stdscr.refresh()
        key = stdscr.getch()
        if key == curses.KEY_LEFT and sel > 0:
            sel -= 1
        elif key == curses.KEY_RIGHT and sel < len(services) - 1:
            sel += 1
        elif key in (10, 13):
            break

    email = username + domains[services[sel]]

    stdscr.attron(curses.color_pair(4) | curses.A_BOLD)
    stdscr.addstr(by + 10, bx + 2, "Your e-mail address:")
    stdscr.attroff(curses.color_pair(4) | curses.A_BOLD)

    stdscr.attron(curses.color_pair(1) | curses.A_BOLD)
    stdscr.addstr(by + 11, bx + 2, f" {email} ")
    stdscr.attroff(curses.color_pair(1) | curses.A_BOLD)

    stdscr.attron(curses.color_pair(3))
    stdscr.addstr(by + 13, bx + 2, "Press any key to exit...")
    stdscr.attroff(curses.color_pair(3))
    stdscr.refresh()
    stdscr.getch()

def make_passwd(stdscr):
    h, w = stdscr.getmaxyx()
    bh, bw = 18, 54
    by, bx = (h - bh) // 2, (w - bw) // 2

    stdscr.clear()
    draw_box(stdscr, by, bx, bh, bw, "MAKEPASSWDBRO")

    stdscr.attron(curses.color_pair(4) | curses.A_BOLD)
    stdscr.addstr(by + 2, bx + 2, "Generate a secure password!")
    stdscr.attroff(curses.color_pair(4) | curses.A_BOLD)

    # Length selection
    length = 16
    while True:
        stdscr.attron(curses.color_pair(3))
        stdscr.addstr(by + 4, bx + 2, "Password length (←→, Enter to confirm):")
        stdscr.addstr(by + 5, bx + 2, f"  Length: ")
        stdscr.attroff(curses.color_pair(3))

        stdscr.attron(curses.color_pair(1) | curses.A_BOLD)
        stdscr.addstr(by + 5, bx + 11, f" {length:2d} ")
        stdscr.attroff(curses.color_pair(1) | curses.A_BOLD)

        stdscr.attron(curses.color_pair(3))
        stdscr.addstr(by + 5, bx + 16, "(8-64)")
        stdscr.attroff(curses.color_pair(3))

        stdscr.refresh()
        key = stdscr.getch()
        if key == curses.KEY_LEFT and length > 8:
            length -= 1
        elif key == curses.KEY_RIGHT and length < 64:
            length += 1
        elif key in (10, 13):
            break

    # Symbols toggle
    use_symbols = False
    while True:
        stdscr.attron(curses.color_pair(3))
        stdscr.addstr(by + 7, bx + 2, "Include symbols? (!@#$%^&*)  ")
        stdscr.attroff(curses.color_pair(3))

        label = " YES " if use_symbols else " NO  "
        stdscr.attron(curses.color_pair(1) | curses.A_BOLD)
        stdscr.addstr(by + 8, bx + 2, label)
        stdscr.attroff(curses.color_pair(1) | curses.A_BOLD)

        stdscr.attron(curses.color_pair(3))
        stdscr.addstr(by + 8, bx + 8, " ← Space to toggle, Enter to confirm")
        stdscr.attroff(curses.color_pair(3))

        stdscr.refresh()
        key = stdscr.getch()
        if key == ord(' '):
            use_symbols = not use_symbols
        elif key in (10, 13):
            break

    # Generate password
    pool = string.ascii_letters + string.digits
    if use_symbols:
        pool += "!@#$%^&*()-_=+[]{}"
    password = ''.join(random.choices(pool, k=length))

    stdscr.attron(curses.color_pair(4) | curses.A_BOLD)
    stdscr.addstr(by + 10, bx + 2, "Your password:")
    stdscr.attroff(curses.color_pair(4) | curses.A_BOLD)

    stdscr.attron(curses.color_pair(1) | curses.A_BOLD)
    stdscr.addstr(by + 11, bx + 2, f" {password} ")
    stdscr.attroff(curses.color_pair(1) | curses.A_BOLD)

    stdscr.attron(curses.color_pair(3))
    stdscr.addstr(by + 13, bx + 2, "Save it somewhere safe!")
    stdscr.addstr(by + 15, bx + 2, "Press any key to exit...")
    stdscr.attroff(curses.color_pair(3))
    stdscr.refresh()
    stdscr.getch()

def main(stdscr, mode):
    curses.curs_set(0)
    curses.start_color()
    curses.init_pair(1, curses.COLOR_BLACK, curses.COLOR_CYAN)
    curses.init_pair(2, curses.COLOR_CYAN,  curses.COLOR_BLACK)
    curses.init_pair(3, curses.COLOR_WHITE, curses.COLOR_BLACK)
    curses.init_pair(4, curses.COLOR_YELLOW,curses.COLOR_BLACK)

    if mode == "mail":
        make_mail(stdscr)
    elif mode == "passwd":
        make_passwd(stdscr)

if __name__ == "__main__":
    mode = sys.argv[1] if len(sys.argv) > 1 else "mail"
    curses.wrapper(main, mode)