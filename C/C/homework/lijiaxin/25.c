#include<stdio.h>
#define N 10

int main()
{
		int arr[N][N];
		int i,j;
		printf("请输入一个%d阶矩阵:\n",N);
		for(i=0;i<N;i++)
				for(j=0;j<N;j++)
				{
						if(i<=j)
								arr[i][j]=1;
						else
								arr[i][j]=i-j+1;
				}
		for(i=0;i<N;i++)
		{
				for(j=0;j<N;j++)
				{
						printf("%2d ",arr[i][j]);
				}
				printf("\n");
		}

}
