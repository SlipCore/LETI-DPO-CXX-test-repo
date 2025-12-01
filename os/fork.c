#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pthread.h"
#include "sched.h"

int main() {
    pid_t pid = fork();
    pid_t ppid = getppid();

    int policy;
    struct sched_param param;
    pthread_getschedparam(pthread_self(), &policy, &param);

    if(pid == -1) { // fork() возвращает -1 при неудаче
        perror("Failed to fork");
        exit(1);
    }

    printf("Program started with pid %d, priority %d\n", pid, param.sched_priority);
    if(pid != 0) { // Родительский процесс
        int parent_value = 0;
        for (int i = 0; i < 128; i++) {
            parent_value += i;
        }
        
        printf("Parent variable: %d\n", parent_value);
        sleep(1); // (не обязательно)
    } else { // потомок, pid == 0
        int son_value = 0;
        for (int i = 0; i < 128; i++) {
            son_value += i * i;
        }
        
        printf("Son variable: %d\n", son_value);
    }

    system("ps");

    printf("Finished program with pid %d, ppid %d\n", pid, ppid);
    return 0;
}
