#include"../apue.h"
int main()
{
	pid_t pid;
	int a=5;	
	pid = fork();	
	if(pid<0)
	{
		perror("fork");
	}
	if(pid==0)
	{
			printf("child:%p\n",&a);
		
	}
	else
	{
			printf("par:%p\n",&a);
			a++;
		//exit(-1);
	}

}




