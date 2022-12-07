#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void sig_fatt(int sign){
    int scelta;
    if(sign==SIGINT){
        printf("Premere 0 per continuare, premere 1 per uscire\n\n");
        scanf("%d",&scelta);
        if(scelta==1)
            execl("/bin/echo","echo","Programma","Terminato",NULL);
        if(scelta==0)
            printf("Ricevuto SIGINT\n\n");
    }
}

void sig_fib(int sign){
    if(sign==SIGINT){
        printf("il Pid è [%d]\n",getpid());
    }
}

int fibonacci(int n){
    if(n<=1)
        return n;
    return fibonacci(n-1)+fibonacci(n-2);
}
int fattoriale(int n){
    if (n <= 1)
        return 1;
    return n*fattoriale(n-1);
}

int main(){
    int i,j;
    pid_t pid1,pid2;

    if(signal(SIGINT,SIG_IGN)==SIG_ERR){
        printf("Errore nel sistema: SIGINT\n\n");
        exit(1);
    }

    pid1=fork();

    if(pid1<0){
        printf("Errore nella fork pid1\n");
        exit(1);
    }
    if(pid1==0){
        if(signal(SIGINT,sig_fib)==SIG_ERR){
            printf("Errore nel sistema: SIGINT\n\n");
            exit(1);
        }
        for(i=1;i<=50;i++){
            printf("pid1: %d\n",fibonacci(i));
            sleep(1);
        }
        exit(0);
    }
    else if(pid1>0){
        pid2=fork();

        if(pid2<0){
            printf("Errore nella fork pid2\n");
            exit(1);
        }
        if(pid2==0){
            if(signal(SIGINT,sig_fatt)==SIG_ERR){
                printf("Errore nel sistema: SIGINT\n\n");
                exit(1);
            }
            for(j=1;j<=20;j++){
                printf("pid2: %d\n",fattoriale(j));
                sleep(1);
            }
            exit(0);
        }
    }
    else if(pid2>0){
        printf("\n\nil pid del primo figlio terminato è : %d\n",waitpid(pid1,NULL,0));
        printf("\nil pid del secondo figlio terminato è : %d\n",waitpid(pid2,NULL,0));
    }
}
