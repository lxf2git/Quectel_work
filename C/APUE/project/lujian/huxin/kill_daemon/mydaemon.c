#include"apue.h"
void sig_fun(int sig)
{
	int src_fd,dest_fd;
	int ret;
	char buf[1024];
	memset(buf,0,sizeof(buf));
	src_fd = open("/proc/uptime",O_RDONLY);
	if(src_fd<0)
	{
		perror("open_file\n");
		exit(-1);
	}
	dest_fd = open("/tmp/mytime",O_CREAT|O_WRONLY|O_APPEND,0666);
	if(dest_fd<0)
	{
		perror("open_creat\n");
		exit(-1);
	}
	while(1)
	{
		ret = read(src_fd,buf,sizeof(buf));
		if(ret < 0)
		{
			perror("read");
			exit(-1);
		}
		if(ret == 0)
		{
			break;
		}
		ret = write(dest_fd,buf,ret);
		if(ret < 0)
		{
			perror("write");
			exit(-1);
		}
	}
}
void sig_func(int sig)
{
	exit(0);
}
void mydaemon()
{
	int fd;
	pid_t pid;
	pid = fork();
	if( pid<0 )
	{
		perror("fork");
		exit(-1);
	}
	if(pid>0)
	{
		exit(0);
	}
	printf("%d \n",getpid());
	umask(0);
	setsid();
	chdir("/");
	fd = open("/dev/null",O_RDWR);
	if(fd<0)
	{
		perror("open");
		exit(-1);
	}
	dup2(fd,0);
	dup2(fd,1);
	dup2(fd,2);
	close(fd);
}
int main()
{
	signal(SIGHUP,sig_fun);
	signal(SIGUSR1,sig_func);
	mydaemon();
	while(1)
	{
		;
	}
}
