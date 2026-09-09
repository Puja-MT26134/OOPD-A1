#!/bin/bash
nasm -f elf64 src/syscall.S -o syscall.o
g++ -c -nostdlib -ffreestanding -fno-exceptions -fno-rtti src/basicIO.cpp -o basicIO.o
g++ -c -nostdlib -ffreestanding -fno-exceptions -fno-rtti src/q5.cpp -o q5.o
ld syscall.o basicIO.o q5.o -o q5_out.out
