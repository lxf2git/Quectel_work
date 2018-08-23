#include<stdio.h>
#define N 10

void output(int arr[][N]);
int main()
{
	int a[N][N]={};
	output(a);
	return 0;
}

void output(int arr[][N])
{
	int i , j ;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if((i-j)<=0)
			{
				arr[i][j]=1;
				printf("%4d",arr[i][j]);
			}
			else
			{
				arr[i][j]=i-j+1;
				printf("%4d",arr[i][j]);
			}
		}
		printf("\n");
	}
}

