#include"talk.h"
pid_t pid;
int fid;
int main()
{
		pid_t pid2=getpid();
		fid=open("talk.txt",O_CREAT|O_EXCL|O_RDWR|O_TRUNC,0666);
		if(fid<0)
		{
				fid=open("talk.txt",O_RDWR);
		}
		read(fid,&pid,sizeof(pid));
		write(fid,&pid2,sizeof(pid));
		signal(SIGUSR1,fun);
		signal(SIGUSR2,fun);
		kill(pid, SIGUSR2);
		while(1)
		{
		}
		return 0;
}

void fun(int sig)
{
		int len;
		char txt[100];
		if(sig==SIGUSR1)
		{
				len=read(fid,txt,sizeof(txt));
				txt[len]='\0';
				printf("%s\n",txt);
		}
		if(sig==SIGUSR2)
		{
		}
}
