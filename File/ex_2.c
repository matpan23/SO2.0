#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<ctype.h>
#define BUFFSIZE 8192

int main(int argc, char **argv){
    int n,f1,f2;
    char buf[BUFFSIZE],*s;
    f1=open(argv[1],O_RDONLY);
    f2=open(argv[2],O_WRONLY | O_EXCL | O_CREAT,0600);

    while((n=read(f1,buf,BUFFSIZE))>0){
        for(s=buf;s-buf<n;s++)
            if(islower(*s))
                *s=toupper(*s);
            else if(isupper(*s))
                *s=tolower(*s);
            write(f2,buf,n);
    }
    close(f1);
    close(f2);
}
