
#include"../apue.h"
int main()
{
	int sta;	
	pid_t wait_pid;
	pid_t pid = fork();
	if(pid<0)
	{
		perror("fork");
		exit(-1);
	}
	if(pid==0)
	{
		printf("child:%d ppid:%d\n",getpid(),getppid());
		exit(20);//0 -1 3  
	}
	else
	{
		printf("i am father\n");
		 wait_pid = wait(&sta);
		 printf("wait_pid:%d stat:%d %d %d\n",wait_pid,
						 WIFEXITED(sta),WEXITSTATUS(sta),WIFSIGNALED(sta));
			
	
	}
}
