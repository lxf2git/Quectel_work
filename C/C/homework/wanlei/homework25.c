#include<stdio.h>

#define N 100

int main()
{
	int i,j;
	int n;
	int a[N][N]={};
	printf("请输入一个n级方阵\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j>=i)
			{
				a[i][j]=1;
			}
			else
			{
				a[i][j]=i-j+1;
			}
			printf("%2d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
