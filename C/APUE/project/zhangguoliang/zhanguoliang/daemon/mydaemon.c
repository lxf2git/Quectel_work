#include"main.h"

void show_err(int i,char *buf)
{
	if(i<0)
	{
		perror(buf);
		exit(-1);
	}
}

void mydaemon(int nochdir,int noclose)
{
	pid_t pid = fork();
	if(pid<0)
	{
		perror("fork");
		exit(-1);
	}
	if(pid==0)
	{
		if(nochdir==0)
		{
			chdir("/");
		}
		setsid();
		umask(0);
		int de=open("/dev/null",O_RDWR);
		show_err(de,"open dev/null");
		if(noclose==0)
		{
			show_err(dup2(de,0),"dup2 0");
			show_err(dup2(de,1),"dup2 1");
			show_err(dup2(de,2),"dup2 2");
	//		dup2(de,1);
	//		dup2(de,2);
		}
		return ;
	}
	exit(0);
}
