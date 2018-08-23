#include<stdio.h> 
int main()
{
	int N,i,j,nu=1;
	printf("请输入N阶方正的行列数。");
	scanf("%d",&N);
	int a[100][100];
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(j>=i)	
				a[j][i]=nu++;	
			else if(i>j)
				a[j][i]=1;
		}
		nu=1;
	}
	for(i=0;i<N;i++)
	{	for(j=0;j<N;j++)
		{
			printf("%2d ",a[i][j]);
		}
	printf("\n");
	}
}

