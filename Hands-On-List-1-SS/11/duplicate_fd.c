#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int fd, dup_fd, dup2_fd, fcntl_fd;

    fd = open("sample.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd < 0) {
        perror("open");
        return 1;
    }

    printf("Original file descriptor = %d\n", fd);

    // a. dup()
    dup_fd = dup(fd);

    if (dup_fd < 0) {
        perror("dup");
        close(fd);
        return 1;
    }

    printf("dup() file descriptor = %d\n", dup_fd);

    write(fd, "Written using original FD\n",
          strlen("Written using original FD\n"));

    write(dup_fd, "Written using dup FD\n",
          strlen("Written using dup FD\n"));

    close(dup_fd);

    // b. dup2()
    dup2_fd = dup2(fd, 10);

    if (dup2_fd < 0) {
        perror("dup2");
        close(fd);
        return 1;
    }

    printf("dup2() file descriptor = %d\n", dup2_fd);

    write(fd, "Written using original FD again\n",
          strlen("Written using original FD again\n"));

    write(dup2_fd, "Written using dup2 FD\n",
          strlen("Written using dup2 FD\n"));

    close(dup2_fd);

    // c. fcntl()
    fcntl_fd = fcntl(fd, F_DUPFD, 0);

    if (fcntl_fd < 0) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("fcntl() file descriptor = %d\n", fcntl_fd);

    write(fd, "Written using original FD third time\n",
          strlen("Written using original FD third time\n"));

    write(fcntl_fd, "Written using fcntl FD\n",
          strlen("Written using fcntl FD\n"));

    close(fcntl_fd);

    close(fd);

    printf("File updated successfully.\n");

    return 0;
}



/* Output:

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/11$ gcc duplicate_fd.c -o duplicate_fd
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/11$ > sample.txt
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/11$ ./duplicate_fd
Original file descriptor = 3
dup() file descriptor = 4
dup2() file descriptor = 10
fcntl() file descriptor = 4
File updated successfully.
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/11$ cat sample.txt
Written using original FD
Written using dup FD
Written using original FD again
Written using dup2 FD
Written using original FD third time
Written using fcntl FD
*/
