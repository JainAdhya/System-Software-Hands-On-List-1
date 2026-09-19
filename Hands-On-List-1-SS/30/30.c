#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main() {
    pid_t pid, sid;
    int fd;

    // Create child process
    pid = fork();

    if (pid < 0) {
        perror("Failed to create child process");
        exit(1);
    }

    if (pid > 0) {
        printf("Parent exiting. Child PID: %d\n", pid);
        exit(0);
    }

    // Create new session
    sid = setsid();

    if (sid < 0) {
        perror("setsid");
        exit(1);
    }

    // Set file creation mask
    umask(0);

    // Change working directory
    chdir("/home/adhya/System-Software-Hands-On-List-1/Hands-On-List-1-SS/30");

    // Close standard file descriptors
    close(0);
    close(1);
    close(2);

    // Open output file
    fd = open("test.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd < 0)
        exit(1);

    // Script to be executed
    const char *script = "./script.sh";

    // Set the time at which the script should execute
    int target_hour = 15;
    int target_min = 25;

    while (1) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        if (t->tm_hour == target_hour &&
            t->tm_min == target_min) {

            system(script);

            write(fd, "Script executed\n", 16);

            // Prevent executing multiple times in the same minute
            sleep(60);
        }

        sleep(10);
    }

    close(fd);

    return 0;
}


/* Output:

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/30$ gcc 30.c -o 30
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/30$ ./30
Parent exiting. Child PID: 11211
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/30$ cat test.txt
Script executed
*/
