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

//void bufferToCommand(char userCmd[256], char arg1[256], char arg2[256], char arg3[256], char arg4[256], char arg5[256], char quotedString[256]) {
//    if (strcmp(userCmd, "dir") == 0) {
//        //printf("dir command sent\n");
//        dir();
//    } else if (strcmp(userCmd, "update") == 0) {
////        printf("update command sent\n");
////        printf("print the array arg2 %s\n", arg2);
////        printf("print the array[0] %d\n", arg2[0]);
//        update(arg1, arg2, quotedString);
//    } else if (strcmp(userCmd, "list") == 0) {
//        list(arg1);
//    } else if (strcmp(userCmd, "halt") == 0) {
//        halt();
//    } else if (strcmp(userCmd, "create") == 0) {
//        create(arg1);
//    } else if (strcmp(userCmd, "help") == 0) {
//        help();
//    } else if (strcmp(userCmd, "banner") == 0) {
//        banner();
//    } else {
//        printf("invalid command, try entering \"help\" for available commands\n");
//    }
//}
int main() {
    char buffer[256];
//    banner();
    bool background = false;
    while (1) {
        printf("Roscoe: ");
        //reads stdin stream and puts in a character buffer
        fgets(buffer, 256, stdin);
        //measure the length of the buffer array and find the carriage return and replace with a \0
        int length = strlen(buffer);
        if ((buffer[length - 2 ]) == '&') {
                background = true; }
        if ((buffer[length -1 ]) == '\n') {
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
        // TODO figure out how to background a process with &
        //search the buffer for any quoted strings
        sscanf(buffer, "%*[^\"\n]\"%[^\"]\")", quotedString);
        //break up the buffer each time there is a space
        sscanf(buffer, "%s %s %s %s %s %s", userCmd, arg1, arg2, arg3, arg4, arg5);
//        bufferToCommand(userCmd, arg1, arg2, arg3, arg4, arg5, quotedString);
//        clearInputArrays(userCmd, arg1, arg2, arg3, arg4, arg5, quotedString);
        }
      }
