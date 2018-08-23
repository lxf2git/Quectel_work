#include"../apue.h"

void mydaemon()
{
	int fd;	
	pid_t pid;	
	pid = fork();
	if(pid<0)
	{
		show_err("fork");
	}
	if(pid>0)
	{
		exit(0);
	}
	umask(0);
	setsid();
	chdir("/");
	fd = open("/dev/null",O_RDWR);
	if(fd<0)
	{
		show_err("fd");
	}
	dup2(fd,0);
	dup2(fd,1);
	dup2(fd,2);
	close(fd);
}
int main()
{
	int fd;
	char c = 'a';	
	mydaemon();//daemon(0,0);
	fd = open("/tmp/daemon",O_CREAT|O_RDWR);	
	if(fd<0)
	{
		show_err("open");
	}
	while(1)
	{
		write(fd,&c,1);
		write(1,&c,1);
		if(c=='z')
		{
			c = 'a'-1;
		}
		c++;
		sleep(2);
	}
	close(fd);
	return 0;

}
