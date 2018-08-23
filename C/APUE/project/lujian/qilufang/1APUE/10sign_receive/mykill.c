#include<stdio.h>
#include <signal.h>
#include <stdlib.h>
#include<string.h>

#define FAIL -1
int ten_power(int nb)
{
	int ret=1;
	int i;
	for(i=0;i<nb;i++)
	{
		ret*=10;
	}
	return ret;
}
int change(char *arr)
{
	int ret=0;
	int nb=strlen(arr);
	int i=0;
	while(i<nb)
	{
		int ten=0;
		ten=ten_power(nb-i-1);
		ret+=(arr[i]-48)*ten;
		i++;
	}
	return ret;
}
void mykill(char **order)
{
	int ret;
	if(strcmp(order[0],"mykill"))
	{
		printf("Input_error\n");
		exit(-1);
	}
	pid_t pid=change(order[2]);
	int sig=change(order[1]+1);
//	printf("pid:%d sig:%d\n",pid,sig);
	if(kill(pid,sig)<0)
	{
		perror("mykill");
		exit(-1);
	}
}
int main(int argc,char **argv)
{
	if(argc!=3)
	{
		printf("Input error!\n");
		return FAIL;
	}
	mykill(argv);
		return 0;

}
