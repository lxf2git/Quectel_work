#include<stdio.h>
#define N 4
void input(int arr[][N])
{
	int i,j;
	
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
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%2d  ",arr[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int arr[N][N];
	int max,min,i,j;
	max=0;min=100000;
	printf("请输入5阶方阵\n");
	input(arr);
	output(arr);
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(j-i>=0)
			{
				if(arr[i][j]<min)
						min=arr[i][j];
			}	
			else
			{
				if(arr[i][j]>max)
						max=arr[i][j];
			}
		}
	
	}
	printf("右上最小数：%d\n",min);
	printf("左上最大数：%d\n",max);

	return 0;
}
