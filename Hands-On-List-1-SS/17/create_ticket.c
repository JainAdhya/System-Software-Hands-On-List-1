#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    int ticket = 100;

    fd = open("ticket.txt", O_WRONLY | O_CREAT | O_TRUNC, 0660);

    if (fd < 0) {
        perror("open");
        return 1;
    }

    write(fd, &ticket, sizeof(ticket));

    printf("Initial ticket number stored: %d\n", ticket);

    close(fd);

    return 0;
}


/* Output:

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/17$ gcc create_ticket.c -o create_ticket
./create_ticket
Initial ticket number stored: 100

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/17$ gcc reserve_ticket.c -o reserve_ticket

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/17$ ./reserve_ticket
Trying to acquire WRITE lock...
WRITE lock acquired.
New ticket number: 101
WRITE lock released.

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/17$ ./reserve_ticket
Trying to acquire WRITE lock...
WRITE lock acquired.
New ticket number: 102
WRITE lock released.
*/
