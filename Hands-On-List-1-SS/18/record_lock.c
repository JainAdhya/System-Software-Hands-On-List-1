#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

struct record {
    int id;
    char name[30];
    int marks;
};

void lock_record(int fd, int record_no, short lock_type) {
    struct flock lock;

    lock.l_type = lock_type;
    lock.l_whence = SEEK_SET;
    lock.l_start = (record_no - 1) * sizeof(struct record);
    lock.l_len = sizeof(struct record);
    lock.l_pid = getpid();

    if (fcntl(fd, F_SETLKW, &lock) < 0) {
        perror("fcntl");
        exit(1);
    }
}

void unlock_record(int fd, int record_no) {
    struct flock lock;

    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (record_no - 1) * sizeof(struct record);
    lock.l_len = sizeof(struct record);
    lock.l_pid = getpid();

    if (fcntl(fd, F_SETLK, &lock) < 0) {
        perror("unlock");
        exit(1);
    }
}

int main() {
    int fd;
    int choice, record_no;
    struct record r;

    // Open/create the file
    fd = open("records.dat", O_RDWR | O_CREAT, 0660);

    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Check if file is empty and create three records
    if (lseek(fd, 0, SEEK_END) == 0) {
        struct record records[3] = {
            {1, "Adhya", 85},
            {2, "Student 2", 90},
            {3, "Student 3", 78}
        };

        write(fd, records, sizeof(records));

        printf("Three records created successfully.\n");
    }

    printf("\nEnter 1 for READ lock\n");
    printf("Enter 2 for WRITE lock\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter record number (1-3): ");
    scanf("%d", &record_no);

    if (record_no < 1 || record_no > 3) {
        printf("Invalid record number.\n");
        close(fd);
        return 1;
    }

    // ------------------------------------------------
    // READ LOCK
    // ------------------------------------------------

    if (choice == 1) {

        printf("\nTrying to acquire READ lock on record %d...\n",
               record_no);

        lock_record(fd, record_no, F_RDLCK);

        printf("READ lock acquired on record %d.\n", record_no);

        // Move to selected record
        lseek(fd,
              (record_no - 1) * sizeof(struct record),
              SEEK_SET);

        // Read the record
        if (read(fd, &r, sizeof(struct record)) != sizeof(struct record)) {
            perror("read");
            unlock_record(fd, record_no);
            close(fd);
            return 1;
        }

        printf("\nRecord information:\n");
        printf("ID    : %d\n", r.id);
        printf("Name  : %s\n", r.name);
        printf("Marks : %d\n", r.marks);

        printf("\nPress Enter to release the lock...");
        getchar();
        getchar();

        unlock_record(fd, record_no);

        printf("READ lock released.\n");
    }

    // ------------------------------------------------
    // WRITE LOCK
    // ------------------------------------------------

    else if (choice == 2) {

        printf("\nTrying to acquire WRITE lock on record %d...\n",
               record_no);

        lock_record(fd, record_no, F_WRLCK);

        printf("WRITE lock acquired on record %d.\n", record_no);

        // Move to selected record
        lseek(fd,
              (record_no - 1) * sizeof(struct record),
              SEEK_SET);

        // Read the selected record
        if (read(fd, &r, sizeof(struct record)) != sizeof(struct record)) {
            perror("read");
            unlock_record(fd, record_no);
            close(fd);
            return 1;
        }

        printf("\nCurrent record:\n");
        printf("ID    : %d\n", r.id);
        printf("Name  : %s\n", r.name);
        printf("Marks : %d\n", r.marks);

        // Modify marks
        printf("\nEnter new marks: ");
        scanf("%d", &r.marks);

        // Move back to the beginning of the record
        lseek(fd,
              (record_no - 1) * sizeof(struct record),
              SEEK_SET);

        // Write modified record
        if (write(fd, &r, sizeof(struct record)) != sizeof(struct record)) {
            perror("write");
            unlock_record(fd, record_no);
            close(fd);
            return 1;
        }

        printf("Record %d modified successfully.\n", record_no);

        unlock_record(fd, record_no);

        printf("WRITE lock released.\n");
    }

    else {
        printf("Invalid choice.\n");
    }

    close(fd);

    return 0;
}


/* Output:

adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/18$ gcc record_lock.c -o record_lock
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/18$ ./record_lock
Three records created successfully.

Enter 1 for READ lock
Enter 2 for WRITE lock
Enter your choice: 1
Enter record number (1-3): 1

Trying to acquire READ lock on record 1...
READ lock acquired on record 1.

Record information:
ID    : 1
Name  : Adhya
Marks : 85

Press Enter to release the lock...
READ lock released.
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/18$ ./record_lock

Enter 1 for READ lock
Enter 2 for WRITE lock
Enter your choice: 2
Enter record number (1-3): 2

Trying to acquire WRITE lock on record 2...
WRITE lock acquired on record 2.

Current record:
ID    : 2
Name  : Student 2
Marks : 90

Enter new marks: 95
Record 2 modified successfully.
WRITE lock released.
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/18$ ./record_lock

Enter 1 for READ lock
Enter 2 for WRITE lock
Enter your choice: 1
Enter record number (1-3): 2

Trying to acquire READ lock on record 2...
READ lock acquired on record 2.

Record information:
ID    : 2
Name  : Student 2
Marks : 95

Press Enter to release the lock...
READ lock released.
*/
