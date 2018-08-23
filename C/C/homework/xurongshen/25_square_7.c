#include<stdio.h>
#define N 20
#define R 4
#define C 4

	output(int n)
	{
		int a[N][N]={0};
		int i, j,t;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				a[i][j] = 1;
				if(i <= j)
				{
					a[i][j] = 1;
					printf("%5d",a[i][j]);
				}
				else
				{
					a[i][j] = i+1-j;
					printf("%5d",a[i][j]);
				}
			}
			printf("\n");
		}
	}

int main()
{
	int arr[R][C];
	printf("请输入矩阵的介数：");
	int n;
	scanf("%d",&n);
	output(n);
	return 0;

}
