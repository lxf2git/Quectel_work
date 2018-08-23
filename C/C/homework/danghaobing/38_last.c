#include<stdio.h> 
int fun(int *a,int *b);
int main() 
{
		int a,b;
		printf("请输入一个整数并输入他的任意！\n");
		scanf("%d%d",&a,&b);
		int ret=fun(&a,&b);
		printf("%d\n",ret);
		fun1(ret);
		return 0;
}

int fun(int *a,int *b)
{
		if(*b>0)
		{
				(*b)--;
				return *a*fun(a,b);
		}
		else 
				return 1;
}

int fun1(int a)
{
		printf("%d",a%1000);
}
