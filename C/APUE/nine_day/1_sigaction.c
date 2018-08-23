#include"../apue.h"

void func(int sig,siginfo_t *info,void *p)
{
	printf("收到信号，来自用户%d的进程%d，附带的参数为%d\n",
					info->si_uid,info->si_pid,info->si_value.sival_int);
	sleep(10);
}

int main()
{
	struct sigaction act,oldact;//	
	act.sa_sigaction = func;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	//sigaddset(&act.sa_mask,SIGINT);//不需要屏蔽
	sigaction(SIGUSR2,&act,NULL);	//登记信号处理
	if(fork()==0)
	{
		printf("uid:%d pid:%d\n",getuid(),getppid());
		union sigval v;
		v.sival_int = 2015;//设置要传递的参数
		sigqueue(getppid(),SIGUSR2,v);//发送信号和参数
		sleep(1);
	}
	else
	{
		pause();
	}
	return 0;

}
