CC=gcc
CFLAGS=-g -O2 -std=gnu99 -Wall -pedantic 
LIBS=-lncurses -ltinfo --enable-ext-colors
TARGET=tinytoy
DEPS=display.h ui.h
OBJ=tinytoy.o display.o ui.o

all: $(TARGET)

%.o: %.c $(DEPS)
	$(CC) -o $@ -c $< $(CFLAGS)
$(TARGET): $(OBJ)
	$(CC) $^ -o $@ $(CFLAGS) $(LIBS)
.PHONY:
	clean
clean:
	-rm -f *.o tinytoy 
