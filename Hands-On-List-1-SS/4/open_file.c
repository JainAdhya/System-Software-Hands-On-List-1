#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main() {
    int fd;

    fd = open("sample.txt", O_RDWR);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    printf("File opened successfully in read-write mode.\n");
    printf("File descriptor = %d\n", fd);

    close(fd);

    fd = open("sample.txt", O_RDWR | O_CREAT | O_EXCL, 0644);

    if (fd == -1) {
        printf("\nO_EXCL test:\n");
        printf("File was not created because it already exists.\n");
        printf("Error: %s\n", strerror(errno));
    }
    else {
        printf("\nO_EXCL test:\n");
        printf("File created successfully.\n");
        printf("File descriptor = %d\n", fd);

        close(fd);
    }

    return 0;
}

/* Output:
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/4$ gcc open_file.c -o open_file
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/4$ ./open_file
File opened successfully in read-write mode.
File descriptor = 3

O_EXCL test:
File was not created because it already exists.
Error: File exists
*/
