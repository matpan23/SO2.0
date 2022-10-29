#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[]){
    pid_t pid;
    pid=fork();

    if(pid<0){/*errore nella fork*/
        fprintf(stderr,"\nErrore nella fork\n");
        exit(-1);
    }
    else
        if(pid==0){/*sono nel figlio*/
            execlp("/bin/ls","ls",NULL);
        }
        else{/*sono nel padre*/
            wait(NULL);
            printf("il processo figlio con pid [%d] è terminto\n",getpid());
            exit(0);
        }
}
