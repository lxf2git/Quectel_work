#include<stdio.h>

void input(int arr[][100],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
		
	}
}

void output(int arr[][100],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%2d  ",arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void max(int arr[][100],int n)
{
		int i,j,max,k;
		k=10000;max=0;
		for(i=0;i<n;i++)
		{
				for(j=0;j<n;j++)
				{
					if(arr[i][j]>max)
							max=arr[i][j];
				}
				printf("第%d行的最大数：%d\n",i,max);
				if(max<k)
						k=max;
				max=0;	
		}	
		printf("各行最大数中的最小数：%d\n",k);
}
int main()
{
	int n,arr[100][100];
	printf("请输入N阶方阵:\n");
	scanf("%d",&n);
	printf("请输入方阵元素：\n");
	input(arr,n);
	output(arr,n);
	max(arr,n);
	


	return 0;
}
