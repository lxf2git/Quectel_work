#include<stdio.h>
int MAX();
int MIN();
//#define N 5
int main()
{
	int a[5],i;
	printf("请输入5个数\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	MAX(a);
	MIN(a);
	printf("啦啦啦阿拉了%d\n",a[0]);
	for(i=0;i<5;i++)
	{
		printf("%d  ",a[i]);
	}
	return 0;
}
int MAX(int a[])
{
	int i,t;
	for(i=0;i<5;i++)
	{
		if(a[4]<a[i])
		{
				t=a[4];
				a[4]=a[i];
				a[i]=t;
		}
	}
	
	printf("max=%d\n",a[5]);
}
int MIN(int a[])
{
	int i,t;
	for(i=0;i<5;i++)
	{
		if(a[0]>a[i])
		{
				t=a[0];
				a[0]=a[i];	
				a[i]=t;			
		}
	}
	printf("min=%d\n",a[0]);
}
