CC=gcc
CFLAGS=-g -O2 -std=gnu99 -Wall -pedantic 
LIBS=-lncurses -ltinfo --enable-ext-colors
TARGET=tinytoy
DEPS=ui.h display.h
OBJ=tinytoy.o ui.o display.o

ifeq ($(PREFIX),)
	PREFIX := /usr/local
endif

all: $(TARGET)

%.o: %.c $(DEPS)
	$(CC) -o $@ -c $< $(CFLAGS)
$(TARGET): $(OBJ)
	$(CC) $^ -o $@ $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	-rm -f *.o tinytoy

.PHONY: install
install: $(TARGET)
	cp $< $(DESTDIR)$(PREFIX)/bin/

.PHONY: UNINSTALL
UNINSTALL:
	-rm  $(DESTDIR)$(PREFIX)/bin/tinytoy
