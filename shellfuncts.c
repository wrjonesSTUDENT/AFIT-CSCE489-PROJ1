/*************************************************************************************
 * shellfuncts.c - code definitions for your functions
 *
 *************************************************************************************/

#include <stdio.h>
#include "shellfuncts.h"
#include <unistd.h>
#include <sys/wait.h>

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
 * banner -
 *************************************************************************************/

//int cmdPrompt() {
    // scan for user input and executed other functions within shellfunts.c

//}
/*************************************************************************************
 * hello - sends hello world to the user! I'm doing proper function commenting so future
 *         coders might not find my code as painful.
 *
 *    Params:  param2 - not a very good parameter name - something better might be
 *                      say, msgstr or sendtext
 *
 *************************************************************************************/

//void send_msg(const char *param2) {
//	printf("%s", param2);
//}

/*************************************************************************************
 * create - \<name\>
 *      create a new file in the current directory with the given name.
 *      If the file already exists, print an error message on the workstation screen.
 *    Params:
 *
 *************************************************************************************/
/* int create() {
    int child = fork();
    if (child == 0) {
        fopen("userArg", "w+");
        printf()
    } else {
        wait(NULL);
        return 1;
    }
    */
/*************************************************************************************
 * update - \<name\> \<number\> \<text\>
 *      Append lines of text to the named file. In particular, the text string \<text\>
 *      is appended to the end of the file, \<number\> times. To simulate a (very)
 *      slow device, the update command sleeps for several seconds after
 *      appending each line.
 *    Params:
 *
 *************************************************************************************/

/*************************************************************************************
 * list - \<name\>
 *      Display the contents of the named file on the workstation screen.
 *      If the file does not exist, print an error message on the workstation
 *      screen and terminate the command.
 *    Params:
 *
 *************************************************************************************/

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
    } else {
        wait(NULL);
        return 1;
    }
    //exit(0);
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
               "list - list th contents of a file\n"
               "dir - lists the files in the current working directory\n"
               "halt - exits the Roscoe shell\n"
               "banner - prints the Roscoe (patent pending) banner\n"
               "*****************************************\n");
    } else {
        wait(NULL);
        return 1;
    }
}