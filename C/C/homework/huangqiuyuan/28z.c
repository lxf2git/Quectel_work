#include<stdio.h>
int main()
{
	int a[100][100],b[100],i,j,N,max=0,min;
	printf("N为：");
	scanf("%d",&N);
	printf ("输入矩阵元素：\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d",&a[i][j]);
		}
		for(j=0;j<N;j++)
		{	if(max<a[i][j])
		      max=a[i][j];
		}
		b[i]=max;
	}
		for(i=0;i<N;i++)
		printf("%d行最大值为：%d\n",i,b[i]);

	for(i=0;i<N;i++)	
	{ for(j=0;j<N;j++)	
		printf("%d ",a[i][j]);
		printf("\n");}


		min=b[0];
	for(i=0;i<N;i++)
	{	if(b[i]<=min)
			min=b[i];
	}
		printf("%d行最大值中最小的值为：%d\n",N,min);

	return 0;
}
