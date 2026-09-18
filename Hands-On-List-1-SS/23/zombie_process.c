#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("Child process started.\n");
        printf("Child PID: %d\n", getpid());
        printf("Child is terminating...\n");

        exit(0);
    }
    else {
        // Parent process
        printf("Parent process started.\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);

        printf("Parent is sleeping for 30 seconds...\n");
        printf("During this time, the child will be a ZOMBIE.\n");

        sleep(30);

        printf("Parent process exiting.\n");
    }

    return 0;
}


/* Output: Terminal 1

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/23$ gcc zombie_process.c -o zombie_process
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/23$ ./zombie_process
Parent process started.
Parent PID: 7872
Child PID: 7873
Parent is sleeping for 30 seconds...
During this time, the child will be a ZOMBIE.
Child process started.
Child PID: 7873
Child is terminating...
Parent process exiting.
*/


/* Output: Terminal 2

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/23$ ps -el | grep Z
F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
1 Z  1000    7968    7967  0  80   0 -     0 -      pts/0    00:00:00 zombie_process
*/
