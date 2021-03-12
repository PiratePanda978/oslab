#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void handler(int num){
printf(" CTRL-C will not work!!\n");
}

void handler1(int num){
printf(" kill -TERM will not work!!\n");
}

void handler2(int num){
printf(" Quit Signal will not work!!\n");
}

void handler3(int num){
printf(" Recieved user defined signal\n");
}

int main(){
signal(SIGINT, handler);	//Handler for INTERRUPT "ctrl-C" signal
signal(SIGTERM, handler1);	//Handler for TERMINATE "kill -TERM" signal
signal(SIGQUIT, handler2);	//Handler for QUIT "ctrl-/" signal
signal(SIGUSR1, handler3);	//Handler for user-defined "kill -USR1" signal
while(1){
printf("Infinite Process. %d\n",getpid());
sleep(2);
}
}
