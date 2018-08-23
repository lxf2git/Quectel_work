
#include"../../apue.h"
#include <signal.h>
int main()
{
	printf("%d\n",getpid());
	sigset_t newset,oldset,temp;
	sigemptyset(&newset);
	sigaddset(&newset,SIGINT);
	sigaddset(&newset,SIGTERM);
	sigprocmask(SIG_BLOCK,&newset,&oldset);//设置屏蔽字
	printf("%d %d\n",
					sigismember(&oldset,SIGINT),sigismember(&oldset,SIGTERM));
	

	puts("睡眠中 请勿打扰");
	sleep(10);
	puts("睡醒了");
//	sigpending(&temp);

	//sigprocmask(SIG_SETMASK,&oldset,NULL);//
	//puts("========");
	return 0;

}
