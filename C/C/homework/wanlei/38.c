#include<stdio.h>

#define N 3

int power(int x,int *p);
void *math(int *p);

int main()
{
	int x,n,i;
	int *p=&x;
	printf("请输入一个数和它的几次方\n");
	scanf("%d%d",p,&n);
	int m=power(n,p);
	printf("%d\n",m);
	p=&m;
	math(p);
	return 0;
}

int power(int x,int *p)
{
	int i;
	int s=1;
	for(i=0;i<x;i++)
	{
		s=s*(*p);
	}
	return s;
}

void *math(int *p)
{
	int i;
	int a[N]={};
	int *point=a;
	for(i=0;i<N;i++)
	{
		*(point+i)=*p%10;
		*p=*p/10;
	}
	for(i=N-1;i>=0;i--)
	{
		printf("%d",*(point+i));
	}
	printf("\n");
}
