#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
    printf("sopra la panca\n");
    execl("/bin/echo","echo","la","capra","campa",NULL);
    printf("sotto la panca la capra crepa\n");
}
