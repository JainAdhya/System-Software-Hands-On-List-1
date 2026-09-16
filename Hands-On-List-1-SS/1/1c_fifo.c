#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    const char *fifo_name = "fifo_syscall";

    if (mkfifo(fifo_name, 0666) == -1) {
        perror("fifo_syscall failed");
        exit(1);
    }

    printf("FIFO created: %s\n", fifo_name);
    return 0;
}


/* Output:
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS$ nano 1c_fifo.c
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS$ gcc 1c_fifo.c -o fifo
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS$ ./fifo
FIFO created: fifo_syscall
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS$ ls -l fifo_syscall
prw-r--r-- 1 adhya adhya 0 Sep 16 06:30 fifo_syscall
*/


/*Ooutput: SHELL COMMAND
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS$ mkfifo fifo_shell
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS$ ls -l fifo_shell
prw-r--r-- 1 adhya adhya 0 Sep 16 06:27 fifo_shell
*/
