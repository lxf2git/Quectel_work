#include"../apue.h"

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
	int ret=0;
	pid_t pid = fork();
	if(pid<0)
	{
		show_err("fork");
	}
	if(pid==0)
	{
		printf("child-bf:ret:%d",ret);	
		ret = add(a,b);
		printf("child-%d\n",ret);
		//exit(-1);
	}
	else
	{
		ret = sub(a,b);
		//printf("par-%d\n",ret);
	}
	printf("pid:%d ret:%d\n",getpid(),ret);
}
