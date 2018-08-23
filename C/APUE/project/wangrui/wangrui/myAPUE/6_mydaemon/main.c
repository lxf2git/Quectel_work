#include "../apue.h"

int main()
{
	pid_t pid;
	int fdNull,fdIn;
	umask(0);
	pid = fork();
	if(pid == 0)
	{
		setsid();
		chdir("/");
		fdNull =  open("/dev/null",O_RDWR);
		if(fdNull<0)
		{
			perror("open");
			exit(-1);
		}
		fdIn = open("/tmp/daemon",O_EXCL|O_CREAT,0777);
		if(fdIn<0)
		{
			if(fdIn == EEXIST)
			{
				fdIn = open("/tmp/daemon",O_RDWR);
				if(fdIn<0)
				{
					perror("open");
					close(fdNull);
					exit(-1);
				}
			}
			else
			{
				perror("open");
				close(fdNull);
				exit(-1);
			}
		}
		dup2(0,fdNull);
		dup2(1,fdNull);
		dup2(2,fdNull);
		while(1)
		{
			write(fdIn,"a",1);
			sleep(2);
		}
	}

	return 0;
}
