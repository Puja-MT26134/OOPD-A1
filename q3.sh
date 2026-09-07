#!/bin/bash
nasm -f elf64 src/syscall.S -o syscall.o
g++ -c -nostdlib -ffreestanding -fno-exceptions -fno-rtti src/basicIO.cpp -o basicIO.o
g++ -c -nostdlib -ffreestanding -fno-exceptions -fno-rtti src/q3.cpp -o q3.o
ld syscall.o basicIO.o q3.o -o q3_out.out
