#include"../apue.h"
int main()
{
	pid_t	pid = fork();
	if(pid<0)
	{
		show_err("fork");
	}
	if(pid==0)
	{
		
		printf("child-bef*pid:%d ppid:%d pgrp:%d\n",
						getpid(),getppid(),getpgrp());
		setpgid(getpid(),0);
		printf("child-af*pid:%d ppid:%d pgrp:%d\n",
						getpid(),getppid(),getpgrp());
		sleep(5);
	}
	else
	{
		sleep(1);
	//	wait(NULL);
		printf("main*pid:%d ppid:%d pgrp:%d\n",
						getpid(),getppid(),getpgrp());
		printf("main-par:%d main-child:%d\n",getpgid(getppid()),getpgid(pid));
	}
	return 0;

}
