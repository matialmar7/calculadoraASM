#
# Linux makefile
# Use with make 
#

AS		:= nasm
ASFLAGS := -f elf
CFLAGS	:= -m32 -g
LDFLAGS := -m32
CC		:= /usr/bin/gcc
CXX		:= g++
CXXFLAGS := -m32
TARGETS := sumar.o restar.o main.o
DEP := driver.o asm_io.o

.PHONY: clean

%.o: %.asm
	$(AS) $(ASFLAGS) $< 

all: $(TARGETS) 

sumar.o:
	$(AS) $(ASFLAGS) -d ELF_TYPE sumar.asm -o sumar.o

restar.o:
	$(AS) $(ASFLAGS) -d ELF_TYPE restar.asm -o restar.o

main.o: main.c restar.asm sumar.asm
	$(CC) $(CFLAGS) main.c sumar.o restar.o -o main.o

clean :
	rm -f *.o $(TARGETS)
