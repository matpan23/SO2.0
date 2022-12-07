#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void sig_fib(int sign){
    pid_t pidf1;
    int choose;
    if(sign==SIGINT){
        pidf1=fork();
        if(pidf1<0){
            printf("Errore nella fork di f1\n");
            exit(1);
        }
        if(pidf1==0){
            printf("Premere 0 per continuare, premere 1 per uscire\n\n");
            scanf("%d",&choose);
            if(choose==1){
                printf("Programma terminato\n");
                kill(getppid(),SIGKILL);
            }
            raise(SIGKILL);
        }
    }
}

int fibonacci(int n){
    if(n<=1)
        return n;
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    int i,j;
    pid_t pid1;

    if(signal(SIGINT,SIG_IGN)==SIG_ERR){
        printf("Errore nel sistema: SIGINT\n\n");
        exit(1);
    }

    pid1=fork();

    if(pid1<0){
        printf("Errore nella fork\n");
        exit(1);
    }
    if(pid1==0){
        if(signal(SIGINT,sig_fib)==SIG_ERR){
            printf("Errore nel sistema: SIGINT\n\n");
            exit(1);
        }
        for(i=1;i<=45;i++)
            printf("figlio:%d\n",fibonacci(i));
            sleep(5);
    }
    else if(pid1>0){
        printf("Il figlio pid1 con pid [%d] è terminato\n",wait(NULL));
    }
}
