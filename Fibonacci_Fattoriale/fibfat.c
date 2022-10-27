#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

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
int main(void){
    pid_t pid;

    pid=fork();
    switch(pid){
        case -1:
            fprintf(stderr,"Errore nella fork\n");
            exit(-1);
        break;
        case 0:
            printf("pid del figlio [%d]\n",getpid());
            for(int i=0;i<10;i++)
                printf("%d\n",fibonacci(i));
        break;
        default:
            for(int i=0;i<10;i++)
                printf("%d\n",fattoriale(i));
        break;
    }
return 0;
}
