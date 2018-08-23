#include"../apue.h"
sig_t ret;
void sig_fun1(int signo)
{
	printf("i am sig_fun1!\n");
}
void sig_fun2(int signo)
{
	printf("i am sig_fun2!\n");
	
}
int main()
{
	printf("%d\n",getpid());
	ret = signal(SIGALRM,sig_fun1);
	if(ret==SIG_ERR)
	{
		show_err("signal1");
	}
	printf("ret:%p\n",ret);
	ret = signal(SIGALRM,sig_fun2);
	//if(ret==SIG_ERR)
	//{
		printf("err:%d\n",SIG_ERR);	
	//	show_err("signal2");
	//}

	for(;;)
	{
		;
	}

}
