#include"../apue.h"
int main()
{
	//printf("%d\n",getpid());	
	int i;
	char *s = "abcd";
	for(i=0;i<3;i++)
	{
	
		if(fork()==0)
		{
		//	printf("child-pid:%d par-pid:%d\n",
//							getpid(),getppid());	

				
			int j;
			for(j=0;j<15;j++)
			{
				write(1,s+i,1);
				write(1,"o",1);
				//printf("*child:%d\n",getpid());
				sleep(1);
			}
			exit(0);
		}
		printf("p----:%d\n",getpid());
	}
#if 0
	for(;;)
	{
		pid_t child = wait(NULL);
		if(child==-1)
		{
			break;
		}
		printf("%d结束\n",child);
	}
#endif
}



