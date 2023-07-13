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
//    banner();
    while (1) {
        printf("Roscoe: ");
        fgets(buffer, 256, stdin);

        int length = strlen(buffer);
        if ((buffer[length -1 ]) == '\n') {
            buffer[length - 1] = '\0';
        }

        int i = 0;
        int j = 0;
        while (j < length){
            sscanf(buffer + i, "%s", userInput[j]);
            i += strlen(userInput[j]) +1;
            j++;
            }
    }
}
