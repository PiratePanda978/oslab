#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
printf("PID of first process = %d\n", getpid());
char *args[] = {"Hello", "Hi", "System calls", NULL};
execv("./second", args);
printf("Back to example.c");
return 0;
}
