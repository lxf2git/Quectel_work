#include<stdio.h>
int max();
int min();
int ex();
int main()
{	int i,x=0,b=0,y=0,sum=0;
	int a[10],i;
	printf("请输入十位转身导师的分数:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
		
	}
	x=max();
	printf("%d\n",x);
	b=min();
	sum=ex();
	y=(sum-x-b)/8;
	printf("平均值是:%d\n",y);	
	
	return 0;
}
int max()
{	
	int i;
	int a[10],i;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
		
	}
	int j;
	for(j=0;j<10;j++)
	{
		a[0]=a[0]>a[i]?a[0]:a[i];
	}

		printf("减去一个最高分:%d\n",a[0]);
		return a[0];
}
int min()
{	
	int i;
	int a[10],i;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
		
	}
	int j;
	for(j=0;j<10;j++)
	{
		a[0]=a[0]<a[i]?a[0]:a[i];
	}

		printf("减去一个最低分:%d\n",a[0]);
		return a[0];
}
int ex()
{	 
	int i,z=0;
	int a[10],i,z=0;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
		
	}
	for(i=0;i<10;i++)
	{
		z+=a[i];
	}
	printf("总分为:%d\n",z);
	return z;
}
