#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <sys/types.h>

int main(){
    int min_fifo = sched_get_priority_min(SCHED_FIFO);
    int max_fifo = sched_get_priority_max(SCHED_FIFO);
    int min_rr = sched_get_priority_min(SCHED_RR);
    int max_rr = sched_get_priority_max(SCHED_RR);

    if(min_fifo == -1  ||  max_fifo == -1  ||  min_rr == -1  ||  max_rr == -1){
        perror("sched_get_priority");
        return -1;
    }

    printf("Real-time Priority Ranges:\n");
    printf("FIFO: min = %d, max = %d\n", min_fifo, max_fifo);
    printf("RR  : min = %d, max = %d\n", min_rr, max_rr);

    printf("The min real time priority = %d\n", sched_get_priority_min(SCHED_OTHER));
    printf("The max real time priority = %d\n", sched_get_priority_max(SCHED_OTHER));

    return 0;
}

/* Output:

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/28$ gcc realtime_priority.c -o realtime_priority
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/28$ ./realtime_priority
Real-time Priority Ranges:
FIFO: min = 1, max = 99
RR  : min = 1, max = 99
The min real time priority = 0
The max real time priority = 0
*/
