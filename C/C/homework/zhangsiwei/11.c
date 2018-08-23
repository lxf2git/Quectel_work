#include<stdio.h>
int max(int a,int b,int c);
int min(int a,int b,int c);
int main()
{
	int a,b,c,MAX,MIN;
	printf("请输入a b c：\n");
	scanf("%d%d%d",&a,&b,&c);
	MAX=max(a,b,c);
	MIN=min(a,b,c);
	printf("MAX=%d\n",MAX);
	printf("MIN=%d\n",MIN);
	printf("MAX-MIN=%d\n",MAX-MIN);

	return 0;
}

int max(int a,int b,int c)
{
	if(a>b)
	{
		if(b>c)
				return a;
		else if(a<c)
				return c;
		else
				return a;
	}
	else 
	{
		if(c>b)
				return c;
		else 
				return b;
	}
}
int min(int a,int b,int c)
{
	if(a<b)
	{
		if(a<c)
				return a;
		else 
				return c;
	}
	else
	{
		if(c<b)
				return c;
		else
				return b;
	}
}
