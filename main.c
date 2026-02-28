/*
 * YIGITUX v1.1
 * Copyright (c) 2026 Yiğit ALP
 *
 * This source code is licensed under the MIT License.
 * See the LICENSE file in the project root for full license information.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

// Define, indef and other stuff
#define MAX_INPUT 256

int main(){

    char input[MAX_INPUT]; // Input variable

    printf("######################################\n");
    printf("#                                    #\n");
    printf("#          YIGITUX v1.1              #\n");
    printf("#   Licensed under the MIT license.  #\n");
    printf("#                                    #\n");
    printf("######################################\n");
    
    printf("\nUse Ctrl+C to exit.\n");
    printf("\n");

    while (1)
    {
        // Prompt
        printf("yigitux-user-$ ");

        // User İnput
        fgets(input, MAX_INPUT, stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0)
        {
            break;
        }  

        // Commands
        handle_command(input);
    }

    return 0;
    
}
