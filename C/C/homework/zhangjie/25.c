#include<stdio.h>
//#define R 2


int main()
{
	int i,j,R;
	int a[100][100]={'0'};
	printf("输入几阶方阵\n");
	scanf("%d",&R);
	for(i=0;i<R;i++)
	{	
		for(j=0;j<R;j++)
		{
			if(i==j||i<j)
			a[i][j]=1;
			else if(i>j)
			a[i][j]=i-j+1;
		}
	}
	for(i=0;i<R;i++)
	{	
		for(j=0;j<R;j++)
		{
			printf("%d ",a[i][j]);
		}
			printf("\n");
	}
	return 0;
}
