#include<stdio.h>
#define X 10
int i,j;
int main()
{
	int a[X];
	printf("请输入%d个评分",X);
	for(i=0;i<X;i++)
	scanf("%d",&a[i]);
	int max,min,sum=0;
	max=find_max(a);
	min=find_min(a);
	printf("最高分为%d 最低分为%d\n",max,min);
	for(i=0;i<X;i++)
	sum=sum+a[i];
	sum=(sum-min-max)/(X-2);
	printf("去掉一个最高分和一个最低分平均分为%d\n",sum);
}

int find_max(int a[X])
{
	int max=a[0];
	for(i=0;i<X;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	return max;
}

int find_min(int a[X])
{
	int min=a[0];
	for(j=0;j<X;j++)
	{
		if(a[j]<min)
			min=a[j];
	}
	return min;
}
