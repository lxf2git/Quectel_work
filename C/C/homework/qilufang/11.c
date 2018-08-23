#include<stdio.h>

int main()
{
	int a,b,c;
	printf("请输入三个数字：\n");
	scanf("%d%d%d",&a,&b,&c);	
	printf("大数减小数的差是%d\n",da(a,b,c)-xiao(a,b,c));
	return 0;
}
int da(int a,int b,int c)
{
	if(a>b)
	{
		if(a>c)
		{
			return a;
		}
		else return c; 
	}
    else
	{
		if(b>c)
		{
			return b;
		}
		else return c;
	}
}
int xiao(int a,int b,int c)
{
	if(a<b)
	{
		if(a<c)
		{
			return a;
		}
		else return c;
	}
	else
	{
		if(b<c)
		{
			return b;
		}
		else return c;
	}
}
