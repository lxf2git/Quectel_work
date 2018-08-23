#include"apue.h"

int mydaemon(int pid_chdir,int pid_close) 
{
	pid_t pid = fork();
	if(pid<0)
	{
		perror("fork");
		return -1;
	}	
	if(pid==0)
	{
		setsid();
		if(pid_chdir==0)
		{
			chdir("/");
		}
		if(pid_close==0)
		{
			int fd = open("/dev/null",O_RDWR);
			if(fd<0)
			{
				perror("open");
				return -1;
			}
			dup2(fd,0);
			dup2(fd,1);
			dup2(fd,2);
			close(fd);
			umask(0);	
		}
	}
	else
	{
		sleep(1);
		exit(0);
	}
}
