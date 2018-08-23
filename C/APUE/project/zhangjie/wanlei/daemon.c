#include "apue.h"

int my_daemon(int nochdir, int noclose);

int main()
{
	my_daemon(0,0);
	int fid = open("/tmp/daemon", O_CREAT|O_EXCL|O_RDWR, 0777);
	if(fid < 0)
	{
		if(EEXIST == errno)
		{
			 fid = open("/tmp/daemon", O_TRUNC|O_RDWR);
			 if(fid < 0)
			 {
			 	return -1;
			 }
		}
		else
		{
			return -1;
		}
	}
	char ch = 'a';
	while(1)
	{
		write(fid, &ch, 1);
		write(1, &ch, 1);
		if(ch == 'z')
		{
			ch = 'a'-1;
		}
		ch++;
		sleep(2);
	}
	close(fid);
	return 0;
}

int my_daemon(int nochdir, int noclose)
{
	pid_t pid = fork();
	int fd;
	if(0 == pid)
	{
		setsid();
		if(nochdir == 0)
		{
			chdir("/");
		}
		if(noclose == 0)
		{
			fd = open("/dev/null", O_RDWR);
			if(fd < 0)
			{
				perror("open");
				return -1;
			}
			dup2(fd, 0);
			dup2(fd, 1);
			dup2(fd, 2);
		}
		umask(0);
		return 0;
	}
	else
	{
		exit(0);
	}
}
