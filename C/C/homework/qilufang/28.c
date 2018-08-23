#include<stdio.h>
#define N 3
void max(int a1[][N]);

int main()
{
	int i,j,input[N][N]={0};
	printf("创建%d阶矩阵：\n",N);
	for(i = 0;i<N;i++)
	{		
		for(j = 0;j<N;j++)
		{
			scanf("%d",&input[i][j]);
		}
	}
	max(input);
	return 0;
}
void max(int a1[][N])
{
	int i,j,a2[N]={0},k,c,b=0;
	for(i = 0;i<N;i++)
	{		
		for(j = 0;j<N;j++)
		{
			if(a1[i][j]>b)
			b=a1[i][j];
		}
		a2[i]=b;
	printf("第%d行最大的数：%d\n",i+1,b);
		b=0;
	}
	c=a2[0];
	for(k=0;k<N;k++)
	{
		if(c>a2[k])
		c=a2[k];
	}
	printf("输出每行最大中的最小数：\n");
	printf("%d\n",c);      
}
