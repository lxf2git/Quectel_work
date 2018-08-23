#include"talk.h"
pid_t pid;
int main()
{
		struct sigaction act;
		act.sa_sigaction = func;
		act.sa_flags = SA_SIGINFO;
		sigemptyset(&act.sa_mask);
		sigaction(SIGUSR1, &act, NULL);

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

		char fname[100];
		union sigval v;
		printf("input:\n");
		scanf("%s",fname);
		int i=0;
		while(fname[i]!=0)
		{
				printf("%c",fname[i]);
				fflush(stdout);
				v.sival_int = fname[i];
				sigqueue(pid,SIGUSR1,v);
				i++;
				usleep(1);
		}
		printf("\n");
		v.sival_int = fname[i];
		sigqueue(pid,SIGUSR1,v);
		while(1)
		{
		}

		return 0;
}

void func(int sig, siginfo_t *info, void *p)
{
		printf("%c",info->si_value.sival_int);
		fflush(stdout);
}

void fun(int sig)
{
		if(sig==SIGUSR2)
		{
		}
}
