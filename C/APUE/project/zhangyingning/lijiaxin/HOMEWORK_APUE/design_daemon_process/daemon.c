#include "../apue.h"
pid_t pid;
void func1(int sig)
{
		if(sig!=SIGHUP)
		{
				perror("func1");
		}
		char wrrd_buf[20]={'\0'};
		char buf[20]={'\0'};
		int fd_rsc = open("/proc/uptime",O_RDONLY);
		if(fd_rsc<0)
		{
				perror("open1");
		}
	   	int fd_dest = open("/tmp/daemon",O_APPEND);	
		if(fd_dest<0)
		{
				perror("open2");
		}
		if(sig==SIGHUP)
		{
				read(fd_rsc,wrrd_buf,sizeof(wrrd_buf));
				write(fd_dest,wrrd_buf,sizeof(wrrd_buf));
		}
		if(sig==SIGUSR1)
		{
				sprintf(buf,"kill -9 %d",pid);
				system(buf);
		}
		close(fd_rsc);
		close(fd_dest);
}
int main()
{
		int fd;
		signal(SIGHUP,func1);
		signal(SIGUSR1,func1);
		daemon(0,0);
		pid = getpid();
		while(1)
		{
				sleep(100);
		}
		return 0;
}


