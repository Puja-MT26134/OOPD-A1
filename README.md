# OOPD-A1
This assignment contains basic programming practices without using standard C/C++ library

# OOPD-A1
This assignment contains basic programming practices without using standard C/C++ library
## Assignment Description
__1. Setting up a git repository__
 - A github repository has been created and initialized with the readme.md, describing the assignment.

__2. Writing a C++ program which returns 0, but compiled without library files__
 -  A minimal C++ program that does nothing except returns 0.
 -  It uses g++ options to exclude standard library.
 - extern "C" void _start() is used to call main() and terminates the process via a direct exit system call

__3. Writing a program using .S file, which asks for an input and gives response accordingly__
- A c++ program is written using syscall.S, basicIO.h.
- In this program we have to takes the user's name and age as input, validates the age by checking whether it is a positive number or not, asks the confirmation of age using (y/n), and retuens the confirmation message accoringly.

__4. Dynamically allocating memory for names without overflow, on a new branch__
- The above program is copied in a new .cpp file.
- In this part, it is asked to extend the above program by asking user 'how many names are needed?' and then dynamically allocate that much memory using the mmap system call.
- Overflow is prevented by setting the upper bound, and ensure that each each name should be written within its fixed-size buffer slot using bounds-checked input.

__5. Extending it to allow resizing the allocation__
- The program 
   is further extended to allow the user to change the number of names 
   after initial allocation. This is done by allocating a new memory 
   region of the required size via mmap, manually copying over the 
   minimum of the old and new counts of existing names, freeing the 
   old memory region via munmap, and prompting for additional names 
   if the new count is larger than the old one.


### Build Commands

**Q2** (compiles without linking the standard library or startup files):
```bash
./q2.sh
./q2_nostd.out
```
Internally runs:
```bash
g++ -nostdlib -fno-exceptions -fno-rtti q2.cpp -o q2_nostd.out
```

**Q3** (assembles the `.S` file, compiles the I/O wrapper and main 
program, then links them without the standard library):
```bash
./q3.sh
./q3_out.out
```
Internally runs:
```bash
nasm -f elf64 src/syscall.S -o syscall.o
g++ -c -nostdlib -ffreestanding -fno-exceptions -fno-rtti src/basicIO.cpp -o basicIO.o
g++ -c -nostdlib -ffreestanding -fno-exceptions -fno-rtti src/q3.cpp -o q3.o
ld syscall.o basicIO.o q3.o -o q3_out.out
```

**Q4** and **Q5** (available on the `extended-q4-q5` branch) follow the 
same build pattern, substituting `q4.cpp`/`q5.cpp` respectively:
```bash
git checkout extended-q4-q5
./q4.sh   # or ./q5.sh
./q4_out.out   # or ./q5_out.out
```
#### Prerequisites
- g++ (GNU C++ compiler)
- nasm (For building the `.S` file)
- A Linux environment (WSL/Ubuntu used for development)

Install on Ubuntu/WSL:
```bash
sudo apt update
sudo apt install build-essential nasm -y
```


