# YIGITUX v1.4
# Copyright (c) 2026 Yiğit ALP
#
# This source code is licensed under the MIT License.
# See the LICENSE file in the project root for full license information.

import curses # Imports the curses thing

COMMANDS = [
    ("help",          "Lists all available commands."),
    ("about",         "Prints program name and license information."),
    ("echo",          "Prints back the text you provide."),
    ("clear",         "Clears the terminal screen."),
    ("time",          "Displays the current time in HH:MM:SS format."),
    ("random",        "Generates a random number between 0-99."),
    ("randlet",       "Gives you a random letter. Alternative to 'random'."),
    ("fortune",       "Gives you a random motivation message if you are sad!"),
    ("joke",          "Tells you some random fun developer facts."),
    ("whoami",        "Shows who you are... just for fun!"),
    ("hackmode",      "Fake hacker logs. Makes you look like a hacker for a few seconds!"),
    ("notepad",       "A simple in-memory notepad. Does not save anything."),
    ("makemailbro",   "Generates an e-mail address for you."),
    ("makepasswdbro", "Generates a random secure password."),
    ("easter-egg",    "Prints 'linux is kool' in ASCII art."),
    ("fixthebug",     "Applies bug spray to your code. A classic easter egg!"),
    ("showeasteregg", "Shows all the funny and cool hidden commands."),
    ("asciiart",      "Prints the alphabet in ASCII art style."),
    ("favrepo",       "Shows Yiğit's favourite GitHub repository."),
    ("credits",       "Shows the credits for YigiTux."),
    ("whichos",       "Tells you which OS you are using."),
    ("sourcecode",    "Opens a popup with the YigiTux source code link."),
    ("exit",          "Exits YigiTux. Goodbye!"),
]

def draw(stdscr):
    curses.curs_set(0)
    curses.start_color()
    curses.init_pair(1, curses.COLOR_BLACK, curses.COLOR_CYAN)   # selected
    curses.init_pair(2, curses.COLOR_CYAN,  curses.COLOR_BLACK)  # header
    curses.init_pair(3, curses.COLOR_WHITE, curses.COLOR_BLACK)  # normal
    curses.init_pair(4, curses.COLOR_YELLOW,curses.COLOR_BLACK)  # description

    selected = 0

    while True:
        stdscr.clear()
        h, w = stdscr.getmaxyx()

        left_w = 22
        right_w = w - left_w - 3

        # Header
        header = " YIGITUX — HELP "
        stdscr.attron(curses.color_pair(2) | curses.A_BOLD)
        stdscr.addstr(0, max(0, (w - len(header)) // 2), header)
        stdscr.attroff(curses.color_pair(2) | curses.A_BOLD)

        # Divider
        stdscr.attron(curses.color_pair(3))
        stdscr.addstr(1, 0, "─" * left_w + "┬" + "─" * (w - left_w - 2))
        stdscr.attroff(curses.color_pair(3))

        # Command list
        visible = h - 4
        start = max(0, selected - visible + 1)

        for i, (cmd, _) in enumerate(COMMANDS[start:start+visible]):
            row = 2 + i
            if row >= h - 2:
                break
            idx = start + i
            if idx == selected:
                stdscr.attron(curses.color_pair(1) | curses.A_BOLD)
                stdscr.addstr(row, 0, f" > {cmd:<{left_w - 3}}")
                stdscr.attroff(curses.color_pair(1) | curses.A_BOLD)
            else:
                stdscr.attron(curses.color_pair(3))
                stdscr.addstr(row, 0, f"   {cmd:<{left_w - 3}}")
                stdscr.attroff(curses.color_pair(3))

        # Vertical divider
        for row in range(2, h - 2):
            stdscr.attron(curses.color_pair(3))
            try:
                stdscr.addstr(row, left_w, "│")
            except:
                pass
            stdscr.attroff(curses.color_pair(3))

        # Description panel
        cmd_name, cmd_desc = COMMANDS[selected]
        stdscr.attron(curses.color_pair(2) | curses.A_BOLD)
        stdscr.addstr(2, left_w + 2, f"Command: {cmd_name}")
        stdscr.attroff(curses.color_pair(2) | curses.A_BOLD)

        stdscr.attron(curses.color_pair(4))
        stdscr.addstr(4, left_w + 2, "Description:")
        stdscr.attroff(curses.color_pair(4))

        stdscr.attron(curses.color_pair(3))
        # Word wrap description
        words = cmd_desc.split()
        line, row = "", 5
        for word in words:
            if len(line) + len(word) + 1 > right_w:
                stdscr.addstr(row, left_w + 2, line)
                row += 1
                line = word
            else:
                line = (line + " " + word).strip()
        if line:
            stdscr.addstr(row, left_w + 2, line)
        stdscr.attroff(curses.color_pair(3))

        # Footer
        stdscr.attron(curses.color_pair(2))
        stdscr.addstr(h - 2, 0, "─" * (w - 1))
        stdscr.addstr(h - 1, 0, " ↑↓ Navigate   q Quit ")
        stdscr.attroff(curses.color_pair(2))

        stdscr.refresh()

        key = stdscr.getch()
        if key == curses.KEY_UP and selected > 0:
            selected -= 1
        elif key == curses.KEY_DOWN and selected < len(COMMANDS) - 1:
            selected += 1
        elif key == ord('q') or key == 27:
            break

def main():
    curses.wrapper(draw)

if __name__ == "__main__":
    main()