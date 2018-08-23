#include<stdio.h>
int main()
{
		int i,j,N;
		printf("请输入阶数\n");
		scanf("%d",&N);
		int a[N][N];
		int b[N];
		printf("请组建矩阵\n");
		for(i=0;i<N;i++)
		{
				for(j=0;j<N;j++)
				{
						scanf("%d",&a[i][j]);
				}
				printf("\n");
		}

		for(i=0;i<N;i++)
		{
				b[i]=a[i][0];
				for(j=0;j<N;j++)
				{
						printf("%4d",a[i][j]);
						if(b[i]<a[i][j])
						{
								b[i]=a[i][j];
						}
				}
				printf("\n");
		}
		int min=b[0];
		for(i=0;i<N;i++)
		{
				if(min>b[i])
				{
						min=b[i];
				}
		}
		printf("%4d个最大值中的最小值为%4d\n",N,min);
return 0;
}
