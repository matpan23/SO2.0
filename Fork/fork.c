#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

/*pid t getpid(void); // process ID del processo chiamante
pid_t getppid(void); // process ID del padre del processo chiamante
*/

int main(void) {
    printf(" \n \n");
    printf("Il pid del processo figlio: [%d]\n", getpid());
    printf("Il pid del processo padre : [%d]\n", getppid());
    printf("\n[Fine programma]\n");
return 0;
}
// il processo padre è sempre uguale, a differenza del figlio che cambia ogni volta
// che si avvia il programma
