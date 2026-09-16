#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    const char *target = "target.txt";
    const char *linkname = "softlink_syscall.txt";

    if (symlink(target, linkname) == -1) {
        perror("symlink failed");
        exit(1);
    }

    printf("Symbolic link created: %s -> %s\n", linkname, target);

    return 0;
}

/* Output:

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS$ nano 1a_softlink.c
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS$ gcc 1a_softlink.c -o softlink
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS$ ./softlink
Symbolic link created: softlink_syscall.txt -> target.txt
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS$ ls -l
total 24
-rw-r--r-- 1 adhya adhya   349 Sep 16 06:08 1a_softlink.c
-rwxr-xr-x 1 adhya adhya 16088 Sep 16 06:08 softlink
lrwxrwxrwx 1 adhya adhya    10 Sep 16 06:04 softlink_shell.txt -> target.txt
lrwxrwxrwx 1 adhya adhya    10 Sep 16 06:09 softlink_syscall.txt -> target.txt
-rw-r--r-- 1 adhya adhya    34 Sep 16 06:04 target.txt
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS$ cat softlink_syscall.txt
This is the original target file.
*/

/*
Output: SHELL COMMAND

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS$ echo "This is the original target file." > target.txt
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS$ cat target.txt
This is the original target file.
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS$ ln -s target.txt softlink_shell.txt
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS$ ls -l
total 4
lrwxrwxrwx 1 adhya adhya 10 Sep 16 06:04 softlink_shell.txt -> target.txt
-rw-r--r-- 1 adhya adhya 34 Sep 16 06:04 target.txt
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS$ cat softlink_shell.txt
This is the original target file.
*/



