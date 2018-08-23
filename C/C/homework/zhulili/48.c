#include<stdio.h>
#include<stdlib.h>
#define N 10

int print(int x)
{
	return x;
}

int mydouble(int x)
{
	return 2*x;
}

void  fun(int (*q)(int),int x)
{
	int ret = (*q)(x);
		printf("%d  ",ret);
}

int main()
{
	int x,result;
	int  m;
	int i;
	int a[N];
	printf("请输入数字：\n");
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
	printf("请选择：\n");
	printf("0------输出原来的数\n");
	printf("1------输出原来数的二倍\n");
	printf("其他------退出\n");
	scanf("%d",&m);
	int (*p)(int);
	if(m==0)
	{
		for(i=0;i<N;i++)
		{	
			 fun(print,a[i]);

		}
	}
	if(m==1)
	{
		for(i=0;i<N;i++)
		{
			 fun(mydouble,a[i]);
		}
	}
	return 0;
}

