#include<stdio.h>

int main()
{
	int i,j,n,a[100][100]={0};
	printf("输入几阶矩阵:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			printf("a[%d][%d]:%d\n",i,j,a[i][j]);
			a[i][0]=a[i][0]>a[i][j]?a[i][0]:a[i][j];
		}
		printf("最大值:%d\n",a[i][0]);
		printf("\n");
	}
	for(i=0;i<n;i++)
	{
		a[0][0]=a[0][0]<=a[i][0]?a[0][0]:a[i][0];
	}
	printf("最小值:a[0][0]:%d\n",a[0][0]);
	return 0;
}

