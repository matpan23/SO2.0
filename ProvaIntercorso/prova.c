#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	pid_t pid1,pid2;

	pid1=fork();

	if(pid1<0){
		fprintf(stderr,"Errore nella fork\n");
		exit(-1);
	}
	if(pid1==0){
		int pf,i;
		pf=getpid();
		printf("il pid del primo figlio è [%d]\n",pf);
		for(i=1;i<=50;i++)
			printf("%d\n",i);
	}
	if(pid1>0){
		pid2=fork();

		if(pid2<0){
			fprintf(stderr,"Errore nella fork\n");
			exit(-1);
		}
		if(pid2==0){
			int pp;
			pp=getppid();
			printf("Il pid del padre è [%d]\n",pp);
			execlp("/bin/ls","ls",NULL);
		}
		if(pid2>0){
			waitpid(-1,NULL,0);
			waitpid(-1,NULL,0);
			printf("Il primo figlio con pid [%d] è terminato\n",pid1);
			printf("Il secondo figlio con pid [%d] è terminato\n",pid2);
		}
	}
}
