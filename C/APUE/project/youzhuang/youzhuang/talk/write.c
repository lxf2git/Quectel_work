#include"talk.h"
pid_t pid;
int main()
{
		char txt[100];
		pid=getpid();
		int fid=open("talk.txt",O_CREAT|O_EXCL|O_RDWR|O_TRUNC,0666);
		if(fid<0)
		{
				fid=open("talk.txt",O_RDWR|O_TRUNC);
		}
		write(fid,&pid,sizeof(pid));
		signal(SIGUSR2,fun);
		pause();
		read(fid,&pid,sizeof(pid));
		while(1)
		{
				scanf("%s",txt);
				write(fid,txt,strlen(txt));
				kill(pid, SIGUSR1);
		}
		return 0;
}

void fun(int sig)
{
		if(sig==SIGUSR2)
		{
		}
}
