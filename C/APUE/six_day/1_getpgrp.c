#include"../apue.h"
int main()
{
#if 1
		pid_t  pid = fork();	
	if(pid<0)
	{
		show_err("fork");
	}
#endif
		printf("pid:%d ppid:%d pgrp:%d pgid:%d \n",
						getpid(),getppid(),getpgrp(),getpgid(0));

	return 0;

}
