#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    printf("Before fork: Process ID = %d\n", getpid());

    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("Child Process:\n");
        printf("Child Process ID = %d\n", getpid());
        printf("Parent Process ID = %d\n", getppid());
    }
    else {
        // Parent process
        printf("Parent Process:\n");
        printf("Parent Process ID = %d\n", getpid());
        printf("Child Process ID = %d\n", pid);
    }

    return 0;
}


/* Output:

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/21$ gcc fork.c -o fork
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/21$ ./fork
Before fork: Process ID = 7366
Parent Process:
Parent Process ID = 7366
Child Process ID = 7367
Child Process:
Child Process ID = 7367
Parent Process ID = 366
*/
