#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void sig_handler(int signum);

int main(){
    //обробник сигналу SIGCHLD
    signal(SIGCHLD, sig_handler);
    pid_t pid = fork();
    if(pid < 0){
        printf("forkn't");
        exit(1);
    }
    if(pid > 0){ //батьківський процес
        printf("This is parent, created child %d, waiting for sig...\n", pid);
        //з pause() батько засинає і чекає на якийсь сигнал
        pause();
        printf("Parent exiting...\n");
    }
    else{ //дочірній
        printf("This is child %d, waiting 3 sec...\n", getpid());
        sleep(3);
        printf("Child exiting...\n");
        exit(0);
    }
}
//обробник SIGCHLD, викликається коли дочірній процес зупиняється
void sig_handler(int signum){
    //дочірній процес збирається (reap), щоб не став zombie
    wait(NULL);
    printf("SIGCHLD detected, child exited\n");
}
