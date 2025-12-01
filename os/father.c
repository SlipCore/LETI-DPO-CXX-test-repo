#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sched.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include "pthread.h"

int main(int argc, char **argv){
    pid_t pid = getpid();             // PID (Process ID) - идентификтор процесса. getpid() - получение PID
    pid_t ppid = getppid();           // PPID (Parent Process ID) - идентификатор процесса-родителя. getppid() - получение PPID
    pid_t sid = getsid(pid);          // SID (Session ID) - идентификтор текущей сессии. getsid() - получение SID
    pid_t pidCopy;
	
    printf("Father: sid = %d pid=%d ppid=%d \n", sid, pid, ppid);    // Вывод информации о процессе-отце
    
    system("echo \"\" > result.txt"); // Очищаем файл с выводом

    int policy;
    struct sched_param param;
    struct timespec qp;
    pthread_getschedparam(pthread_self(), &policy, &param);

    param.sched_priority = 50;
    if (sched_setscheduler(pid, SCHED_RR, &param) == -1) // устанавливаем RR политику
        perror("SCHED_SETSCHEDULER_1");

    if (sched_rr_get_interval(pid, &qp) == -1)	// определяем величину кванта
        perror("SCHED_RR_GET_INTERVAL");
    else
        printf("Квант при циклическом планировании: %ld сек %ld нс\n", qp.tv_sec, qp.tv_nsec);

    if((pidCopy = fork()) == 0){            // Клонирование текущего процесса для пункта a)
        execl("son.out", "son.out", "1", NULL);      // Замена текущего образа процесса на новый (просто говоря порождение другого процесса)
    } if(fork() == 0){                        
        execl("son.out", "son.out", "2", NULL);      // То же самое, но для пункта б)
    } if(fork() == 0){
        execl("son.out", "son.out", "3", NULL);      // То же самое, но для пункта в)
    }

    system("ps xjf >> result.txt");
	
    while(1) {
        sleep(1);
    }

    int status;
	waitpid(pidCopy, &status, WNOHANG); // Ожидание завершения процесса son_a. WNOHANG - флаг текущей команды,
                                        // предназначеный для немедленного возвращения управления, если ни один из текущих потомков не завершился
    return 0;
}