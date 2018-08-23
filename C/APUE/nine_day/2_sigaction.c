#include"../apue.h"

void fun(int sig)
{
		printf("sig:%d\n",sig);
}

int main()
{
	struct sigaction act1,oldact;//	
	
	act1.sa_handler = fun;
	act1.sa_flags = 0;
	sigemptyset(&act1.sa_mask);//不需要屏蔽
	sigaction(SIGALRM,&act1,NULL);	//登记信号处理
	//signal(SIGALRM,fun);
	
		printf("uid:%d pid:%d\n",getuid(),getppid());
		alarm(1);
		pause();
	return 0;

}
