/*************************************************************************************
 * myshell - wjonesSTUDENT code for Project 1 of CSCE 489
 *
 *************************************************************************************/

#include <stdio.h>
#include "shellfuncts.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//void bufferToCommand(char userInput[25]) {
//    if (strcmp(userInput, "dir") == 0) {
//        //printf("dir command sent\n");
//        dir();
//    } else if (strcmp(userInput, "update") == 0) {
//        printf("update command sent\n");
//    } else if (strcmp(userInput, "list") == 0) {
//        printf("list command sent\n");
//    } else if (strcmp(userInput, "halt") == 0) {
//        printf("roscoe shell exited\n");
//        halt();
//    } else if (strcmp(userInput, "create") == 0) {
//        printf("create command sent\n");
//    } else if (strcmp(userInput, "help") == 0) {
//        //printf("help command sent\n");
//        help();
//    } else if (strcmp(userInput, "banner") == 0) {
//        banner();
//    } else {
//        printf("invalid command, try entering \"help\" for available commands\n");
//    }
//}
int main() {
    char buffer[256];
    char userInput[6][256];
    // char quotedArg[256];
//    banner();
    while (1) {
        printf("Roscoe: ");
        //reads stdin stream and puts in a character buffer
        fgets(buffer, 256, stdin);
        //measure the length of the buffer array and find the carriage return and replace with a \0
        int length = strlen(buffer);
        if ((buffer[length -1 ]) == '\n') {
            buffer[length - 1] = '\0';
        }
        // place each string from the buffer array into the userInput array row each time a space is encountered
        int i = 0;
        int j = 0;
        while (j < length){ //this isn't the greatest indicator of how many times i should loop through
            sscanf(buffer + i, "%[A-Z,a-z,0-9,&]s", userInput[j]);
            i += strlen(userInput[j]) +1;
            j++;
            }
    }
//       failed attempt at capturing the arg in quotes
//        if (sscanf(buffer, "\"%[^\"]\"", quotedArg) ==1) {
//            printf("quoted content %s\n", quotedArg);
//        } else {
//            printf("No quoted content %s\n");
//            break;
//        }
}
