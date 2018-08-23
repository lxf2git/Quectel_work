#include"./apue.h"
void get_time(int pid)
{
	char buf[1024];
	int nb;
	memset(buf,0,sizeof(buf));
	int fd_rd=open("/proc/uptime",O_RDWR);
	if(fd_rd<0)
	{
		perror("open");
	}
	umask(0);
	int fd_wr=open("/root/Desktop/file.c",O_CREAT|O_RDWR|O_APPEND);
	if(fd_wr<0)
	{
		perror("open");
	}
	nb=read(fd_rd,buf,120);
	if(nb<0)
	{
		perror("read");
		exit(-1);
	}
	if(write(fd_wr,buf,nb)<0)
	{
		perror("write");
		exit(-1);
	}
	close(fd_rd);
	close(fd_wr);
}
void process_shut(int sig)
{
	char command[30];
	memset(command,0,sizeof(command));
	pid_t pid=getpid();
	sprintf(command,"kill -9 %d",pid);
	system(command);
}
int main()
{
	pid_t pid=getpid();
	printf("pid:%d\n",pid);
	daemon(0,0);
	signal(SIGHUP,get_time);
	signal(SIGUSR1,process_shut);
	while(1)
	{
		;
	}
}
