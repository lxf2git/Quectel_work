#include<stdio.h>
#define N 5


int main()
{
	int i,j,k,p;
	int a[N][N]={'0'};
	printf("请输入5阶方阵\n");
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			scanf("%d",&a[i][j]);
		}
			k=a[0][0];
			p=a[1][0];
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			if(i<=j)
			{
				if(k>a[i][j])
				k=a[i][j];
			}
			else if(i>j)
			{
				if(p<a[i][j])
				p=a[i][j];
			}
		}
	printf("右上最小为%d左下最大为%d\n",k,p);
	return 0;
}
