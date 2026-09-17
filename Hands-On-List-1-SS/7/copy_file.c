#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define bsize 1024

int main(int argc, char *argv[]) {
    int src_fd, dest_fd;
    ssize_t n;
    char ds[bsize];

    // Check command-line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        exit(1);
    }

    // Open source file for reading
    src_fd = open(argv[1], O_RDONLY);

    if (src_fd < 0) {
        perror("open source");
        exit(1);
    }

    // Open destination file for writing
    // Create it if it does not exist
    // Truncate it if it already exists
    dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (dest_fd < 0) {
        perror("open destination");
        close(src_fd);
        exit(1);
    }

    // Read from source and write to destination
    while ((n = read(src_fd, ds, bsize)) > 0) {
        if (write(dest_fd, ds, n) != n) {
            perror("write");
            close(src_fd);
            close(dest_fd);
            exit(1);
        }
    }

    // Check for read error
    if (n < 0) {
        perror("read");
        close(src_fd);
        close(dest_fd);
        exit(1);
    }

    close(src_fd);
    close(dest_fd);

    printf("File copied successfully from %s to %s\n", argv[1], argv[2]);

    return 0;
}


/* Output:
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/7$ echo "Hello System Software" > file1
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/7$ cat file1
Hello System Software
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/7$ nano copy_file.c
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/7$ gcc copy_file.c -o copy_file
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/7$ ./copy_file file1 file2
File copied successfully from file1 to file2
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/7$ cat file2
Hello System Software
*/
