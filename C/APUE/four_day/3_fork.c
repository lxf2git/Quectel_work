#include"../apue.h"

int glob;
int add(int a,int b)
{
	return a+b;
}

int sub(int a,int b)
{
	return a-b;
}
int main()
{
	int a=50,b=10;	
	int ret;
	pid_t pid = fork();
	if(pid<0)
	{
		show_err("fork");
	}
	if(pid==0)
	{
		glob = add(a,b);
		printf("child-glob:%d\n",glob);
		//exit(-1);
	}
	else
	{
		sleep(1);	
		ret = sub(a,glob);//glob=0
	}

	printf("pid:%d ret:%d\n",getpid(),ret);
}
