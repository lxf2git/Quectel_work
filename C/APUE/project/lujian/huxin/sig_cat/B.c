#include"apue.h"
void func(int sig,siginfo_t *info,void *p)
{
	if((char)info->si_value.sival_int != '\0')
	{
		strcat(file_na,(char*)&(info->si_value.sival_int));
	}
	else
	{
	union sigval v;
	int ret;
	char buf[10];
	int fd = open(file_na,O_RDONLY);
	if(fd < 0)
	{
		perror("open");
		exit(-1);
	}
	while(1)
	{
		memset(buf,0,strlen(buf));
		ret = read(fd,buf,1);
		if(ret< 0 )
		{
			perror("read");
			exit(-1);
		}
		if(ret == 0)
		{
			break;
		}
		v.sival_int = 0;
		v.sival_int =(int) *buf;
	   	sigqueue(info->si_pid,SIGUSR1,v);	
	   	usleep(200*1000);
	}
	sigqueue(info->si_pid,SIGUSR2,v);
	exit(0);
	}
}
int main()
{
	printf("niam\n");
	printf("B_id:%d\n",getpid());
	act.sa_sigaction = func;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1,&act,NULL);
	while(1)
	{
		;
	}

	return 0;
}
