/*************************************************************************************
 * myshell - wjonesSTUDENT code for Project 1 of CSCE 489
 *
 *************************************************************************************/

#include <stdio.h>
#include "shellfuncts.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void bufferToCommand(char userCmd[256], char arg1[256], char arg2[256], char arg3[256], char arg4[256], char arg5[256]) {
    if (strcmp(userCmd, "dir") == 0) {
        //printf("dir command sent\n");
        dir();
    } else if (strcmp(userCmd, "update") == 0) {
        printf("update command sent\n");
        update(arg1, arg2, arg3, arg4);
    } else if (strcmp(userCmd, "list") == 0) {
        list(arg1);
    } else if (strcmp(userCmd, "halt") == 0) {
        halt();
    } else if (strcmp(userCmd, "create") == 0) {
        create(arg1);
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
    banner();
    while (1) {
        printf("Roscoe: ");
        //reads stdin stream and puts in a character buffer
        fgets(buffer, 256, stdin);
        //measure the length of the buffer array and find the carriage return and replace with a \0
        int length = strlen(buffer);
        if ((buffer[length -1 ]) == '\n') {
            buffer[length - 1] = '\0';
        }
        // make a bunch of variables for each chunk of a given user command
        char userCmd[256];
        char arg1[256];
        char arg2[256];
        char arg3[256];
        char arg4[256];
        char arg5[256];
        //break up the buffer each time there is a space
        // TODO figure out how to handle a string of quotes
        // TODO figure out how to background a process with &
        sscanf(buffer, "%s %s %s %s %s %s", userCmd, arg1, arg2, arg3, arg4, arg5);
        bufferToCommand(userCmd, arg1, arg2, arg3, arg4, arg5);
      }
}
