#include<stdio.h>

int main()
{
	int a[50][50],i,j,min,max;
	printf("请输入一个5阶方阵：");
	for(i=0;i<5;i++)
	{
	for(j=0;j<5;j++)
	{
		scanf("%d",&a[i][j]);
		if(i<=j)
		{
			if(a[0][0]<=a[i][j])
			min=a[0][0];
			else min=a[i][j];
		}
		else
		{
			if(a[0][0]<=a[i][j])
			max=a[i][j];
			else max=a[0][0];
		}
	}
	}
	printf("最小值为:%d\n",min);
	printf("最大值为:%d\n",max);
	return 0; 
}
