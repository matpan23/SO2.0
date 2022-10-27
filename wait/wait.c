#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    int value, value2;

    value = fork();
    if(value < 0) return 0;

    if(value == 0) 
        printf("Il pid del primo figlio: %d e il pid del padre: %d\n", getpid(), getppid());
    else if(value > 0) {
        value2 = fork();
        if (value2 < 0) return 0;

        if(value2 == 0) {
            printf("La somma del pid del figlio e del pid del padre: %d\n", getppid() + getpid());
        }
        else if (value2 > 0) {
            printf("Terminazione del primo figlio con pid %d\n", wait(NULL));
            printf("Terminazione del secondo figlio con pid %d\n", wait(NULL));
        }
    }
}
