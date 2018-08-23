#include"../apue.h"
sig_t ret;
void sig_fun1(int signo)
{
	printf("i am sig_fun1!\n");
	ret = signal(SIGALRM,ret/*sig_fun2*/);//new ret:sig_fun1
	if(ret==SIG_ERR)
	{
		show_err("signal:sig_fun1");
	}
	printf("ret-sig-fun1:%p\n",ret);
}
void sig_fun2(int signo)
{
	printf("i am sig_fun2!\n");
	ret = signal(SIGALRM,ret/*sig_fun1*/);//new ret:sig_fun2
	if(ret==SIG_ERR)
	{
		show_err("signal:sig_fun2");
	}
	printf("ret-sig-fun2:%p\n",ret);
	
}
int main()
{
	printf("%d\n",getpid());
	ret = signal(SIGALRM,sig_fun1);
	if(ret==SIG_ERR)
	{
		show_err("signal1");
	}
	ret = signal(SIGALRM,sig_fun2);//ret:sig_fun1
	if(ret==SIG_ERR)
	{
		show_err("signal2");
	}
	printf("sigfun1:%p\n",sig_fun1);
	printf("sigfun2:%p\n",sig_fun2);

	for(;;)
	{
		;
	}

}
