#include <stdio.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <name>\n", argv[0]);
        return 1;
    }

    printf("Hello, %s!\n", argv[1]);

    return 0;
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
