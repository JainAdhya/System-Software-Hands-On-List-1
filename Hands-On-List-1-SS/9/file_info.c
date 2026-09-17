#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    struct stat file;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if (stat(argv[1], &file) < 0) {
        perror("stat");
        return 1;
    }

    printf("File information for: %s\n\n", argv[1]);

    // a. Inode number
    printf("a. Inode number       : %ld\n", file.st_ino);

    // b. Number of hard links
    printf("b. Hard links         : %ld\n", file.st_nlink);

    // c. User ID
    printf("c. UID                : %d\n", file.st_uid);

    // d. Group ID
    printf("d. GID                : %d\n", file.st_gid);

    // e. File size
    printf("e. Size               : %ld bytes\n", file.st_size);

    // f. Block size
    printf("f. Block size         : %ld bytes\n", file.st_blksize);

    // g. Number of blocks
    printf("g. Number of blocks   : %ld\n", file.st_blocks);

    // h. Last access time
    printf("h. Last access        : %s", ctime(&file.st_atime));

    // i. Last modification time
    printf("i. Last modification  : %s", ctime(&file.st_mtime));

    // j. Last change time
    printf("j. Last change        : %s", ctime(&file.st_ctime));

    return 0;
}


/* Output:
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/9$ nano file_info.c
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/9$ echo "Hello System Software" > sample.txt
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/9$ gcc file_info.c -o file_info
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/9$ ./file_info sample.txt
File information for: sample.txt

a. Inode number       : 50350
b. Hard links         : 1
c. UID                : 1000
d. GID                : 1000
e. Size               : 22 bytes
f. Block size         : 4096 bytes
g. Number of blocks   : 8
h. Last access        : Thu Sep 17 16:30:32 2026
i. Last modification  : Thu Sep 17 16:30:32 2026
j. Last change        : Thu Sep 17 16:30:32 2026
*/
