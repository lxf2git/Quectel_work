#include<stdio.h>

int min(int ,int ,int );
int max(int ,int ,int );
int main()
		
{
	int a,b,c,MAX,MIN,CHA;
	printf("请输入三个整数:");
	scanf("%d%d%d",&a,&b,&c);
	MAX = max(a,b,c);
	MIN = min(a,b,c);
	CHA = MAX - MIN;
	printf("MAX: %d MIN: %d CHA: %d\n",MAX,MIN,CHA);
	return 0;
}
int max(int a,int b,int c)
{ 
	int d;
	if(a<b)
	{
		d=a;
		a=b;
		b=d;
	}
	if(a<c)
	{
		d=a;
		a=c;
		c=d;
	}
	return a;
}
int min(int a,int b,int c)
{ 
	int d;
	if(a>b)
	{
		d=a;
		a=b;
		b=d;
	}
	if(a>c)
	{
		d=a;
		a=c;
		c=d;
	}
	return a;
}

