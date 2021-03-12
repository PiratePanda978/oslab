#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(void)
{
pid_t pid = fork();
int exit;
if (pid != 0)
{
wait(&exit);
}
printf("Hello VITians \n: %d\n", pid);
}
