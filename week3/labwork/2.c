#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main()
{
    int num1;
    int num;
    char snum1[20];
    char snum[20];
    int status, pid, pip[2];
    status = pipe(pip);
    if (status == -1)
    {
        perror("Unable to create pipe");
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
        sprintf(snum, "%d", num);
        printf("Sending message\n%d\n", num);
        write(pip[1], snum, strlen(snum) + 1);
        close(pip[1]);
        exit(0);
    }
    else
    {
        close(pip[1]);
        read(pip[0], snum1, strlen(snum) + 1);
        sscanf(snum1, "%d", &num1);
        printf("Message recieved.\n%d\n", num1);
        close(pip[0]);
        pid = fork();
        if (pid == -1)
        {
            perror("Unable to create process");
            exit(2);
        }
        else if (pid == 0)
        {
            int i, t1 = 0, t2 = 1, nextTerm;
            for (i = 1; i <= num1; ++i)
            {
                nextTerm = t1 + t2;
                t1 = t2;
                t2 = nextTerm;
            }
            printf("The x by 2 term is %d\n", nextTerm/2);
            close(pip[0]);
            sprintf(snum,"%d",nextTerm/2);
            write(pip[1], snum, strlen(snum) + 1);
            close(pip[1]);
            exit(0);
        }
        else{
            close(pip[1]);
            read(pip[0], snum1, strlen(snum) + 1);
            sscanf(snum1, "%d", &num1);
            close(pip[0]);
            pid = fork();
            if (pid == -1)
            {
                perror("Unable to create process");
                exit(2);
            }
            else if (pid == 0){
                if(num1%2==0)
                printf("Even\n");
                else
                printf("Odd\n");
                exit(0);
            }
            exit(0);
        }
        exit(0);
    }
}
