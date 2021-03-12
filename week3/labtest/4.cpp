#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
#include<unistd.h> //header file to provide access to POSIX OS API
int main()
{
int status, pid, pip[2];
char instring[20];
char outstring[20];
strcpy(outstring,"Hi I am child");
//creating pipe
status=pipe(pip);
if(status == -1){
perror("Unable to create pipe");
exit(1);
}
pid = fork(); //create child process
if(pid == -1) {
perror("Unable to create process");
exit(2);}
else if(pid == 0) {
// child process: send message to parents
close(pip[0]);
//close the read part of pipe
printf("Sending Message . . . \n");
write(pip[1],outstring, strlen(outstring)+1);
close(pip[1]);
// writing done, close it
exit(0);
}
else {
// parent process: read message from child
close(pip[1]);
//close the write part of pip
read(pip[0], instring, strlen(outstring)+1);
printf("Message Received. . .\n %s\n",instring);
close(pip[0]);
// Read done, close it
exit(0);
}
}
