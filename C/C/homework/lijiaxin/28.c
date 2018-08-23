#include<stdio.h>
#define N 3
void max(int a1[][N]);
void min(int a2[N][N]);
void input(int arr[N][N])
{
		int i,j;
		for(i=0;i<N;i++)
		{
				for(j=0;j<N;j++)
				{
						scanf("%d",&arr[i][j]);
				}
		}			
			
}
int main()
{
		int a[N][N];
		input(a);
		max(a);
		min(a);

}
void max(int a1[][N])
{
		int i,j;
		for(i=0;i<N;i++)
		{
				for(j=0;j<N;j++)
				{
						if(a1[i][0] < a1[i][j])
								
								a1[i][0]=a1[i][j];
				}
		}
}
void min(int a2[N][N])
{
		int i,j;
		for(i=0,j=0;i<N;i++)
		{
				if(a2[0][0]>a2[i][j])
				{
						a2[0][0]=a2[i][0];
				}
		}
		printf("各行最大值中最小值为%d:\n",a2[0][0]);
}
