#include<stdio.h>
#include<stdio.h>
#define N 5
int max(int,int);
int min(int,int);
int main()
{
	int a[N][N],i,j,max1,min1;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{	
			scanf("%d",&a[i][j]);
		}
	}


	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{	
			printf("%d ",a[i][j]);
			if(j==N-1)
			printf("\n");
		}
	}
	min1=a[0][0];
	max1=a[1][0];
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{	
			if(j>=i)
			min1=min(min1,a[i][j]);
			else
			max1=max(max1,a[i][j]);
		}
	}
	printf("右上角最小的数是%d\n ",min1);
	printf("左下角最大的数是%d\n ",max1);
}

int max(int x,int y)
{
	return (x>y?x:y);
}
int min(int x,int y)
{
	return (x<y?x:y);
}
