#include"../../apue.h"	
struct sigaction act;
char buf[1024]={'\0'};
pid_t pid;
char date;

void show()
{
	int fd = open(buf,O_RDONLY);
	if(fd<0)
	{
		show_err("open");
	}	
	char ch;
	int end;
	union sigval v_b;
	while(1)
	{
		if(end=read(fd,&ch,sizeof(char))==0)
		{
			kill(SIGINT,pid);
			exit(0);
		}
		v_b.sival_int = (int)ch;
		sigqueue(pid,SIGUSR2,v_b);
		sleep(1);
	}
}

void func(int sig,siginfo_t *info,void *p)
{
	printf("receive pid:%d\n",info->si_pid);
	printf("date:%c\n",info->si_value.sival_int);
	if(info->si_value.sival_int=='\n')
	{
		pid = info->si_pid;
		show();
		return;
	}
	date =(char)info->si_value.sival_int;
	strcat(buf,&date);
}

int main()	
{
	printf("send_pid:%d\n",getpid());
	act.sa_sigaction = func;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1,&act,NULL);

	for(;;)
	{
		sleep(10);
	}

	return 0;	
}
