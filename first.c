#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){

  pid_t pid;

  pid=fork();

  if(pid==-1)
    fprintf(stderr,"Errore nella fork\n\n");
  if(pid>0){
    printf("Sono nel figlio\n");
  }//figlio
  if(pid== 0){
    printf("Sono nel padre\n");
    printf("PID del figlio %d\n",pid);
  }
}
