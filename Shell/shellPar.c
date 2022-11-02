#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]){
    pid_t pid;
    char comm[512];
    char opt[22];
    char path[55];
    char *arg[20];

    do{
        printf("%%");
        scanf("%s%s%s",path,comm,opt);
        arg[0]=comm;
        arg[1]=opt;
        pid=fork();
        switch(pid){
            case -1:
                fprintf(stderr,"Errore nella fork\n");
                exit(1);
            break;
            case 0:
                execv(path,arg);
            break;
        }
        wait(NULL);
    }while(666);
}
