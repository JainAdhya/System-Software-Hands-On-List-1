#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-Rl", NULL};

    printf("Executing ls -Rl using execvp():\n");

    execvp("ls", args);

    perror("execvp");
    return 1;
}

/* Output:

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/27$ gcc 27e.c -o 27e
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/27$ ./27e
Executing ls -Rl using execvp():
.:
total 100
-rwxr-xr-x 1 adhya adhya 16032 Sep 19 08:24 27a
-rw-r--r-- 1 adhya adhya   510 Sep 19 08:29 27a.c
-rwxr-xr-x 1 adhya adhya 16040 Sep 19 08:26 27b
-rw-r--r-- 1 adhya adhya   607 Sep 19 08:29 27b.c
-rwxr-xr-x 1 adhya adhya 16104 Sep 19 08:27 27c
-rw-r--r-- 1 adhya adhya   742 Sep 19 08:31 27c.c
-rwxr-xr-x 1 adhya adhya 16088 Sep 19 08:32 27d
-rw-r--r-- 1 adhya adhya   823 Sep 19 08:32 27d.c
-rwxr-xr-x 1 adhya adhya 16088 Sep 19 08:37 27e
-rw-r--r-- 1 adhya adhya   208 Sep 19 08:34 27e.c
*/
