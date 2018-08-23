#include"../apue.h"

void sig_fun(int sig)
{
	int info;
	pid_t wait_pid;	
	while((wait_pid = waitpid(-1,&info,WNOHANG))>0)
	printf("%d结束，返回%d\n",wait_pid,WEXITSTATUS(info));

}
int main()
{
	int i;	
	system("clear");	
	signal(SIGCHLD,sig_fun);

	for(i=0;i<10;i++)//产生10个子进程
	{
		if(fork()==0)//child
		{
			int j;
			char c='A'+i;
			for(j=0;j<20;j++)
			{
				write(2,&c,1);
				sleep(1);
			}
			exit(c);
		}
	}
	//par
	for(;;)
	{
		sleep(100);
	}
}
