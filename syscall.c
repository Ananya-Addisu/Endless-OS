#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3;
    pid_t pgid;
    
    printf("Parent process PID: %d\n", getpid());
    
    pid1 = fork();
    if (pid1 < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid1 == 0) {
        printf("First child PID: %d, Parent PID: %d\n", getpid(), getppid());
        
        if (setpgid(0, 0) < 0) {
            perror("setpgid failed");
            exit(1);
        }
        
        printf("First child's process group ID: %d\n", getpgrp());
        sleep(2);
        exit(0);
    }
    
    pid2 = fork();
    if (pid2 < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid2 == 0) {
        printf("Second child PID: %d, Parent PID: %d\n", getpid(), getppid());
        
        if (setpgid(0, pid1) < 0) {
            perror("setpgid failed");
            exit(1);
        }
        
        printf("Second child's process group ID: %d\n", getpgrp());
        sleep(3);
        exit(0);
    }
    
    pid3 = fork();
    if (pid3 < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid3 == 0) {
        printf("Third child PID: %d, Parent PID: %d\n", getpid(), getppid());
        
        if (setpgid(0, 0) < 0) {
            perror("setpgid failed");
            exit(1);
        }
        
        printf("Third child's process group ID: %d\n", getpgrp());
        sleep(4);
        exit(0);
    }
    
    sleep(1);
    
    printf("\nParent process group ID: %d\n", getpgrp());
    
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    waitpid(pid3, NULL, 0);
    
    printf("All child processes have completed.\n");
    return 0;
}