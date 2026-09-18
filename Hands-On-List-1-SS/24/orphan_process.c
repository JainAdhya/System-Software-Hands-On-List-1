#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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
        printf("Initial Parent PID: %d\n", getppid());

        // Wait for parent to terminate
        sleep(5);

        printf("\nAfter parent terminates:\n");
        printf("Child PID: %d\n", getpid());
        printf("New Parent PID: %d\n", getppid());

        printf("Child has become an orphan process.\n");
    }
    else {
        // Parent process
        printf("Parent process started.\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);

        printf("Parent process is terminating...\n");
        exit(0);
    }

    return 0;
}


/* Output:

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/24$ gcc orphan_process.c -o orphan_process
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/24$ ./orphan_process
Parent process started.
Parent PID: 8146
Child PID: 8147
Parent process is terminating...
Child process started.
Child PID: 8147
Initial Parent PID: 8146
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/24$
After parent terminates:
Child PID: 8147
New Parent PID: 366
Child has become an orphan process.
*/
