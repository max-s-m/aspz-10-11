#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pid = fork();
    if(pid < 0){
        printf("forkn't\n");
        exit(1);
    }
    else if(pid > 0){
        printf("This is parent, waiting for child...\n");
        int status;
        pid_t child_pid = wait(&status); //чекає завершення дочірнього процесу
        printf("This is parent, child %d exited\n", child_pid);
        if(WIFEXITED(status)){ //процес завершився нормально
            printf("Exited with code %d\n", WEXITSTATUS(status)); //код завершення дочірнього
        }
        else{
            printf("Exit trouble\n");
        }
    }
    else{
        printf("This is child %d, exit(69)...\n", getpid());
        exit(69);
    }
}
