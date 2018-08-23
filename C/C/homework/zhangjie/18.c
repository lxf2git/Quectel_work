#include<stdio.h>
int max(int a[]);
int min(int a[]);

int main()
{
	int i,sum=0,x,y;
	int a[10];
	for(i=0;i<10;i++)
	scanf("%d",&a[i]);
	x=max(a);
	y=min(a);
	for(i=0;i<10;i++)
	{
		sum+=a[i];
	}
	printf("average:%d\n",(sum-x-y)/8);
	return 0;
}

int max(int a[])
{
	int i,m;
	m=a[0];
	for(i=0;i<10;i++)
	{
		if(m<a[i])
		m=a[i];
	}
	return m;
}

int min(int a[])
{
	int i,m;
	m=a[0];
	for(i=0;i<10;i++)
	{
		if(m>a[i])
		m=a[i];
	}
	return m;
}
