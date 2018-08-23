#include<stdio.h>
#define N 5

void input(int arr[][N]);
void output(int arr[][N]);

int main()
{
	int a[N][N]={};
	input(a);
	output(a);
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
	int right[N*N]={};
	int left[N*N]={};
	int i, j, n, m;
	int min, max;
	n=0;
	m=0;
	printf("矩阵\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if((i-j)<=0)
			{
				right[n]=arr[i][j];
				n++;
			}
			else
			{
				left[m]=arr[i][j];
				m++;
			}
			printf("%4d",arr[i][j]);
		}
		printf("\n");
	}
	min=right[0];
	for(i=0;i<n;i++)
	{
		if(min>=right[i])
		{
			min=right[i];
		}
	}
	printf("min:%d\n",min);
	max=left[0];
	for(i=0;i<n;i++)
	{
		if(max<=left[i])
		{
			max=left[i];
		}
	}
	printf("max:%d\n",max);

}









