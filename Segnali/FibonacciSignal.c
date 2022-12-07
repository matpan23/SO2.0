#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void sig_usr(int signo){
    if(signo == SIGINT){
		int i;
		printf("\r-1 per continuare\n-0 per uscire\n:");
		scanf("%d",&i);
		getchar();
		if(!i)
			exit(0);
    }
}
void printPID(int signo){
    if(signo == SIGINT)
		printf("\nPID: %d",getpid());
}
int fatt(int n){
	if(n==0)
		return 1;
	else
		return(n*fatt(n-1));
}
int fib(int n){
	if(n<=1)
		return n;
	else
		return (fib(n-1) + fib(n-2));
}
int main (void){
	signal(SIGINT,SIG_IGN);

	pid_t pid1,pid2;
	int i;

	pid1 = fork();// creazione pid 1 figlio

	switch(pid1){
		case -1: //errore 1 fork
			fprintf(stderr,"errore nella creazione della fork");
        break;
		case 0: // figlio 1
			if(signal(SIGINT,printPID) == SIG_ERR){
				printf("ERRORE DI SISTEMA : SIGINT\n");
				exit(1);
			}
			for(i=1;i<=30;i++){
				printf("Figlio 1:%d\n",fib(i));
				sleep(1);
			}
			exit(0);
		break;
	}
	pid2 = fork(); // creazione pid 2 figlio

	switch(pid2){
		case -1: //errore 2 fork
			fprintf(stderr,"errore nella creazione della fork");
		break;
		case 0: // figlio 2
			if(signal(SIGINT,sig_usr) == SIG_ERR){
				printf("ERRORE DI SISTEMA : SIGINT\n");
				exit(1);
			}
			for(i=1;i<=20;i++){
				printf("Figlio 2:%d\n",fatt(i));
				sleep(1);
			}
			exit(0);
		break;
	}
	printf("il figlio con pid %d e terminto\n",waitpid(-1,NULL,0));
	printf("il figlio con pid %d e terminto\n",waitpid(-1,NULL,0));
}
