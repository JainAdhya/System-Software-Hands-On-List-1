#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd[5];

    // Create and open five files
    fd[0] = open("file1.txt", O_CREAT | O_RDWR, 0644);
    fd[1] = open("file2.txt", O_CREAT | O_RDWR, 0644);
    fd[2] = open("file3.txt", O_CREAT | O_RDWR, 0644);
    fd[3] = open("file4.txt", O_CREAT | O_RDWR, 0644);
    fd[4] = open("file5.txt", O_CREAT | O_RDWR, 0644);

    // Check whether files were opened successfully
    for (int i = 0; i < 5; i++) {
        if (fd[i] == -1) {
            perror("open");
            return 1;
        }

        printf("file%d.txt opened with file descriptor %d\n",
               i + 1, fd[i]);
    }

    printf("Process ID (PID): %d\n", getpid());
    printf("Program is running in an infinite loop...\n");

    // Infinite loop
    while (1) {
    }

    return 0;
}

/* Output:
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/5$ gcc five_files.c -o five_files
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/5$ ./five_files &
[1] 1089
file1.txt opened with file descriptor 3
file2.txt opened with file descriptor 4
file3.txt opened with file descriptor 5
file4.txt opened with file descriptor 6
file5.txt opened with file descriptor 7
Process ID (PID): 1089
Program is running in an infinite loop...
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/5$ ls -l /proc/1089/fd
total 0
lrwx------ 1 adhya adhya 64 Sep 17 14:31 0 -> /dev/pts/0
lrwx------ 1 adhya adhya 64 Sep 17 14:31 1 -> /dev/pts/0
lrwx------ 1 adhya adhya 64 Sep 17 14:31 2 -> /dev/pts/0
lrwx------ 1 adhya adhya 64 Sep 17 14:31 3 -> /home/adhya/System-Software-Hands-On-List-1/Hands-On-List-1-SS/5/file1.txt
lrwx------ 1 adhya adhya 64 Sep 17 14:31 4 -> /home/adhya/System-Software-Hands-On-List-1/Hands-On-List-1-SS/5/file2.txt
lrwx------ 1 adhya adhya 64 Sep 17 14:31 5 -> /home/adhya/System-Software-Hands-On-List-1/Hands-On-List-1-SS/5/file3.txt
lrwx------ 1 adhya adhya 64 Sep 17 14:31 6 -> /home/adhya/System-Software-Hands-On-List-1/Hands-On-List-1-SS/5/file4.txt
lrwx------ 1 adhya adhya 64 Sep 17 14:31 7 -> /home/adhya/System-Software-Hands-On-List-1/Hands-On-List-1-SS/5/file5.txt
*/
