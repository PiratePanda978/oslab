#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main() 
{ 
    for(int i=0;i<4;i++)
    { 
        if(fork() == 0) 
        { 
            printf("[child process] pid %d from [parent process] pid %d\n",getpid(),getppid()); 
            exit(0); 
        } 
    } 
    for(int i=0;i<4;i++)
    wait(NULL);
} 
