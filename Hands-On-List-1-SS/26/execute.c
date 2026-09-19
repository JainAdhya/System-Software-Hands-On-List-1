#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Executing hello program...\n");

    execl("./hello", "hello", (char *)NULL);

    perror("execl");
    return 1;
}


/* Output:

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/26$ nano hello.c
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/26$ gcc hello.c -o hello
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/26$ nano execute.c
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/26$ gcc execute.c -o execute
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/26$ ./execute
Executing hello program...
Hello! This is the executable program.
*/
