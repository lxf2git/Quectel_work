#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int n=8;	
	int *p=(int *)malloc(n*sizeof(int));
	char *q=malloc(20*sizeof(char));
	//if 	
	printf("size:%d\n",n*sizeof(int));
	//memset(p,0,sizeof(p));	
	
	bzero(p,n*sizeof(int));	
	return 0;

}
