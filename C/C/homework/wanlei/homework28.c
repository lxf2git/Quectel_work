#include<stdio.h>

#define N 100

void input(int y,int a[][N]);
int max(int x,int y,int a[][N]);
int max1(int y,int a[]);

int main()
{
	int i,n,Max;
	int a[N][N];
	int b[N];
	printf("请输入一个n级数组\n");
	scanf("%d",&n);
	input(n,a);
	for(i=0;i<n;i++)
	{
		b[i]=max(i,n,a);
		printf("%d ",b[i]);
	}
	printf("\n");
	Max=max1(n,b);
	printf("每行最大值中最小的为：%d\n",Max);
	return 0;
}

void input(int y,int a[][N])
{
	int i,j;
	for(i=0;i<y;i++)
	{
		for(j=0;j<y;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
}

int max(int x,int y,int a[x][N])
{
	int i,j;
	int Max;
	//for(i=0;i<N;i++)
	//{
		Max=a[x][0];
		for(j=0;j<y;j++)
		{
			if(Max<a[x][j])
				Max=a[x][j];
		}
		//printf("%d\n",Max);
		return Max;
	//}
}

int max1(int y,int a[])
{
	int i;
	int Max=a[0];
	for(i=0;i<y;i++)
	{
		if(Max>a[i])
			Max=a[i];
	}
	return Max;
}
