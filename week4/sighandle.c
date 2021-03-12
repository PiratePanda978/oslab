#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>  

#define   MAX_i    10000
#define   MAX_j    20000

#define   MAX_SECOND  (2)

void  INThandler(int); 
void  ALARMhandler(int);

int  SECOND; 
int  i, j;

void  INThandler(int sig)
{
     char  c;
     signal(SIGINT, SIG_IGN);       
     signal(SIGALRM, SIG_IGN);      
     printf("*** INT handler --> You just hit Ctrl-C\n");
     printf("*** INT handler --> current values of i and j = %d and %d\n",
             i, j);
     printf("*** INT handler --> Do you really want to quit? [y/n] ");
     c = getchar();      
     if (c == 'y') {
          printf("*** INT handler --> Program halts due to your request.\n");
          exit(0);
     }
     signal(SIGINT, INThandler);   
     signal(SIGALRM, ALARMhandler);  
     alarm(SECOND);
}

void  ALARMhandler(int sig)
{
     signal(SIGINT, SIG_IGN);  
     signal(SIGALRM, SIG_IGN);     
     printf("*** ALARM handler --> an alarm signal arrives\n");
     printf("*** ALARM handler --> current values of i and j = %d and %d\n",
             i, j);
     alarm(SECOND);              
     signal(SIGINT, INThandler);     
     signal(SIGALRM, ALARMhandler);
}

void  main(int argc, char *argv[])
{
     long  sum;

     if (argc != 2) {
          printf("Use: %s time-interval\n", argv[0]);
          printf("Time interval set to default (%d).\n", MAX_SECOND);
          SECOND = MAX_SECOND;
     }
     else {
          SECOND = abs(atoi(argv[1]));
          if (SECOND == 0) {
               printf("Time interval must be positive.  Use default (%d).\n",
                      MAX_SECOND);
               SECOND = MAX_SECOND;
          }
     }
     signal(SIGINT, INThandler);
     signal(SIGALRM, ALARMhandler);
     alarm(SECOND);
     for (i = 1; i <= MAX_i; i++)  {   
          sum = 0;                     
          for (j = 0; j <= MAX_j; j++)
               sum += j;
     }
     printf("Computation is done.\n\n");
}