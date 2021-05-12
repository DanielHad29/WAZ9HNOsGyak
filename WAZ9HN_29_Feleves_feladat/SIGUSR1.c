#include <wait.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
int x=0;

void signal_handler1(int sig)
{
x=x+5;
printf("x=%d\n", x);
}
void signal_handler2(int sig)
{
x=x+5;
printf("x=%d\n", x);
}
void signal_handler3(int sig)
{
x=x+5;
printf("x=%d\n", x);
}

int main ()
{
pid_t pid;
signal(SIGINT, signal_handler1);
signal(SIGUSR1, signal_handler2);
signal(SIGUSR2, signal_handler3);

pid=fork();

if(pid==0)
{
 pid_t parent=getppid();
 kill(parent, SIGINT);
 sleep(1);
 kill(parent, SIGUSR1);
 sleep(1);
 kill(parent, SIGUSR2);
 sleep(1);
 return 0;
}
else
{
 int stat;
 wait(&stat);
}
return 0;
}
