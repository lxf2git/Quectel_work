#include"talk.h"
pid_t pid;
int fid;
int i;
int main()
{
		struct sigaction act;
		act.sa_sigaction = func;
		act.sa_flags = SA_SIGINFO;
		sigemptyset(&act.sa_mask);
		sigaction(SIGUSR1, &act, NULL);

		pid_t pid2=getpid();
		fid=open("talk.txt",O_CREAT|O_EXCL|O_RDWR|O_TRUNC,0666);
		if(fid<0)
		{
				fid=open("talk.txt",O_RDWR);
		}
		read(fid,&pid,sizeof(pid));
		write(fid,&pid2,sizeof(pid));
		kill(pid, SIGUSR2);
		while(1)
		{
		}
		return 0;
}

void func(int sig, siginfo_t *info, void *p)
{
		int red;
		char ch;
		char fname[100];
		union sigval v;
		if(info->si_value.sival_int!=0)
		{
				fname[i]=info->si_value.sival_int;
				i++;
		}
		else
		{
				fname[i]='\0';
				printf("%s\n",fname);
				fid=open(fname,O_RDWR);
				if(fid<0)
				{
						perror("open");
						kill(pid,SIGKILL);
						exit(0);
				}
				red=read(fid, &ch, 1);
				while(red!=0)
				{
						v.sival_int = ch;
						sigqueue(pid, SIGUSR1, v);
						red=read(fid, &ch, 1);
						usleep(1);
				}
				kill(pid,SIGKILL);
				exit(0);
		}
}
