#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    fd_set readfds;
    struct timeval timeout;
    int result;
    char buf[100];

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for input on STDIN for 10 seconds...\n");
    fflush(stdout);

    result = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

    if (result < 0) {
        perror("select");
        return 1;
    }
    else if (result == 0) {
        printf("No data available on STDIN within 10 seconds.\n");
    }
    else {
        if (FD_ISSET(STDIN_FILENO, &readfds)) {

            read(STDIN_FILENO, buf, sizeof(buf));

            printf("Data is available on STDIN within 10 seconds. Input detected: %s", buf);
        }
    }

    return 0;
}

/* Output:

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/13$ gcc select_stdin.c -o select_stdin
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/13$ ./select_stdin
Waiting for input on STDIN for 10 seconds...
Adhya
Data is available on STDIN within 10 seconds. Input detected: Adhya
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/13$ ./select_stdin
Waiting for input on STDIN for 10 seconds...
No data available on STDIN within 10 seconds.
*/
