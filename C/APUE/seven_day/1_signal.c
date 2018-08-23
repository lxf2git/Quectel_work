#include"../apue.h"
void func(int sig)
{
	switch(sig)
	{
		case SIGINT:
				printf("我不怕ctrl+c\n");
				break;
		case SIGTERM:
				printf("想杀我 没门\n");
				break;
		case SIGTSTP:
				printf("我是不会停滴\n");
				break;
		default:
				puts("default");
	}
}

int main()
{
	signal(SIGINT,func);//登记ctrl+c 信号的处理	
	signal(SIGTERM,func);//登记kill 信号的处理	
	signal(SIGTSTP,func);//登记ctrl+z 信号的处理	

	printf("%d\n",getpid());

	for(;;)
	{
		write(2,".",1);
		sleep(10);
	}
	return 0;

}
