/*
 * YIGITUX v1.2
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

// ------------------------
// Command: time
// Displays the current time in HH:MM:SS format
// ------------------------
void cmd_time(char *input) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("%02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
}

// ------------------------
// Command: random
// Generates and prints a random number between 0-99
// ------------------------
void cmd_random(char *input) {
    srand(time(NULL));
    printf("Random number: %d\n", rand() % 100);
}

// ------------------------
// Command: help
// Lists all available commands
// ------------------------
void cmd_help(char *input) {
    printf("Available commands:\n");
    printf("help\nabout\nexit\necho\nclear\ntime\nrandom\neaster-egg\nfortune\njoke\nfixthebug\nshoweasteregg\nFor details, look to my README.md file (its in the source code!).\n");
}

// Command: 

// ------------------------
// Command: about
// Prints program name and license information
// ------------------------
void cmd_about(char *input) {
    printf("YIGITUX v1.2\n Licensed under the MIT license.\n");
}

// ------------------------
// Command: echo
// Prints back the text provided by the user
// ------------------------
void cmd_echo(char *input) {
    if (strlen(input) > 5) {
        printf("%s\n", input + 5); // Skip "echo "
    } else {
        printf("\n");
    }
}

// ------------------------
// Command: clear
// Clears the terminal screen
// ------------------------
void cmd_clear(char *input) {
    system("clear");
}

// ------------------------
// Command: easter-egg
// Just a command i developed for fun :)
// ------------------------
void cmd_easter_egg(char *input) {
    printf(".__  .__                      .__          __                .__   \n");
    printf("|  | |__| ____  __ _____  ___ |__| ______ |  | ______   ____ |  | \n");
    printf("|  | |  |/    \\|  |  \\  \\/  / |  |/  ___/ |  |/ /  _ \\ /  _ \\|  |  \\\n");
    printf("|  |_|  |   |  \\  |  />    <  |  |\\___ \\  |    <  <_> |  <_> )  |__\n");
    printf("|____/__|___|  /____//__/\\_ \\ |__/____  > |__|_ \\____/ \\____/|____/\n");
    printf("             \\/            \\/         \\/       \\/                  \n");
    printf("\n");
    printf("You found the 'linux is kool' easter egg!\n");
}

// ------------------------
// Command: fortune
// Gives you a random motivation message, if you are sad!
// ------------------------
void cmd_fortune(char *input) {
    // Motivation messages
    char *fortunes[] = {
        "Don't be sad, everything will be fine!",
        "Maybe you need to fork my project!",
        "Coding is good, but not vibe coding!!", // Do not use AI too much while coding something!!
        "Okay... Now just take a deep breathe brother.", // Oxygen is cool!
        "Never give up on your projects!" // My biggest mistake :(
    };

    int num_fortunes = sizeof(fortunes) / sizeof(fortunes[0]);
    
    // Seed for randomness
    srand(time(NULL));
    
    // Pick a random index
    int index = rand() % num_fortunes;
    
    printf("%s\n", fortunes[index]);
}

// ------------------------
// Command: fixthebug
// Just another funny easter egg, because i am bored!
// ------------------------
void cmd_fix_a_bug(char *input) {
    printf("Fixing the bug...\n");
    printf("Applying the spray...\n");
    printf("Sucsessfully removed the bug!");
    printf("If you want more easter eggs, type 'showeasteregg' you can see all the cool commands.\n");
}

// ------------------------
// Command: showeasteregg
// Shows you all funny and cool commands in yigitux
// ------------------------
void cmd_showingfun(char *input) {
    printf("Sure! Here, all funny commands:\nfixthebug: just a bad joke, i know!\neaster-egg: types 'linux is kool' whit ASCII art.\njoke: Tells you some developer facts! (They are not so funny!)\nfortune: just some messages.\n");
}

// ------------------------
// Command: joke
// Tells you some random fun developer facts :D
// ------------------------
void cmd_joke(char *input){
    char *jokes[] = {
        "A random programmer always prefers dark mode. Guess who is him/her?", // Everybody prefer dark mode, right?
        "My little brother finds a bug on his code, now he is spraying bug spray on the screen.", // What a creative fix!
        "Fact: 2026 developers use ChatGPT, but not a random indian guy!", // He is crying now! (du du de de da deu deu du!)
        "Python? No, I LIKE C!!!", // Lol its my favorite language
        "There are 10 types of people: those who understand binary and those who don't.", // haha, where is the funny part?
        "Debugging: Removing the needles from the haystack." // This one is my favorite joke!
    };

    // Number of jokes
    int num_jokes = sizeof(jokes) / sizeof(jokes[0]);

    // Seed for randomness
    srand(time(NULL));

    // Pick a random joke
    int index = rand() % num_jokes;

    // Print the joke
    printf("%s\n", jokes[index]);
}

// ------------------------
// Handle command
// Maps user input to the corresponding function
// ------------------------
void handle_command(char *input)
{
    if(strcmp(input, "help") == 0) cmd_help(input);
    else if(strcmp(input, "about") == 0) cmd_about(input);
    else if(strncmp(input, "echo ", 5) == 0 || strcmp(input, "echo") == 0) cmd_echo(input);
    else if(strcmp(input, "clear") == 0) cmd_clear(input);
    else if(strcmp(input, "time") == 0) cmd_time(input);
    else if(strcmp(input, "random") == 0) cmd_random(input);
    else if(strcmp(input, "easter-egg") == 0) cmd_easter_egg(input);
    else if(strcmp(input, "fortune") == 0) cmd_fortune(input);
    else if(strcmp(input, "joke") == 0) cmd_joke(input);
    else if(strcmp(input, "fixthebug") == 0) cmd_fix_a_bug(input);
    else if(strcmp(input, "showeasteregg") == 0) cmd_showingfun(input);
    else {
        printf("Unknown command: %s\n", input);
    }
}