
CC = i686-elf-gcc
AS = i686-elf-as

CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra
OBJECTS = boot.o kernel.o term.o userio.o util.o
INCFLAGS = 
LDFLAGS = -T linker.ld -ffreestanding -O2 -nostdlib
LIBS = -lgcc
CP = cp

all: zero.sys

$(OBJECTS): fcns.h vars.h vardec.h

zero.sys: $(OBJECTS) linker.ld
	$(CC) $(LDFLAGS) -o zero.sys $(OBJECTS) $(LIBS)

.SUFFIXES:	.c .cc .C .cpp .o .s .S

.c.o :
	$(CC) -o $@ -c $(CFLAGS) $< $(INCFLAGS)

clean:
	rm -f *.o

run: zero.sys
	qemu-system-i386 -kernel zero.sys

runtext: zero.sys
	qemu-system-i386 -display curses -kernel zero.sys

kill:
	pkill qemu

.PHONY: all
.PHONY: count
.PHONY: clean
