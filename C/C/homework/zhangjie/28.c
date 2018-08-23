#include<stdio.h>

#define N 5

void min(int b[N]);

void squr(int arr[][N])
{
	int i,j;
	printf("输入方阵a[N][N]\n");
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			scanf("%d",&arr[i][j]);
		}
}

void max(int a[][N])
{
	int k,i,j;
	int b[N];
	for(i=0;i<N;i++)
	{	
		k=a[i][0];	
		for(j=0;j<N;j++)
		{
			if(k<a[i][j])
			k=a[i][j];
		}
		b[i]=k;
	}
	min(b);
}

void min(int b[N])
{
	int i,j;
	j=b[0];
	for(i=0;i<N;i++)
	{
		if(j>b[i])
		j=b[i];
	}
	printf("%d",j);
}

int main()
{
	int a[N][N];
	squr(a);
	max(a);
	return 0;
}
