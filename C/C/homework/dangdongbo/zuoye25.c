#include<stdio.h>
#define N 5
int main()
{
		int a[N][N]={},i,j;
		for(i=0;i<N;i++)
		{
		for(j=0;j<N;j++)
		{
			if(i>j)
			a[i][j]=i-j+1;
			else
			a[i][j]=1;
			printf("%d ",a[i][j]);
		}
		printf("\n");
		}
}
