# YIGITUX v1.4
# Copyright (c) 2026 Yiğit ALP
#
# This source code is licensed under the MIT License.
# See the LICENSE file in the project root for full license information.

import curses

def draw_box(stdscr, y, x, h, w, title=""):
    stdscr.attron(curses.color_pair(2))
    stdscr.addstr(y, x, "┌" + "─" * (w - 2) + "┐")
    for i in range(1, h - 1):
        stdscr.addstr(y + i, x, "│" + " " * (w - 2) + "│")
    stdscr.addstr(y + h - 1, x, "└" + "─" * (w - 2) + "┘")
    stdscr.attroff(curses.color_pair(2))
    if title:
        stdscr.attron(curses.color_pair(2) | curses.A_BOLD)
        stdscr.addstr(y, x + 2, f" {title} ")
        stdscr.attroff(curses.color_pair(2) | curses.A_BOLD)

def main(stdscr):
    JOKES = [
        "A random programmer always prefers dark mode.",
        "My little brother finds a bug, now he is spraying bug spray on the screen.",
        "Python? No, I LIKE C!!!",
        "There are 10 types of people: those who understand binary and those who don't.",
        "Debugging: Removing the needles from the haystack."
        "press q to quit"
    ]

    curses.start_color()
    curses.init_pair(1, curses.COLOR_YELLOW, curses.COLOR_BLACK)
    curses.init_pair(2, curses.COLOR_CYAN,   curses.COLOR_BLACK)
    curses.init_pair(3, curses.COLOR_WHITE,  curses.COLOR_BLACK)
    curses.init_pair(4, curses.COLOR_BLACK,  curses.COLOR_CYAN)

    selected = 0

    while True:
        stdscr.clear()
        draw_box(stdscr, 1, 2, 9, 60, "YIGITUX JOKES")

        for i, joke in enumerate(JOKES):
            if i == selected:
                stdscr.attron(curses.color_pair(4) | curses.A_BOLD)
                stdscr.addstr(3 + i, 4, f"> {joke[:55]}")
                stdscr.attroff(curses.color_pair(4) | curses.A_BOLD)
            else:
                stdscr.attron(curses.color_pair(3))
                stdscr.addstr(3 + i, 4, f"  {joke[:55]}")
                stdscr.attroff(curses.color_pair(3))

        stdscr.refresh()
        key = stdscr.getch()
        if key == curses.KEY_UP and selected > 0:
            selected -= 1
        elif key == curses.KEY_DOWN and selected < len(JOKES) - 1:
            selected += 1
        elif key == ord('q'):
            break

curses.wrapper(main)