#include"../apue.h"
int main()
{
		pid_t  pid = fork();	
	if(pid<0)
	{
		show_err("fork");
	}
	if(pid==0)
	{
		printf("pid:%d ppid:%d pgrp:%d pgid:%d \n",
						getpid(),getppid(),getpgrp(),getpgid(0));
	
	}
	else
	{
		printf("pid:%d ppid:%d pgrp:%d pgid:%d \n",
						getpid(),getppid(),getpgrp(),getpgid(pid));
	
	}

	return 0;

}
