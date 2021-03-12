#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sigproc()
{
printf("you have pressed ctrl-c \n");
printf("Process ID : %d\n",getpid());
exit(0);
}

void quitproc()
{
printf("ctrl-c pressed to quit\n");
exit(0);
}

int main()
{
signal(SIGINT, sigproc);
signal(SIGQUIT, quitproc);
printf("use ctrl-c to quit\n");
for(;;);
}
