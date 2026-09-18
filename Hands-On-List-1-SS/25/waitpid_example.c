#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid[3];
    int status;

    // Create three child processes
    for (int i = 0; i < 3; i++) {

        pid[i] = fork();

        if (pid[i] < 0) {
            perror("fork");
            return 1;
        }

        if (pid[i] == 0) {
            // Child process
            printf("Child %d created. PID = %d\n", i + 1, getpid());

            // Give different sleep times
            sleep((i + 1) * 2);

            printf("Child %d terminating. PID = %d\n", i + 1, getpid());

            exit(0);
        }
    }

    // Parent process
    printf("\nParent PID = %d\n", getpid());

    printf("Parent is waiting specifically for Child 2 (PID = %d)\n",
           pid[1]);

    // Wait specifically for Child 2
    if (waitpid(pid[1], &status, 0) < 0) {
        perror("waitpid");
        return 1;
    }

    printf("Parent has received termination of Child 2.\n");

    // Wait for remaining children
    waitpid(pid[0], &status, 0);
    waitpid(pid[2], &status, 0);

    printf("All child processes have terminated.\n");

    return 0;
}


/* Output:


*/
