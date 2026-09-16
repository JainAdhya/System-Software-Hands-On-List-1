#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd;
    fd = creat("myfile.txt", 0644);
    if(fd < 0){
        perror("File creation failed");
        exit(1);
    }

    printf("File created successfully!\n");
    printf("File descriptor value: %d\n", fd);

    close(fd);  
    return 0;
}


/*Output:
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/3$ gcc create_file.c -o create_file
adhya@adhya:~/System-Software-Hands-On-List-1/Hands-On-List-1-SS/3$ ./create_file
File created successfully!
File descriptor value: 3
*/
