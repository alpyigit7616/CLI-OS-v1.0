/*
 * YIGITUX v1.1
 * Copyright (c) 2026 Yiğit ALP
 *
 * This source code is licensed under the MIT License.
 * See the LICENSE file in the project root for full license information.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "commands.h"
#include <time.h> 

void cmd_time(char *input) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("%02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
}

void cmd_random(char *input) {
    srand(time(NULL));
    printf("Random number: %d\n", rand() % 100);
}

// Commands 
void handle_command(char *input)
{
    // Command help
    if (strcmp(input, "help") == 0) {
        printf("Available commands:\n");
        printf("help\nabout\nexit\necho\nclear\ntime\nrandom\nFor details, look to my README.md file (its in the source code!).\n");
    }

    // Command: about
    else if (strcmp(input, "about") == 0) {
        printf("YIGITUX v1.1\n Licensed under the MIT license.\n");
    }

    // Command(S): echo
    else if (strncmp(input, "echo ", 5) == 0)
    {
        printf("%s\n", input + 5);
    }

    else if (strcmp(input, "echo") == 0)
    {
        printf("\n");
    }

    // Command: clear
    else if (strcmp(input, "clear") == 0)
    {
        system("clear");
    }

    // Command: time
    else if(strcmp(input, "time") == 0){
        cmd_time(input);
    }

    // Command: random
    else if(strcmp(input, "random") == 0){
        cmd_random(input);
    }

    // Wrong command
    else {
        printf("Unknown command: %s\n", input);
    }
}