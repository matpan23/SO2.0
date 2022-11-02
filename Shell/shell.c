#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[]){
    pid_t pid;
    char comm[512];

    do{
        printf("%%");
        scanf("%s",comm);
        pid=fork();

        switch(pid){
            case -1:
                fprintf(stderr,"Errore nella fork\n");
                exit(1);
            break;
            case 0:
                execlp(comm,comm,NULL);
            break;
        }
        wait(NULL);
    }while(strcmp(comm,"leave"));
}
