#include<stdio.h>

int max(int x,int y);
int min(int x,int y);
int jian(int x,int y);

int main()
{
	int a,b,c;
	int Max,Min,s;
	printf("请输入三个数\n");
	scanf("%d%d%d",&a,&b,&c);
	Max=max(a,max(b,c));
	Min=min(a,min(b,c));
	s=jian(Max,Min);
	printf("差是：%d\n",s);
	return 0;
}

int max(int x,int y)
{
	return  (x>y? x:y);
}

int min(int x,int y)
{
	return (x<y? x:y);
}

int jian(int x,int y)
{
	return (x-y);
}
