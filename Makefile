#
# Linux makefile
# Use with make 
#

AS		:= nasm
ASFLAGS := -f elf
CFLAGS	:= -m32
LDFLAGS := -m32
CC		:= /usr/bin/gcc
CXX		:= g++
CXXFLAGS := -m32
TARGETS := prime math first main.o
DEP := driver.o asm_io.o

.PHONY: clean

%.o: %.asm
	$(AS) $(ASFLAGS) $< 

all: $(TARGETS) 

prime: $(DEP)

math: $(DEP)

first: $(DEP)

asm_io.o: asm_io.asm
	$(AS) $(ASFLAGS) -d ELF_TYPE asm_io.asm

array1: driver.o array1c.o

first.o: asm_io.inc

main4.o: asm_io.inc

prime.o: asm_io.inc 

main.o: main.c first.asm
	$(CC) $(CFLAGS) main.c asm_io.o first.o -o main.o

clean :
	rm -f *.o $(TARGETS)
