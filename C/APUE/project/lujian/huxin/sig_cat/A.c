#include"apue.h"
void func(int sig,siginfo_t *info,void *p)
{
	int num;
	printf("%c",info->si_value.sival_int);
	fflush(stdout);
}
void fun(int sig)
{
	printf("file read succeed\n");
	exit(0);
}

int main(int argc,char **argv)
{
	if(argc != 3 )
	{
		printf("%s PGID file_name\n",argv[0]);
		return -1;
	}
	int in,i;
	char *p = argv[2];
	int num;
	act.sa_sigaction = func;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1,&act,NULL);
	signal(SIGUSR2,fun);
	union sigval v;
	num = strlen(argv[2]);
	for(i = 0;i < num+1; i++)
	{
			v.sival_int = *p++;
			in = atoi(argv[1]);
			sigqueue(in,SIGUSR1,v);
			usleep(20*1000);
	}
	for(;;)
	{
		;
	}
}
