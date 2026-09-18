#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    int old_priority, new_priority;

    // Get the initial nice value
    old_priority = getpriority(PRIO_PROCESS, 0);

    printf("Initial nice value: %d\n", old_priority);

    // Increase the nice value by 5
    new_priority = nice(5);

    if (new_priority == -1) {
        perror("nice");
    }
    else {
        printf("New priority value after increment: %d\n", new_priority);
    }

    // Verify the new nice value
    printf("Verified new priority value: %d\n",
           getpriority(PRIO_PROCESS, 0));

    return 0;
}


/* Output:

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/20$ gcc priority.c -o priority
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/20$ ./priority
Initial nice value: 0
New priority value after increment: 5
Verified new priority value: 5
*/
