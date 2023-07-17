# Welcome to the Roscoe Interactive Shell
This project is my first program ever coded in C.  I named it after my cat Roscoe as he accompanied me on this long journey of learning to use an IDE and writing a program in C.
The Roscoe Interactive Shell has 7 major functions.

![roscoe](https://github.com/wrjonesSTUDENT/AFIT-CSCE489-PROJ1/assets/138234445/69375150-2962-4c67-934f-a51ca57a14dc)


### CREATE

create - list \<file\>.   creates a new file.

### UDPATE

update - update \<file\> # "string".   Appends a "string" # number of times to a \<file\>.  Strings cannot be longer than 256 characters.

### LIST

list - list \<file\>.   list the contents of a file.

### DIR

dir - lists the files in the current working directory

### HALT

halt - exits the Roscoe shell.

### BANNER

banner - reprints the Welcome Banner

### &

Background a process

## How to Run
download myshell.c, shellfuncts.c, shellfuncts.h, and Makefile into whatever directory you would like to run the shell from.

You can either run "gcc -o myshell myshell.c shellfuncts.c" OR use my leftover testing make file with "make test".

You will then be in the Roscoe Interactive Shell.

## Questions
1. Why was it necessary that your shell use the fork command before running the exec() system call (5 pts)?

If you executed any exec() system call prior to forking into a child process.  Your code would return the results of your exec command and then exit the shell. The exec command would replace the Roscoe shell code in memory.  I added the code i wrote for my dir command below for reference.

```
int dir() {
    int child = fork();
    if (child == 0) {
        execl("/bin/ls", "ls", NULL);
        printf("\n");
        exit(0);
    } else {
        wait(NULL);
        return 1;
    }
}
```

2. Explain, in as much detail as possible, what happened when you called the fprintf function (10 pts)? Keep in mind, I'm looking for an answer that discusses the process from when the function is entered, through the different "layers" until the function is complete.

https://www.ibm.com/docs/en/ztpf/2019?topic=apis-fprintf-printf-sprintf-format-write-data

When you call fprintf function, you typically provide a file pointer and a format satring.  fprintf will write directly to the file pointer provided "for instance in the Roscoe shell" it's pointed to the file opened with fopen().  You can also point it to stdout or stderr.  Then the file is closed by calling fclose().  Finally fprintf returns the number of characters written to the file.
