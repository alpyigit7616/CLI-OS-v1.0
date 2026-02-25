#include <stdio.h>
#include <string.h>
#include "commands.h"

void handle_command(char *input)
{
    if (strcmp(input, "help") == 0) {
        printf("Available commands:\n");
        printf("help\nabout\nexit\n");
    }
    else if (strcmp(input, "about") == 0) {
        printf("CLI-OS v1.0 Alpha\n");
    }
    else {
        printf("Unknown command: %s\n", input);
    }
}