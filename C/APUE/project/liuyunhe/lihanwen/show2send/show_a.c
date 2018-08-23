#include"../apue.h"	

void func(int sig,siginfo_t *info,void *p)
{
	printf("%c",info->si_value.sival_int);
	fflush(stdout);
	sleep(1);
}

int main(int argc,char *argv[])	
{
	if(argc!=2)
	{
		printf("%s filename\n",argv[0]);
		exit(-1);
	}

	char ch;
	int len,i;
	union sigval v;
	pid_t pid;

	struct sigaction show_act;
	show_act.sa_sigaction = func;
	show_act.sa_flags = SA_SIGINFO;
	sigemptyset(&show_act.sa_mask);
	sigaction(SIGUSR2,&show_act,NULL);

	len = strlen(argv[1]);
	printf("show_pid:%d\n",getpid());
	printf("input link_pid:\n");
	scanf("%d",&pid);
	char buf[2]={'\n'};
	strcat(argv[1],buf);
	for(i=0;i<=len;i++)
	{
		ch = argv[1][i];
		v.sival_int = (int)ch;
		printf("%c\n",ch);
		sigqueue(pid,SIGUSR1,v);
		sleep(1);
	}

	for(;;)
	{
		sleep(10);
	}

	return 0;	
}
