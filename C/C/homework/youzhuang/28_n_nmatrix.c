#include<stdio.h>

#define N 4

void input(int a[N][N]);
void print(int a[N][N],int max[N]);

int main()
{
		int a[N][N];
		int max[N],min;
		int i,j;
		printf("请输入%d阶方阵:\n",N);
		input(a);

		for(i=0;i<N;i++)
		{
				max[i]=a[i][0];
				for(j=0;j<N;j++)
				{
						if(max[i]<a[i][j])
						{
								max[i]=a[i][j];
						}
				}
		}

		min=max[0];
		for(i=0;i<N;i++)
		{
				if(min>max[i])
				{
						min=max[i];
				}
		}
		print(a,max);
		printf("最小值:%d\n",min);

		return 0;
}

void input(int a[N][N])
{
		int i,j;
		for(i=0;i<N;i++)
		{
				for(j=0;j<N;j++)
				{
						scanf("%d",&a[i][j]);
				}
		}
} 

void print(int a[N][N],int max[N])
{
		int i,j;
		printf("\n");
		for(i=0;i<N;i++)
		{
				for(j=0;j<N;j++)
				{
						printf(" %d ",a[i][j]);
				}
				printf("\n");
		}
		printf("\n");
		for(i=0;i<N;i++)
		{
				printf("第%d行Max:%d\n",i+1,max[i]);
		}
}
