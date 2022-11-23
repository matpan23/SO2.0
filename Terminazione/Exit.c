#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int pid,status,i=0;

    pid=fork();
    if(pid==0){
        printf("Figlio: sto per terminare\n");
        exit(0);
    }
    else{
        pid=wait(&status);
        if(WIFEXITED(status))
            printf("Terminazione volontaria di %d con stato %d\n",pid,WEXITSTATUS(status));
        else
            if(WIFSIGNALED(status))
                printf("Terminazione involontaria per segnale %d\n",WTERMSIG(status));
    }
}
