#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int fd;
    pid_t pid;

    // Open file
    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Create child process
    pid = fork();

    if (pid < 0) {
        perror("fork");
        close(fd);
        return 1;
    }

    if (pid == 0) {
        // Child process
        write(fd, "Written by child process\n", 25);
    }
    else {
        // Parent process
        write(fd, "Written by parent process\n", 26);
    }

    close(fd);

    return 0;
}


/* Output:

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/22$ gcc fork_write.c -o fork_write
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/22$ ./fork_write
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/22$ cat output.txt
Written by parent process
Written by child process
*/
