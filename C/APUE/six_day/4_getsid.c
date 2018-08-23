#include"../apue.h"
int main()
{
	pid_t pid;

	printf("par-pid:%d ppid:%d pgrp:%d sid:%d\n",
					getpid(),getppid(),getpgrp(),getsid(getpid()));
#if 1
	pid = fork();
	if(pid<0)
	{
		show_err("fork");
	}
	if(pid==0)
	{
		setsid();	
		printf("child-pid:%d ppid:%d pgrp:%d sid:%d\n",
					getpid(),getppid(),getpgrp(),getsid(getpid()));
	
	}
#endif
}
