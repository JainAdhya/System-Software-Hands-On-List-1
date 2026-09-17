#include <unistd.h>
#include <stdlib.h>

int main() {
    char buffer[100];
    ssize_t bytes;

    // Read input from STDIN
    bytes = read(0, buffer, sizeof(buffer));

    if (bytes < 0) {
        write(2, "Read error\n", 11);
        exit(1);
    }

    // Write input to STDOUT
    if (write(1, buffer, bytes) < 0) {
        write(2, "Write error\n", 12);
        exit(1);
    }

    return 0;
}


/* Output:
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/6$ gcc stdin_stdout.c -o stdin_stdout
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/6$ ./stdin_stdout
Hello!!
Hello!!
*/
