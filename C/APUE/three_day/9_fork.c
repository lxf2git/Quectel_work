#include"../apue.h"
int main()
{
	pid_t pid;
	int i=0;	
	pid = fork();	
	if(pid<0)
	{
		perror("fork");
	}
	if(pid==0)
	{
		for(i=0;i<5;i++)
		{	
			printf("child-getpid:%d\n",getpid());
			sleep(1);
		}
	}
	else
	{
		for(i=0;i<3;i++)
		{
			printf("par-getpid:%d\n",getpid());
			sleep(1);
			
		}	
		//exit(-1);
	}

}
