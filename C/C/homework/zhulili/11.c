#include<stdio.h>

int max(int x,int y);
int min(int x,int y);

int main()
{
	int a,b,c,d,e;
	scanf("%d,%d,%d",&a,&b,&c);
	d=max(a,b);
	e=max(d,c);
	b=min(a,b);
	b=min(b,c);
	printf("最大值为：%d\n",e);
	printf("最小值为：%d\n",b);
	printf("差值：%d\n",e-b);
	return 0;
}
int max(int x,int y)
{
	int z;
	if(x>y)
	{
		z=x;
	}
	else
		z=y;
	return z;
}
int min(int x,int y)
{
	int s;
	if(x>y)
		s=y;
	else
	    s=x;
	return s;
}
