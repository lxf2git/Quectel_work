#include"../apue.h"
int main()
{
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set,SIGUSR1);
	sigaddset(&set,SIGUSR2);
	sigdelset(&set,SIGUSR2);
	sigfillset(&set);
	printf("%d\n",sigismember(&set,SIGUSR2));
	return 0;

}
