#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    int ticket;
    struct flock lock;

    fd = open("ticket.txt", O_RDWR);

    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Initialize write lock
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    printf("Trying to acquire WRITE lock...\n");

    // Acquire write lock
    if (fcntl(fd, F_SETLKW, &lock) < 0) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("WRITE lock acquired.\n");

    // Read current ticket number
    lseek(fd, 0, SEEK_SET);
    read(fd, &ticket, sizeof(ticket));

    // Increment ticket number
    ticket++;

    // Print new ticket number
    printf("New ticket number: %d\n", ticket);

    // Store updated ticket number
    lseek(fd, 0, SEEK_SET);
    write(fd, &ticket, sizeof(ticket));

    // Release lock
    lock.l_type = F_UNLCK;

    if (fcntl(fd, F_SETLK, &lock) < 0) {
        perror("fcntl unlock");
        close(fd);
        return 1;
    }

    printf("WRITE lock released.\n");

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
