#include<stdio.h>
#define N 4

void input(int a[N][N]);
void print(int a[N][N]);
void maxmin(int a[N][N]);

int main()
{
		int a[N][N];
		printf("请输入%d阶方阵:\n",N);
		input(a);
		print(a);
		maxmin(a);
		return 0;
}

void maxmin(int a[N][N])
{		
		int i,j;
		int max,min;
		max=a[1][0];
		min=a[0][0];
		for(i=0;i<N;i++)
		{
				for(j=0;j<N;j++)
				{
						if(j>=i)
						{
								if(min>a[i][j])
								{
										min=a[i][j];
								}
						}
						else
						{
								if(max<a[i][j])
								{
										max=a[i][j];
								}
						}
				}
		}
		printf("左下角max:%d\n",max);
		printf("右上角min:%d\n",min);
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
void print(int a[N][N])
{
		int i,j;
		printf("\n\n\n");
		for(i=0;i<N;i++)
		{
				for(j=0;j<N;j++)
				{
						if(a[i][j]<10)
						{
								printf(" %d   ",a[i][j]);
						}
				}
				printf("\n\n\n");
		}
}
