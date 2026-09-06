
int main(){
    
    return 0;
}
extern "C" void _start(){
    asm volatile(
        "call main\n"
        "mov %eax, %edi\n"
        "mov $60, %eax\n"
        "syscall\n"
    );
}