#include"main.h"
int main()
{
		struct sigaction act;
		act.sa_sigaction = fun;
		act.sa_flags = SA_SIGINFO;
		sigemptyset(&act.sa_mask);
		sigaction(SIGUSR2, &act, NULL);
		if(fork()==0)
		{
				printf("%d %d\n",getpid(),getppid());
				int i=0;
				while(1)
				{
						union sigval v;
						v.sival_int = 'a'+i;
						sigqueue(getppid(),SIGUSR2,v);
						sleep(1);
						i++;
						if(i==26)
						{
								i=0;
						}
				}
		}
		else
		{
				while(1)
				{
						pause();
				}
		}
		return 0;
}

void fun(int sig,siginfo_t *info, void *p)
{
		printf("%c\n",info->si_value.sival_int);
}
