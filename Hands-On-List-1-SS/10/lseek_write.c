#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd;
    off_t position;

    char data1[] = "1234567890";
    char data2[] = "ABCDEFGHIJ";

    // Open file in read-write mode
    fd = open("sample.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);

    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Write first 10 bytes
    if (write(fd, data1, 10) != 10) {
        perror("write");
        close(fd);
        return 1;
    }

    printf("First 10 bytes written: %s\n", data1);

    // Move file pointer 10 bytes forward
    position = lseek(fd, 10, SEEK_CUR);

    if (position == (off_t)-1) {
        perror("lseek");
        close(fd);
        return 1;
    }

    printf("lseek return value = %ld\n", (long)position);

    // Write another 10 bytes
    if (write(fd, data2, 10) != 10) {
        perror("write");
        close(fd);
        return 1;
    }

    printf("Second 10 bytes written: %s\n",data2);

    // Close the file
    close(fd);

    return 0;
}


/* Output:

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/10$ nano lseek_write.c
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/10$ gcc lseek_write.c -o lseek_write
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/10$ ./lseek_write
First 10 bytes written: 1234567890
lseek return value = 20
Second 10 bytes written: ABCDEFGHIJ
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/10$ od -c sample.txt
0000000   1   2   3   4   5   6   7   8   9   0  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   A   B   C   D   E   F   G   H   I   J
0000036
*/
