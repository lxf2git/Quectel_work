#include"../apue.h"

void sig_fun(int sig)
{
	puts("ding-ling-ling");
}
int main()
{
	signal(SIGALRM,sig_fun);	
	
	unsigned int ret = alarm(10);
	printf("ret10:%d\n",ret);
#if 0	
	sleep(1);
	unsigned int ret1 = alarm(3);
	printf("ret3:%d\n",ret1);

	unsigned int ret3 = alarm(1);
	printf("ret1:%d\n",ret3);
#endif
	for(;;)
	{
			;
	}
	return 0;

}
