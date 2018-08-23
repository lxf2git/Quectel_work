#include<stdio.h>
#include<stdlib.h>

void creat_memory(void **p,int szie);
void fun(void (*pf)(int,int *),int x,int *p);
void double_(int x,int *p);
void print(int x,int *p);

int main()
{
	int *p=NULL;
	int n;
	printf("please input a n\n");
	scanf("%d",&n);
	creat_memory((void **)&p,n*sizeof(int));
	fun(double_,n,p);
	fun(print,n,p);
	if(p!=NULL)
	{
		free(p);
		p=NULL;
	}
	return 0;
}
void fun(void (*pf)(int,int *),int x,int *p)
{
	pf(x,p);
}

void creat_memory(void **p,int size)
{
	*p=malloc(size);
	if(NULL==*p)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void double_(int x,int *p)
{
	int i;
	for(i=0;i<x;i++)
	{
		scanf("%d",p+i);
		p[i]=2*p[i];
	}
}

void print(int x,int *p)
{
	int i,s=0;
	for(i=0;i<x;i++)
	{
		s=s+p[i];
	}
	printf("%d\n",s);
}
