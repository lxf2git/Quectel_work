#include<stdio.h>
int main()
{
	int i,j,n,a[100][100];
	printf("输入几阶方阵：");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i<=j)
			printf("%2d ",a[i][j]=1);
			if(i>j)
			printf("%2d ",a[i][j]=i-j+1);
		}
			printf("\n");
	}




	return 0;
}
