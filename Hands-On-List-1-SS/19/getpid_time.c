#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

static inline uint64_t rdtsc() {
    unsigned int low, high;

    __asm__ volatile (
        "rdtsc"
        : "=a"(low), "=d"(high)
    );

    return ((uint64_t)high << 32) | low;
}

int main() {
    uint64_t start, end;
    pid_t pid;

    // Read TSC before getpid()
    start = rdtsc();

    // Execute getpid()
    pid = getpid();

    // Read TSC after getpid()
    end = rdtsc();

    printf("Process ID: %d\n", pid);
    printf("TSC before getpid(): %lu\n", start);
    printf("TSC after getpid():  %lu\n", end);
    printf("Time taken by getpid(): %lu CPU cycles\n", end - start);

    return 0;
}


/* Output:

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/19$ gcc getpid_time.c -o getpid_time
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/19$ ./getpid_time
Process ID: 6940
TSC before getpid(): 60667820590541
TSC after getpid():  60667820600193
Time taken by getpid(): 9652 CPU cycles
*/
