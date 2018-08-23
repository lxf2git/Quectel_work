#include<stdio.h>
#define N 5
int main()
{
	int a[N][N];
	int i,j,min=999999,max=0;
	printf("输入数字:\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d",&a[i][j]);
			printf(" %2d",a[i][j]);
			if(i<=j)
			{
				if(a[i][j]<min)
						min=a[i][j];
			}
			if(i>j)
			{
				if(a[i][j]>max)
					max=a[i][j];
			}
		}
		printf("\n");
	}
	printf("右上角最小数:%d\n左下角最大数:%d\n",min,max);
	return 0;
}
