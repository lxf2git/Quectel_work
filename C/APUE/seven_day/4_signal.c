#include"../apue.h"

void sig_fun(int sig)
{
	printf("sig:%d\n",sig);
}
int main()
{
	printf("%d\n",getpid());	
	signal(SIGALRM,sig_fun);//SIG_IGN SIG_DFL
	pause();
	printf("haha\n");	
	return 0;

}
