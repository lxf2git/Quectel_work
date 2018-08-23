#include"../apue.h"

void sig_int(int sig)
{
	printf("hahaha\n");
}
void sig_kill(int sig)
{
	printf("heiheihei\n");
}


int main()
{
	printf("%d\n",getpid());
	signal(SIGTERM,sig_kill);
	signal(SIGINT,sig_int);
	sigset_t newset,oldset,temp;
	sigemptyset(&newset);
	sigaddset(&newset,SIGINT);
	sigaddset(&newset,SIGTERM);
	sigprocmask(SIG_BLOCK,&newset,&oldset);//设置屏蔽字
	

	puts("睡眠中 请勿打扰");
	sleep(20);
	puts("睡醒了");

	sigprocmask(SIG_SETMASK,&oldset,NULL);//设置屏蔽字
	return 0;

}
