#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

int fd[2];
int count;
void fun(int sig)
{
		char buf;
		read(fd[0],&buf,sizeof(char));
		if(65<=buf&&buf<=90)
				buf+=32;
		printf("%c",buf);
		fflush(NULL);
/*		if(buf == '\n')
		{
				kill(getppid(),SIGKILL);
				exit(0);
		}
*/

}
void fun1(int sig)
{
		count = 0;
}
int main()
{
		char buf;
		int pid,pid1,ret;
		pipe(fd);
		if((pid=fork()) == 0)
		{
				signal(SIGUSR1,fun);
				close(fd[1]);
				while(1);
		}
		else
		{
				close(fd[0]);
				if((pid1=fork()) == 0)
				{
						signal(SIGUSR1,fun1);
						while(1)
						{
								usleep(1000*500);
								count++;
								if(count == 10)
								{
										kill(pid,SIGKILL);
										kill(getppid(),SIGKILL);
										exit(0);
								}
						}
				}
				else
				while((ret = read(0,&buf,sizeof(char))) > 0)
				{
						write(fd[1],&buf,sizeof(char));
						kill(pid,SIGUSR1);
						kill(pid1,SIGUSR1);
						usleep(1000*50);
				}
		}
}
