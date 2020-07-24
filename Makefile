CC=gcc
CFLAGS=-ggdb -Wall -Wextra
DEPS = shellfuncts.h
OBJ = myshell.o shellfuncts.o 

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< 

myshell: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ 

.PHONY: clean

clean:
	rm -f *.o *~ myshell 
