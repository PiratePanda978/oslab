#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main()
{
int num1,num2,sum,square1;
int a,b,d;
int c = 0;
int num;
char snum1[20];
char snum[20];
int status, pid, pip[2];
status = pipe(pip);
if (status == -1)
{perror("Unable to create pipe");
exit(1);
}
pid = fork();
if (pid == -1)
{
perror("Unable to create process");
exit(2);
}
else if (pid == 0)
{
close(pip[0]);
num = (rand() % (100 - 0 + 1)) + 0;
num2 = (rand() % (100 - 0 + 1)) + 0;
sum = num + num2;
a = sum*sum;
a = a/2;
sprintf(snum, "%d", sum);
write(pip[1], snum, strlen(snum) + 1);
close(pip[1]);
exit(0);
}
else
{
close(pip[1]);
read(pip[0], snum1, strlen(snum) + 1);
sscanf(snum1, "%d", &num1);
square1 = num1*num1;
for(int i=1;i<=a;i++){
if(a%i==0)
c++;
}
if(c==2)
printf("Hello My name is Anupam Kunwar, the generated number %d is prime\n");
else
printf("Hello My name is Anupam Kunwar, the generated number %d is not prime\n");
close(pip[0]);
pid = fork();
if (pid == -1)
{
perror("Unable to create process");
exit(2);
}
else if (pid == 0)
{
int halfNo;
halfNo = square1/2;
close(pip[0]);
sprintf(snum,"%d",halfNo);
write(pip[1], snum, strlen(snum) + 1);
close(pip[1]);
exit(0);
}
else{
exit(0);
}
exit(0);
}
}
