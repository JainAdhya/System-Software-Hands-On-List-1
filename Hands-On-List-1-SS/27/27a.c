#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Executing ls -Rl using execl():\n");

    execl("/bin/ls", "ls", "-Rl", (char *)NULL);

    perror("execl");
    return 1;
}


/* Output:

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/27$ gcc 27a.c -o 27a
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/27$ ./27a
Executing ls -Rl using execl():
.:
total 20
-rwxr-xr-x 1 adhya adhya 16032 Sep 19 08:24 27a
-rw-r--r-- 1 adhya adhya   190 Sep 19 08:24 27a.c
*/
