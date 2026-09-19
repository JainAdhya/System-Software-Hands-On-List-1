#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Executing ls -Rl using execlp():\n");

    execlp("ls", "ls", "-Rl", (char *)NULL);

    perror("execlp");
    return 1;
}


/* Output:

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/27$ gcc 27b.c -o 27b
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/27$ ./27b
Executing ls -Rl using execlp():
.:
total 40
-rwxr-xr-x 1 adhya adhya 16032 Sep 19 08:24 27a
-rw-r--r-- 1 adhya adhya   590 Sep 19 08:25 27a.c
-rwxr-xr-x 1 adhya adhya 16040 Sep 19 08:26 27b
-rw-r--r-- 1 adhya adhya   206 Sep 19 08:25 27b.c
*/
