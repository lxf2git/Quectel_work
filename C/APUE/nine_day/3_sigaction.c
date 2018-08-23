#include"../apue.h"

void func(int sig,siginfo_t *info,void *p)
{
	printf("收到信号，来自用户%d的进程%d，附带的参数为%d\n",
					info->si_uid,info->si_pid,info->si_value.sival_int);
	sleep(10);
}

int main()
{
	printf("%d\n",getpid());
	struct sigaction act,oldact;//	
	act.sa_sigaction = func;
	act.sa_flags = SA_SIGINFO;//屏蔽自身信号(SIGINT)  |SA_NODEFER
	sigemptyset(&act.sa_mask);
	sigaction(SIGINT,&act,NULL);	//登记信号处理

		union sigval v;
		v.sival_int = 2015;//设置要传递的参数
		sigqueue(getpid(),SIGINT,v);//发送信号和参数
		pause();
	return 0;

}
