#include<stdio.h>
#include<stdio.h>
#define N 3
int max(int,int);
int min(int,int);
int main()
{
	int a[N][N],i,j,max_[4],min1;
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

	for(i=0;i<N;i++)
	{	
		max_[i]=a[i][0];
		for(j=0;j<N;j++)
		{
			max_[i]=max(max_[i],a[i][j]);
		}
		printf("该行最大的数是%d\n",max_[i]);
	}
	min1=max_[0];
	for(i=0;i<N;i++)
	min1=min(min1,max_[i]);
	printf("最小的数是%d\n",min1);
}

int max(int x,int y)
{
	return (x>y?x:y);
}
int min(int x,int y)
{
	return (x<y?x:y);
}
