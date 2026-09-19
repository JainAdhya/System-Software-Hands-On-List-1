#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main() {
    printf("Executing ls -Rl using execle():\n");

    execle("/bin/ls", "ls", "-Rl", (char *)NULL, environ);

    perror("execle");
    return 1;
}

/* Output:

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/27$ gcc 27c.c -o 27c
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/27$ ./27c
Executing ls -Rl using execle():
.:
total 60
-rwxr-xr-x 1 adhya adhya 16032 Sep 19 08:24 27a
-rw-r--r-- 1 adhya adhya   590 Sep 19 08:25 27a.c
-rwxr-xr-x 1 adhya adhya 16040 Sep 19 08:26 27b
-rw-r--r-- 1 adhya adhya   687 Sep 19 08:27 27b.c
-rwxr-xr-x 1 adhya adhya 16104 Sep 19 08:27 27c
-rw-r--r-- 1 adhya adhya   243 Sep 19 08:27 27c.c
*/
