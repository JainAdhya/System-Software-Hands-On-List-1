#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    int flags;

    // Open the file
    fd = open("sample.txt", O_RDWR);

    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Get file status flags using fcntl
    flags = fcntl(fd, F_GETFL);

    if (flags < 0) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    // Check the opening mode
    if ((flags & O_ACCMODE) == O_RDONLY) {
        printf("File is opened in READ ONLY mode.\n");
    }
    else if ((flags & O_ACCMODE) == O_WRONLY) {
        printf("File is opened in WRITE ONLY mode.\n");
    }
    else if ((flags & O_ACCMODE) == O_RDWR) {
        printf("File is opened in READ WRITE mode.\n");
    }

    if(flags  &  O_APPEND)   printf("Append mode enabled\n");
    if(flags  &  O_NONBLOCK) printf("Non-blocking mode enabled\n");
    if(flags  &  O_SYNC)     printf("Synchronous I/O enabled\n");

    close(fd);

    return 0;
}

/* Output:

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/12$ echo "Hello System Software" > sample.txt
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/12$ gcc check_mode.c -o check_mode
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/12$ ./check_mode
File is opened in READ WRITE mode.
*/
