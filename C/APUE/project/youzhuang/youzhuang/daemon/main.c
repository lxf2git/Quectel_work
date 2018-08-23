#include"main.h"

int main()
{
		int fid;
		char c = 'a';
		signal(SIGHUP,fun);
		signal(SIGUSR1,fun);
		mydaemon(0,0);
		fid = open("/tmp/daemon",O_CREAT|O_EXCL|O_WRONLY|O_APPEND);
		if(fid<0)
		{
				perror("open");
				fid = open("/tmp/daemon",O_WRONLY|O_APPEND|O_TRUNC);
		}
		while(1)
		{
				write(fid, &c, 1);
				write(1, &c, 1);
				if(c=='z')
				{
						c = 'a'-1;
				}
				c++;
				sleep(2);
		}
		close(fid);
		return 0;
}

void fun(int sig)
{
		char time[50];
		int fid = open("/proc/uptime",O_RDONLY);
		int fid_daemon = open("/tmp/daemon",O_WRONLY|O_APPEND);
		int size;
		if(SIGUSR1==sig)
		{
				exit(0);
		}
		if(SIGHUP==sig)
		{
				size=read(fid,time,sizeof(time));
				write(fid_daemon, time, size);
		}
		close(fid);
}

int mydaemon(int nochdir, int noclose)
{
		int fid;
		int pid;
		pid=fork();
		if(pid==0)
		{
				setsid();
				umask(0);
				if(0==nochdir)
				{
						chdir("/");
				}
				if(0==noclose)
				{
						fid=open("/dev/null",O_RDONLY);
						dup2(fid,0);
						dup2(fid,1);
						dup2(fid,2);
				}
		}
		else
		{
				exit(0);
		}
		return 0;
}
