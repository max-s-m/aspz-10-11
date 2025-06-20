#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    printf("Creating 3 children\n");
    for(int i = 0; i < 3; i++){
        pid_t pid = fork();
        if(pid == 0){
            printf("Child %d\n", i);
            exit(0);
        }
    }
    while(wait(NULL) > 0); // чекає всіх
    printf("All children exited\n");
}
