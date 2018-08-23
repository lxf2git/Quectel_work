#include<stdio.h>
int main()
{
	int i,sum=0,a[10];
	int max=0,min,j,k;
	printf("请输入各评委所给分数：");
	scanf("%d",&a[0]);
	min=a[0];
	max=a[0];
	for(i=1;i<10;i++)
	{
	scanf("%d",&a[i]);
		if(max<a[i])
		{
			max=a[i];
		}
	}
	for(i=0;i<10;i++)
	{
		if(min>a[i])
		{
			min=a[i];
		}
	}
	for(i=0;i<10;i++)
	{
		sum+=a[i];
	}
	sum=sum-max;
	sum=sum-min;
	printf("去掉一个最高分和一个最低分后：%d\n",sum);
}
