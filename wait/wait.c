#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main (void){
    pid_t pid1,pid2;

    pid1= fork();

    if(pid1<0){
        fprintf(stderr,"errore nella system call fork");
        exit(0);
    }
    else
        if(pid1==0){
            printf("il pid del primo figlio è: %d \n", getpid());
            for(int i=1; i<=50;i++){
                printf("%d\t",i);
            }
        }
    else{
        pid2= fork();
        if(pid2<0){
            fprintf(stderr,"errore nella system call fork");
            exit(0);
        }
        else
            if(pid2==0){
                printf("\n\n il pid del padre è %d\n\n",getppid());
                for(int j=101;j<=150;j++){
                    printf("%d\t",j);
                }
            }
            else{
                printf("\n\nil pid del primo figlio terminato è : %d\n",waitpid(-1,NULL,0));
                printf("\nil pid del secondo figlio terminato è : %d\n",waitpid(-1,NULL,0));
            }
    }
return 0;
}
