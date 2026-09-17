#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    struct stat file;

    // Check command-line argument
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Get file information
    if (lstat(argv[1], &file) < 0) {
        perror("lstat");
        return 1;
    }

    printf("File: %s\n", argv[1]);

    // Identify the type of file
    if (S_ISREG(file.st_mode)) {
        printf("Type: Regular file\n");
    }
    else if (S_ISDIR(file.st_mode)) {
        printf("Type: Directory\n");
    }
    else if (S_ISLNK(file.st_mode)) {
        printf("Type: Symbolic link\n");
    }
    else if (S_ISCHR(file.st_mode)) {
        printf("Type: Character device\n");
    }
    else if (S_ISBLK(file.st_mode)) {
        printf("Type: Block device\n");
    }
    else if (S_ISFIFO(file.st_mode)) {
        printf("Type: FIFO (Named pipe)\n");
    }
    else if (S_ISSOCK(file.st_mode)) {
        printf("Type: Socket\n");
    }
    else {
        printf("Type: Unknown\n");
    }

    return 0;
}


/* Output:

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/14$ gcc file_type.c -o file_type
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/14$ echo "Hello System Software" > sample.txt
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/14$ ./file_type sample.txt
File: sample.txt
Type: Regular file
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/14$ ln -s sample.txt softlink
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/14$ ./file_type softlink
File: softlink
Type: Symbolic link
*/
