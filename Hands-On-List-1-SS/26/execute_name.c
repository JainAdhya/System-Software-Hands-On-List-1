#include <stdio.h>
#include <unistd.h>

int main() {

    printf("Executing name program...\n");

    execl("./name", "name", "Adhya", (char *)NULL);

    perror("execl");
    return 1;
}


/* Output:

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/26$ nano name.c
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/26$ gcc name.c -o name
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/26$ nano execute_name.c
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/26$ gcc execute_name.c -o execute_name
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/26$ ./execute_name
Executing name program...
Hello, Adhya!
*/
