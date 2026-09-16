#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    const char *target = "target.txt";
    const char *linkname = "hardlink_syscall.txt";

    if (link(target, linkname) == -1) {
        perror("link failed");
        exit(1);
    }

    printf("Hard link created: %s -> %s\n", linkname, target);

    return 0;
}

/* Output:
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS$ nano 1b_hardlink.c
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS$ gcc 1b_hardlink.c -o hardlink
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS$ ./hardlink
Hard link created: hardlink_syscall.txt -> target.txt
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS$ ls -li target.txt hardlink_syscall.txt
44935 -rw-r--r-- 3 adhya adhya 34 Sep 16 06:04 hardlink_syscall.txt
44935 -rw-r--r-- 3 adhya adhya 34 Sep 16 06:04 target.txt
*/


/* Output: SHELL COMMAND
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS$ ln target.txt hardlink_shell.txt
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS$ ls -li target.txt hardlink_shell.txt
44935 -rw-r--r-- 2 adhya adhya 34 Sep 16 06:04 hardlink_shell.txt
44935 -rw-r--r-- 2 adhya adhya 34 Sep 16 06:04 target.txt
*/

