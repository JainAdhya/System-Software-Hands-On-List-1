#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd;
    char ch;
    char line[100];
    int i = 0;
    ssize_t bytes;

    // Open file in read-only mode
    fd = open("sample.txt", O_RDONLY);

    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Read the file character by character
    while ((bytes = read(fd, &ch, 1)) > 0) {

        if (ch == '\n') {
            line[i] = '\0';
            printf("%s\n", line);
            i = 0;
        }
        else {
            line[i++] = ch;
        }
    }

    // Display the last line if it does not end with newline
    if (i > 0) {
        line[i] = '\0';
        printf("%s\n", line);
    }

    // Close the file at end of file
    close(fd);

    return 0;
}


/* Output:
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/8$ nano sample.txt
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/8$ cat sample.txt
Hello System Software
This is line two.
This is line three.
This is the last line.
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/8$ gcc read_lines.c -o read_lines
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/8$ ./read_lines
Hello System Software
This is line two.
This is line three.
This is the last line.
*/
