#include"../apue.h"

	char buf[20];
void sig_fun(int sig)
{
	printf("%s\n",buf);
}
int main()
{
	printf("%d\n",getpid());	
	signal(SIGALRM,sig_fun);
	scanf("%[]",buf);
	pause();
	return 0;

}
