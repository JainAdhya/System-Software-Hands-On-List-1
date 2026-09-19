#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

void print_policy(int policy) {
    switch (policy) {
        case SCHED_OTHER:
            printf("SCHED_OTHER (default)\n");
            break;

        case SCHED_FIFO:
            printf("SCHED_FIFO (real-time FIFO)\n");
            break;

        case SCHED_RR:
            printf("SCHED_RR (real-time Round-Robin)\n");
            break;

        default:
            printf("Unknown scheduling policy\n");
    }
}

int main() {
    pid_t pid = getpid();
    int policy;
    struct sched_param param;

    // Get current scheduling policy
    policy = sched_getscheduler(pid);

    if (policy == -1) {
        perror("sched_getscheduler");
        return 1;
    }

    printf("Current scheduling policy: ");
    print_policy(policy);

    // Set priority
    param.sched_priority = 10;

    // Change policy to SCHED_FIFO
    if (sched_setscheduler(pid, SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler SCHED_FIFO");
        return 1;
    }

    printf("Scheduling policy changed to SCHED_FIFO\n");
    printf("Priority: %d\n", param.sched_priority);

    // Verify SCHED_FIFO
    policy = sched_getscheduler(pid);

    if (policy == -1) {
        perror("sched_getscheduler");
        return 1;
    }

    printf("Current scheduling policy: ");
    print_policy(policy);

    // Change policy to SCHED_RR
    if (sched_setscheduler(pid, SCHED_RR, &param) == -1) {
        perror("sched_setscheduler SCHED_RR");
        return 1;
    }

    printf("Scheduling policy changed to SCHED_RR\n");
    printf("Priority: %d\n", param.sched_priority);

    // Verify SCHED_RR
    policy = sched_getscheduler(pid);

    if (policy == -1) {
        perror("sched_getscheduler");
        return 1;
    }

    printf("Current scheduling policy: ");
    print_policy(policy);

    return 0;
}


/* Output:

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/29$ gcc scheduling_policy.c -o scheduling_policy
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/29$ sudo ./scheduling_policy
[sudo: authenticate] Password:
Current scheduling policy: SCHED_OTHER (default)
Scheduling policy changed to SCHED_FIFO
Priority: 10
Current scheduling policy: SCHED_FIFO (real-time FIFO)
Scheduling policy changed to SCHED_RR
Priority: 10
Current scheduling policy: SCHED_RR (real-time Round-Robin)
*/
