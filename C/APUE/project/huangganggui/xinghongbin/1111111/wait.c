//#include"/home/apue/apue.h"
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
void fun()
{
		printf("asd\n");
}
int main()
{
		if(fork()== 0)
		{
				union sigval v;
				sigqueue(getppid(),SIGUSR1,v);
				while(1);
				
		}
		else
		{
		struct sigaction act;
		act.sa_sigaction = fun;
		act.sa_flags = SA_SIGINFO;
		sigemptyset(&act.sa_mask);
		sigaction(SIGUSR1,&act,NULL);
				wait(NULL);
		}

}
