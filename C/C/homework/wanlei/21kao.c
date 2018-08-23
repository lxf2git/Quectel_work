#include<stdio.h>

#define N 50

void change(int x,int a[]);
void change_1(int x,int a[]);

int main()
{
	int a[N];
	int x;
	printf("请输入一个x的值\n");
	scanf("%d",&x);
	change(x,a);
	return 0;
}

void change(int x,int a[])
{
	int i,n;
	n=0;
	for(i=0;;i++)
	{
		a[i]=x%2;
		n++;
		if(x/2==0)
		{
			break;
		}
		else
		{
			x/=2;
		}
	}
	change_1(n,a);
}

void change_1(int x,int a[])
{
	int i,t;
	for(i=0;i<x/2;i++)
	{
		t=a[i];
		a[i]=a[x-1-i];
		a[x-1-i]=t;
	}
	for(i=0;i<x;i++)
	{
		printf("%d",a[i]);
	}
	printf("\n");
}
