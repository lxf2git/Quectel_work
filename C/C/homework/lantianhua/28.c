#include<stdio.h>
#define N 4



void input (int arr[][N]);
void output (int arr[][N]);
int main()
{	int i,j,k;
	int arr[N][N]={};
	input(arr);
	output(arr);
	int max,min;
	int b[N];
        for(i=0;i<N;i++)
	{	
		max=arr[i][0];
   		for(j=0;j<N;j++)
		{
			if(arr[i][j]>max)
			max=arr[i][j];
		}
		printf("第%d行的最大的数为：%d\n",i,max);
		b[i]=max;
	}
	min=b[0];
	for(k=0;k<N;k++)
	{
		if(b[k]<min)
		   min=b[k];
	}
	printf("min:%d\n",min);
	return 0;
}
void input (int arr[][N])

{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d",&arr[i][j]);
		}
		printf("\n");
	}
	
}

void output (int arr[][N])
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%4d",arr[i][j]);
		}
		printf("\n");
	}
	
}
