
int main(){
    
    return 0;
}
extern "C" void _start(){
    asm volatile(
        "call main\n"
        "mov %rax, %rdi\n"
        "mov $60, %rax\n"
        "syscall\n"
    );
}