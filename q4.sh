#!/bin/bash
nasm -f elf64 src/syscall.S -o syscall.o
g++ -c -nostdlib -ffreestanding -fno-exceptions -fno-rtti src/basicIO.cpp -o basicIO.o
g++ -c -nostdlib -ffreestanding -fno-exceptions -fno-rtti src/q4.cpp -o q4.o
ld syscall.o basicIO.o q4.o -o q4_out.out