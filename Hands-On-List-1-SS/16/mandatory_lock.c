#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd;
    struct flock lock;
    char choice;

    printf("Enter r for read lock and w for write lock: ");
    scanf(" %c", &choice);

    // Open file in read-write mode
    fd = open("sample.txt", O_RDWR | O_CREAT, 0660);

    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Initialize lock structure
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    // Select read or write lock
    if (choice == 'w') {
        lock.l_type = F_WRLCK;
        printf("Trying to acquire WRITE lock...\n");
    }
    else if (choice == 'r') {
        lock.l_type = F_RDLCK;
        printf("Trying to acquire READ lock...\n");
    }
    else {
        printf("Invalid choice. Enter r for read lock or w for write lock.\n");
        close(fd);
        return 1;
    }

    // Apply lock
    if (fcntl(fd, F_SETLKW, &lock) < 0) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    if (lock.l_type == F_WRLCK)
        printf("WRITE lock acquired.\n");
    else
        printf("READ lock acquired.\n");

    printf("Process ID: %d\n", getpid());
    printf("Lock is held. Press Enter to release the lock...\n");

    getchar();
    getchar();

    // Unlock
    lock.l_type = F_UNLCK;

    if (fcntl(fd, F_SETLK, &lock) < 0) {
        perror("fcntl unlock");
        close(fd);
        return 1;
    }

    printf("Lock released.\n");

    close(fd);

    return 0;
}


/* Output:
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/16$ gcc mandatory_lock.c -o mandatory_lock
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/16$ ./manda
tory_lock
Enter r for read lock and w for write lock: r
Trying to acquire READ lock...
READ lock acquired.
Process ID: 5058
Lock is held. Press Enter to release the lock...
Lock released.

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/16$ ./mandatory_lock
Enter r for read lock and w for write lock: w
Trying to acquire WRITE lock...
WRITE lock acquired.
Process ID: 5069
Lock is held. Press Enter to release the lock...
Lock released.
*/
