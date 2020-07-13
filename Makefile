CC=gcc
CFLAGS=-I -g -Wall -Wextra
DEPS = shellfuncts.h
OBJ = myshell.o shellfuncts.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

myshell: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o *~ myshell 
