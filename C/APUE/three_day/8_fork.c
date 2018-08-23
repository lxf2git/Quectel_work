#include"../apue.h"
int main()
{
	pid_t pid;	
	pid = fork();	
	if(pid<0)
	{
		perror("fork");
	}
	if(pid==0)
	{
		printf("child-getpid:%d parent:%d\n",getpid(),getppid());
	}
	else
	{
		printf("child:%d",pid);
		printf("par-getpid:%d parent:%d\n",getpid(),getppid());
	}
	puts("hello");
	return 0;

}
