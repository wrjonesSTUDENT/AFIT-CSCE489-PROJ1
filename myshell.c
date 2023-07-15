/*************************************************************************************
 * myshell - wjonesSTUDENT code for Project 1 of CSCE 489
 *
 *************************************************************************************/

#include <stdio.h>
#include "shellfuncts.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>

void bufferToCommand(char userCmd[256], char arg1[256], char arg2[256], char arg3[256], char arg4[256], char arg5[256], char quotedString[256], int background) {
    if (strcmp(userCmd, "dir") == 0) {
        //printf("dir command sent\n");
        dir();
    } else if (strcmp(userCmd, "update") == 0) {
//        printf("update command sent\n");
//        printf("print the array arg2 %s\n", arg2);
//        printf("print the array[0] %d\n", arg2[0]);
        update(arg1, arg2, quotedString, background);
    } else if (strcmp(userCmd, "list") == 0) {
        list(arg1, background);
    } else if (strcmp(userCmd, "halt") == 0) {
        halt();
    } else if (strcmp(userCmd, "create") == 0) {
        create(arg1, background);
    } else if (strcmp(userCmd, "help") == 0) {
        help();
    } else if (strcmp(userCmd, "banner") == 0) {
        banner();
    } else {
        printf("invalid command, try entering \"help\" for available commands\n");
    }
}
int main() {
    char buffer[256];
//    banner();
    while (1) {
        int background = 0;
        printf("Roscoe: ");
        //reads stdin stream and puts in a character buffer
        if (fgets(buffer, 256, stdin) != NULL) {
            //measure the length of the buffer array and find the carriage return and replace with a \0
            int length = strlen(buffer);
            if ((buffer[length - 2]) == '&') {
                background = 1;
            }
            if ((buffer[length - 1]) == '\n') {
                buffer[length - 1] = '\0';
            }
            // make a bunch of variables for each chunk of expected user command inputs
            char userCmd[256];
            char arg1[256];
            char arg2[256];
            char arg3[256];
            char arg4[256];
            char arg5[256];
            char quotedString[256];
            //search the buffer for any quoted strings
            sscanf(buffer, "%*[^\"\n]\"%[^\"]\")", quotedString);
            //break up the buffer each time there is a space
            sscanf(buffer, "%s %s %s %s %s %s", userCmd, arg1, arg2, arg3, arg4, arg5);
            bufferToCommand(userCmd, arg1, arg2, arg3, arg4, arg5, quotedString, background);
            clearInputArrays(userCmd, arg1, arg2, arg3, arg4, arg5, quotedString);
            fflush(stdin);
            wait(NULL);
        }
        memset(buffer, '\0', 256);
    }
}
