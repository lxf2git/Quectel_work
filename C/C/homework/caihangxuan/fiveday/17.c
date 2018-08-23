#include<stdio.h>
int main()
{
	int a[5],i,j,mouch=0,litter=0;
	printf("请输入五个数");
	for(i=0;i<5;i++)
	scanf("%d",&a[i]);
//	for(i=0;i<5;i++)
//	printf("%d",a[i]);
	int max=a[0],min=a[0];
	for(i=0;i<5;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
			mouch=i;
		}
	}
	for(j=0;j<5;j++)
	{
		if(a[j]<min)
		{
			min=a[j];
			litter=j;
		}
	}
//	printf("max:%d min:%d",max,min);
	a[mouch]=a[4];
	a[litter]=a[0];
	a[4]=max;
	a[0]=min;
	for(i=0;i<5;i++)
	printf("%d ",a[i]);
	printf("\n");
}
