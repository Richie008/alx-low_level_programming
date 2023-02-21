#include <unistd.h>
#include <sys/syscall.h>

/**
*main - a progrram that prints _putchar
*return: 0 (success)
*/

int main(void) 
{ 
    const char msg[] = "_putchar\n"; 
    syscall(SYS_write, 1, msg, sizeof(msg)); 
    return 0; 
}

