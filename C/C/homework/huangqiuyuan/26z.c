#include<stdio.h>
int main()
{
	int a[5][5],i,j,min,max;
	printf("输入五阶方阵数列：\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			scanf("%d",&a[i][j]);
			printf("%2d ",a[i][j]);
		}
		printf("\n");
	}

	min=a[0][0];
	max=0;
	for(i=0;i<5;i++)	
	{	
		for(j=0;j<5;j++)
		{
			if(i<=j)
			{
			if(a[i][j]<=min)
			min=a[i][j];
			}
			if(i>j)
			{
			if(a[i][j]>=max)
			max=a[i][j];
			}
		}	

	}
		printf("右上最小值：%d\n",min);
		printf("左下最大值：%d\n",max);
	return 0;
}
