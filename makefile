CC=gcc
CFLAGS=-g -o2 -std=c99 -Wall -pedantic 
LIBS=-lncurses -ltinfo
DEPS=tinytoy.h display.h ui.h
OBJ=tinytoy.o display.o ui.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
tinytoy: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
.PHONY:
	clean
clean:
	-rm -f *.o tinytoy 
