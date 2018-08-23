#include<stdio.h>

int main()
{
	int i,a[5],max,min;
	max=0;
	min=a[0];
	printf("请输入一个元素为5的数组：");
	for(i=0;i<=4;i++)
	{
	scanf("%d",&a[i]);
	if(max<a[i])
	{
	max=a[i];
	}
	else if(0<=min-a[i])
	min=a[i];
	}
	printf("最大的数:a[4]=%d,最小的数：a[0]=%d",max,min);
	return 0;	
}
