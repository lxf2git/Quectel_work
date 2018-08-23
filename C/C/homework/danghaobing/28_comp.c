#include<stdio.h>
#define N 3
int main()
{
		int a[N][N]={};
		int i,j;
		for(i=0;i<N;i++)
		{
				for(j=0;j<N;j++)
				{
						scanf("%d",&a[i][j]);
						printf("%2d ",a[i][j]);
						a[i][0]=a[i][0]>=a[i][j]?a[i][0]:a[i][j];
				}
				printf("\n");
				printf("第%d行最大值：%d\n",i+1,a[i][0]);
		}	
		for(i=0;i<N;i++)
		{
					a[0][0]=a[0][0]<=a[i][0]?a[0][0]:a[i][0];
		}
		printf("最大值中的最小值:%d\n",a[0][0]);
}
