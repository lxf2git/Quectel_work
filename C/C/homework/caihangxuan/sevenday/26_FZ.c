#include<stdio.h> 
#define N 5
int main()
{
	int i,j,nu=1,max_l,min_r;
	int a[100][100];
	printf("请输入25个整型，构成5阶方针。\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	min_r=a[0][0];
	max_l=a[1][0];
	for(i=0;i<N;i++)
	{	for(j=0;j<N;j++)
		{
			if(j>=i)
			{
				if(min_r>a[i][j])
					min_r=a[i][j];
			}
			else if(j<i)
			{
				if(max_l<a[i][j])
					max_l=a[i][j];
			}
		}
	}
	for(i=0;i<N;i++)
	{	for(j=0;j<N;j++)
		{
			printf("%2d ",a[i][j]);
		}
	printf("\n");
	}
	printf("min_r:%d max_l:%d\n",min_r,max_l);
}

