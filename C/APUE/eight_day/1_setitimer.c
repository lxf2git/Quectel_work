#include"../apue.h"

void timeout(int signo)
{
	puts("时间到了 小朋友");
}
int main()
{
	signal(SIGALRM,timeout);

	struct itimerval iv;
	iv.it_interval.tv_sec = 10;
	iv.it_interval.tv_usec = 0;
	
	iv.it_value.tv_sec = 5;
	iv.it_value.tv_usec = 0;

	setitimer(ITIMER_REAL,&iv,NULL);
	for(;;)
	{
		write(1,".",1);
		sleep(1);
	}
	return 0;

}
