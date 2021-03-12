#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main()
{
int status, pid, pip[2];
char instring[20];
char outstring[20];
strcpy(outstring,"CSE2005");
status=pipe(pip);
if(status == -1)
{
perror("Unable to create pipe");
exit(1);
}
printf("Sending Message . . . \n");
write(pip[1],outstring, strlen(outstring)+1);
close(pip[1]);
printf("Message Received. . .\n %s", instring);
close(pip[0]);
}
