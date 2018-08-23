#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n;

int print(int m)
{
	printf("%d的双倍是：%d\n",m/2,m);
	return 0;
}

int double1(int n)
{
	int a;
	a = n*2;
	return 	a;
}

int  fun(int (*p)(int),int n)
{	
		return	(*p)(n);
}

int main()
{
	int c,b;
	int i;
	printf("please input number of data:");
	scanf("%d",&n);
//	for(i=0;i<n;i++)
//	{
	for(i=0;i<n;i++)
	{
		printf("please input  data%d:",i);
		scanf("%d",&c);
		
		b = fun(double1,c);
		fun(print,b);
	}
//	}
//	for(i=0;i<n;i++)
//	{
	//	fun(print,c);
//	}
	return 0;
}
