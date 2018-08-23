#include "../apue.h"

int my_daemon(int nochdir,int noclose)
{
		pid_t pid = fork();
		if(pid<0)
		{
				perror("fork");
				return -1;
		}
		if(pid==0)
		{
				if(nochdir==0)
				{
						chdir("/");
				}
				if(noclose==0)
				{
						int fd = open("/dev/null",O_RDWR);
						dup2(fd,0);
						dup2(fd,1);
						dup2(fd,2);
						close(fd);
				}
				setsid();
				umask(0);
		}
		else
		{
				sleep(1);
				exit(0);
		}
}
