CC=gcc
CFLAGS=-ggdb -Wall -Wextra -O0
DEPS = shellfuncts.h
OBJ = myshell.o shellfuncts.o 

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

myshell: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
test:
	gcc -o myshell myshell.c shellfuncts.c

clean:
	rm -f *.o *~ myshell 
