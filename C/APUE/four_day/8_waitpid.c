#include"../apue.h"
int main()
{
	printf("%d\n",getpid());	
	int i;
	char *s = "abcd";
	for(i=0;i<3;i++)
	{
	
		if(fork()==0)
		{
			printf("child-pid:%d par-pid:%d\n",
							getpid(),getppid());	

				
			int j;
			for(j=0;j<15;j++)
			{
				write(1,s+i,1);
				sleep(50);
			}
			exit(0);
		}
		//printf("i:%d pid:%d\n",i,getpid());
	}
		pid_t child = waitpid(-1,NULL,WNOHANG);
		printf("%d结束\n",child);
	
}



