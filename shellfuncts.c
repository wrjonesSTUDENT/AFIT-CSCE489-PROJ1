/*************************************************************************************
 * shellfuncts.c - code definitions for your functions
 *
 *************************************************************************************/

#include <stdio.h>
#include "shellfuncts.h"
#include <unistd.h>
#include <sys/wait.h>
#include "string.h"

// clears the input arrays after each command is run
int clearInputArrays(char userCmd[], char arg1[], char arg2[], char arg3[], char arg4[], char arg5[], char quotedString[]) {
    memset(userCmd, 0, 256);
    memset(arg1, 0, 256);
    memset(arg2, 0, 256);
    memset(arg3, 0, 256);
    memset(arg4, 0, 256);
    memset(arg5, 0, 256);
    memset(quotedString, 0, 256);
}

/*************************************************************************************
 * banner -
 *************************************************************************************/

int banner() {
	// banner spam
    printf("      |\\      _,,,---,,_\n"
           "ZZZzz /,`.-'`'    -.  ;-;;,_\n"
           "     |,4-  ) )-,_. ,\\ (  `'-'\n"
           "    '---''(_/--'  `-'\\_)  Roscoe\n"
           "\n"
                 "Welcome to the Roscoe interactive shell\n"
                 "type help for basic functions\n"
                 "*****************************************\n");
}
/*************************************************************************************
 * create - \<name\>
 *      create a new file in the current directory with the given name.
 *      If the file already exists, print an error message on the workstation screen.
 *    Params:
 *
 *************************************************************************************/
int create(char arg1[]) {
    int child = fork();
    if (child == 0) {
        // i found this syntax on w3schools with fclose and fopen tutorials
        // specifically the if statement to check if a file already exists
        FILE *fp;
        if (fp = fopen(arg1, "r")) {
            fclose(fp);
            printf("this file already exists please choose a different filename\n");
            _exit(0);
        } else {
            fp = fopen(arg1, "w+");
            fclose(fp);
            _exit(0);
        }
    } else {
        wait(NULL);
        return 1;
    }
}
/*************************************************************************************
 * update - \<name\> \<number\> \<text\>
 *      Append lines of text to the named file. In particular, the text string \<text\>
 *      is appended to the end of the file, \<number\> times. To simulate a (very)
 *      slow device, the update command sleeps for several seconds after
 *      appending each line.
 *    Params:
 *
 *************************************************************************************/
//use fopen() to open file <name> for append (i.e., mode "a")
//loop <number> times
//use fprintf() to append the line <text> to the end of the file
//use fflush() to force the file write to disk
//        use sleep(strlen( <text>/5) to suspend the process for a few seconds
//        use fclose() to close the file
//print a message on the workstation screen saying that the update has completed (include the process id of this child process)
//exit(0)
// update file2 10 “this is the first 10 lines” &
// userCmd arg1 arg2 "arg3" arg4
int update(char arg1[], char arg2[], char quotedString[]) {
    // intiliaze the actual integer instead of the ASCII representation of a integer
    int arg2Int = arg2[0] - '0';
    int child = fork();
    if (child == 0) {
        // i found this syntax on w3schools with fclose and fopen tutorials
        // specifically the if statement to check if a file already exists
        FILE *fp;
        fp = fopen(arg1, "a");
        if (fp == NULL) {
            printf("no such filename, did you make a typo?\n");
            fclose(fp);
            _exit(0);
        } else {
            printf("add that line %d times\n", arg2Int);
            for (int i=0;i <= arg2Int;i++)
                fprintf(fp, "%s\n", quotedString);
                fflush(fp);
                _exit(0);
        }
    } else {
        wait(NULL);
        return 1;
    }
}
/*************************************************************************************
 * list - \<name\>
 *      Display the contents of the named file on the workstation screen.
 *      If the file does not exist, print an error message on the workstation
 *      screen and terminate the command.
 *    Params:
 *
 *************************************************************************************/
//use fopen() to open file <name> for reading (i.e., mode "r")
//if the file doesn't exist, then print an error message, and terminate the child process
//use fclose() to close the file
//use execl() to cat the file
//exit(0)
int list(char arg1[]) {
    int child = fork();
    if (child == 0) {
        // i found this syntax on w3schools with fclose and fopen tutorials
        // specifically the if statement to check if a file already exists
        FILE *fp;
        fp = fopen(arg1, "r");
        if (fp == NULL) {
            printf("no such filename, did you make a typo?\n");
            fclose(fp);
            _exit(0);
        } else {
            execl("/bin/cat", "cat", arg1, NULL);
            _exit(0);
        }
    } else {
        wait(NULL);
        return 1;
    }
}

/*************************************************************************************
 * dir - no args
 *      List the names of all files in the current directory.
 *      Note that since there is no command to change to a new directory,
 *      the current directory is the only directory.
 *    Params:
 *
 *************************************************************************************/
int dir() {
    int child = fork();
    if (child == 0) {
        execl("/bin/ls", "ls", NULL);
        _exit(0);
    } else {
        wait(NULL);
        return 1;
    }
}
/*************************************************************************************
 * halt - no args
 *      Terminate the shell
 *    Params:
 *
 *************************************************************************************/
int halt() {
    _exit(0);
}
/*************************************************************************************
 * help -
 *      simple intro to functions
 *    Params:
 *
 *************************************************************************************/
int help() {
    int help = fork();
    if (help == 0) {
        printf("*****************************************\n"
                "available functions include:\n"
               "*****************************************\n"
               "create - creates a new file\n"
               "update - writes to a file\n"
               "list - list the contents of a file\n"
               "dir - lists the files in the current working directory\n"
               "halt - exits the Roscoe shell\n"
               "banner - prints the Roscoe (patent pending) banner\n"
               "*****************************************\n");
        _exit(0);
    } else {
        wait(NULL);
        return 1;
    }
}