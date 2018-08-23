#include<stdio.h>
#define N 3
void output(int arr[][N]);
void input(int arr[][N]);
void calculate(int arr[][N]);
int main()
{
	int a[N][N]={};
	input(a);
	output(a);
	calculate(a);
	return 0;
}

void input(int arr[][N])
{
	int i, j;
	printf("输入数据:\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
}

void output(int arr[][N])
{
	printf("矩阵\n");
	int i, j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%4d",arr[i][j]);
		}
		printf("\n");
	}
}

void calculate(int arr[][N])
{
	int i, j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(arr[i][j]>=arr[i][0])
			{
				arr[i][0]=arr[i][j];
			}
		}
		printf("第%d行,最大值为%d\n",i+1,arr[i][0]);
		if(arr[i][0]<=arr[0][0])
		{
			arr[0][0]=arr[i][0];
		}
	}
	printf("最大数中的最小数:%d\n",arr[0][0]);
}
