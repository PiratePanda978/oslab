#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h> //header file to provide access to POSIX OS API
int main()
{
int status, pid, pip[2];
char instring[20];
char outstring[20];
strcpy(outstring,"CSE2005\n");
//creating pipe
status=pipe(pip);
if(status == -1)
{
perror("Unable to create pipe");
exit(1);
}
//Write part
printf("Sending Message . . . \n");
write(pip[1],outstring, strlen(outstring)+1);
close(pip[1]); // close the write part
//Read partread(pip[0], instring, strlen(outstring)+1);
printf("Message Received. . .\n %s", instring);
close(pip[0]); // close the read part
}
