/*
 * YIGITUX v1.3
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
#include <unistd.h>

// Ifndef, ifdef, define and other stuff
#define MAX_INPUT 256

// These codes makes my project cross-platform, so it can runs anywhere.

// If there is a windows these codes will be runned
#ifdef _WIN32
#include <windows.h>
#define sleep_sec(x) Sleep((x) * 1000)
#define sleep_ms(x)  Sleep(x)

// If there is a Linux or Macos these codes will be runned
#else
#include <unistd.h>
#define sleep_sec(x) sleep(x)
#define sleep_ms(x)  usleep((x) * 1000)
#endif

// This one is for the 'whichos' command
#ifdef _WIN32
#define os_is() printf("You are using Windows!\n")
#else
#define os_is() printf("You are using Linux or Macos! (Maybe Android)\n");
#endif

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
    printf("help\nabout\nexit\necho\nclear\ntime\nrandom\neaster-egg\nfortune\njoke\nfixthebug\nshoweasteregg\nwhoami\nrandlet\nnotepad\nhackmode\nfavrepo\nwhichos\nasciiart\ncredits\nmakemailbro\nmakepasswdbro\nFor details, look to my README.md file (its in the source code!).\n");
}

// Command: 

// ------------------------
// Command: about
// Prints program name and license information
// ------------------------
void cmd_about(char *input) {
    printf("YIGITUX v1.3\n Licensed under the MIT license.\n");
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
// Command: whichos
// Tells you which OS do you use.
// ------------------------
void cmd_whichos(char *input){
    os_is();
}

// ------------------------
// Command: whoami
// Shows you who are you, just for fun! (All this commands are for fun)
// ------------------------
void cmd_whoareyou(char *input) {
    char *answers[] = {
        "You are the guy who uses bug spray.",
        "You are the guy who uses LiveBoot on his/her own phone",
        "You are root!",
        "You are biggest Linus Torvalds fan!", // I like him!
        "You are just a random guy, no worries", // Everything is a guy for me
        "You are.. You are using my project!",
        "You are you!" // Damn!
    };
    int num_uare = sizeof(answers) / sizeof(answers[0]);

    // Seed for randomness
    srand(time(NULL));

    // Pick a random joke
    int index = rand() % num_uare;

    // Print the joke
    printf("%s\n", answers[index]);
}

// ------------------------
// Command: randlet
// Gives you a random letter, alternative to "random" command.
// ------------------------
void cmd_randlet(char *input) {

    char letters[26];

    for(int i = 0; i < 26; i++) {
        letters[i] = 'A' + i;
    }

    int index = rand() % 26;
    printf("Random letter: %c\n", letters[index]);
}

// ------------------------
// Command: hackmode
// Some cool fake logs, makes you a hacker for a few seconds!
// ------------------------
void cmd_hackmode(char *input) {

    printf("YigiTux HackMode is loading");
    fflush(stdout);

    for(int i = 0; i < 3; i++) {
        sleep_sec(1);
        printf(".");
        fflush(stdout);
    }

    printf("\nWelcome to the YigiTux HackMode!\n");
    sleep_sec(1);

    printf("[+] Initializing kernel modules...\n");
    sleep_ms(500);

    printf("[+] Scanning network interfaces...\n");
    sleep_ms(500);

    printf("[+] Bypassing firewall...\n");
    sleep_sec(1);

    printf("[+] Accessing secure shell...\n");
    sleep_sec(1);

    printf("Password: ********\n");
    sleep_ms(300);

    printf("[+] Decrypting credentials...\n");
    sleep_sec(1);

    printf("[+] Access granted.\n\n");
    sleep_ms(500);

    char *steps[] = {
        "Injecting payload...",
        "Escalating privileges...",
        "Hijacking session...",
        "Establishing backdoor...",
        "Done."
    };

    int count = sizeof(steps) / sizeof(steps[0]);

    for(int i = 0; i < count; i++) {
        printf("%s\n", steps[i]);
        sleep_ms(300);
    }

    printf("\nHackMode session terminated.\n");
}

// ------------------------
// Command: favrepo
// Tells you my favourite github repository, also this is for fun!
// ------------------------
void cmd_favrepo(char *input){
    printf("My favourite github repository is 'linux kernel source tree' from Linus Torvalds!\n");
    printf("https://github.com/torvalds/linux\n");
}

// ------------------------
// Command: notepad
// Micro and Vim alternative notepad, it dosent save anything
// ------------------------
void cmd_notepad(char *input) {
    system("clear");

    char buffer[100][256];
    int line_count = 0;
    char line[256];

    printf("=== YIGITUX NOTEPAD ===\n");
    printf("Type your text below.\n");
    printf("Commands:\n");  
    printf(":q       -> Quit\n");
    printf(":clear   -> Clear text\n");
    printf(":show    -> Show all text\n");
    printf("------------------------\n");
    
    while(1) {
        printf("notepad> ");
        fgets(line, sizeof(line), stdin);

        // newline temizle
        line[strcspn(line, "\n")] = 0;

        if(strcmp(line, ":q") == 0) {
            printf("Exiting notepad...\n");
            break;
        }
        else if(strcmp(line, ":clear") == 0) {
            line_count = 0;
            printf("Text cleared.\n");
        }
        else if(strcmp(line, ":show") == 0) {
            printf("----- CONTENT -----\n");
            for(int i = 0; i < line_count; i++) {
                printf("%d: %s\n", i + 1, buffer[i]);
            }
            printf("-------------------\n");
        }
        else {
            if(line_count < 100) {
                strcpy(buffer[line_count], line);
                line_count++;
            } else {
                printf("Buffer full! Max 100 lines.\n");
            }
        }
    }
}

// ------------------------
// Command: credits
// Shows you the credits
// ------------------------
void cmd_credits(char *input){
    printf("--------------------- YIGITUX CREDITS ---------------------\n");
    printf("- Yiğit ALP website: yigit.phomeds.com\n");
    printf("------------------------------------------------------------\n");
}

// ------------------------
// Command: asciiart
// Prints the alphabet with the ASCII art
// ------------------------
void cmd_asciiart(char *input) {
    printf("    _   ___  ___ ___  ___ ___ ___ _  _ ___   _ _  ___    __  __ _  _  ___  _   _ ___ ___  ___ _____ _   ___   ____   ______\n");
    printf("   /_\\ | _ )/ __|   \\| __| __/ __| || |_ _| | | |/ / |  |  \\/  | \\| |/ _ \\| | | | _ \\ _ \\/ __|_   _| | | \\ \\ / /\\ \\ / /_  /\n");
    printf("  / _ \\| _ \\ (__| |) | _|| _| (_ | __ || | || | ' <| |__| |\\/| | .` | (_) | |_| |  _/   /\\__ \\ | | | |_| |\\ V /  \\ V / / / \n");
    printf(" /_/ \\_\\___/\\___|___/|___|_| \\___|_||_|___\\__/|_|\\_\\____|_|  |_|_|\\_|\\___/ \\___/|_| |_|_\\|___/ |_|  \\___/  \\_/    |_| /___|\n");
}

// ------------------------
// Command: makemailbro
// Makes you a e-mail adress
// ------------------------
void cmd_mail(char *input, char *username, char *mailservice, char *adress) {
    system("clear");
    printf("Welcome to makemailbro. Enter your username.\nYour username: ");
    fgets(username, MAX_INPUT, stdin);
    username[strcspn(username, "\n")] = 0;

    printf("E-mail service (gmail/outlook/proton): ");
    fgets(mailservice, MAX_INPUT, stdin);
    mailservice[strcspn(mailservice, "\n")] = 0;

    if (strcmp(mailservice, "gmail") == 0)
        snprintf(adress, MAX_INPUT, "%s@gmail.com", username);
    else if (strcmp(mailservice, "outlook") == 0)
        snprintf(adress, MAX_INPUT, "%s@outlook.com", username);
    else if (strcmp(mailservice, "proton") == 0)
        snprintf(adress, MAX_INPUT, "%s@proton.me", username);
    else {
        printf("Unknown service!\n");
        return;
    }

    printf("Your e-mail: %s\n", adress);
}

// ------------------------
// Command: makepasswdbro
// Makes you a random password
// ------------------------
void cmd_passwd(char *input) {
    system("clear");
    printf("----------------------------YIGITUX MAKEPASSWDBRO----------------------------\n");
    
    char length_str[MAX_INPUT];
    int length;
    
    printf("Welcome to makepasswdbro! How long should your password be? (8-64): ");
    fgets(length_str, MAX_INPUT, stdin);
    length_str[strcspn(length_str, "\n")] = 0;
    length = atoi(length_str);
    
    if (length < 8 || length > 64) {
        printf("Invalid length! Please enter a number between 8 and 64.\n");
        return;
    }
    
    char ask_symbols[MAX_INPUT];
    printf("Include symbols? (!@#$%^&*) (yes/no): ");
    fgets(ask_symbols, MAX_INPUT, stdin);
    ask_symbols[strcspn(ask_symbols, "\n")] = 0;
    
    // Character pools
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char digits[]    = "0123456789";
    char symbols[]   = "!@#$%^&*()-_=+[]{}";
    
    char pool[128];
    strcpy(pool, lowercase);
    strcat(pool, uppercase);
    strcat(pool, digits);
    if (strcmp(ask_symbols, "yes") == 0)
        strcat(pool, symbols);
    
    int pool_size = strlen(pool);
    char password[65];
    
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        password[i] = pool[rand() % pool_size];
    }
    password[length] = '\0';
    
    printf("\nYour generated password: %s\n", password);
    printf("Make sure to save it somewhere safe!\n");
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
    else if(strcmp(input, "whoami") == 0) cmd_whoareyou(input);
    else if(strcmp(input, "randlet") == 0) cmd_randlet(input);
    else if(strcmp(input, "notepad") == 0) cmd_notepad(input);
    else if(strcmp(input, "hackmode") == 0) cmd_hackmode(input);
    else if(strcmp(input, "favrepo") == 0) cmd_favrepo(input);
    else if(strcmp(input, "whichos") == 0) cmd_whichos(input);
    else if(strcmp(input, "asciiart") == 0) cmd_asciiart(input);
    else if(strcmp(input, "credits") == 0) cmd_credits(input);
    else if(strcmp(input, "makemailbro") == 0) {
    char username[MAX_INPUT], mailservice[MAX_INPUT], adress[MAX_INPUT];
    cmd_mail(input, username, mailservice, adress);}
    else if(strcmp(input, "makepasswdbro") == 0) cmd_passwd(input);
    else printf("Unknown command: %s\n", input);
}