#include<stdio.h> 
int main()
{
	int N,i,j,max,min;
	printf("请输入N阶方正的行列数。");
	scanf("%d",&N);
	int a[500][500],b[500];
	printf("请输入构成%d阶方阵的%d个整型",N,N*N);
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
		  scanf("%d",&a[i][j]); //输入数组元素	
		}
	}
	max=a[0][0];
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(max<a[i][j])
			  max=a[i][j];	//找出数组里每行的最大值
		}
		printf("第%d行的最大数为%d\n",i,max);
		b[i]=max; //最大值存入b数组
	}
	min=b[0];
	for(i=0;i<N;i++)
	{
		if(min>b[i])
			min=b[i];
	}
	printf("各行最小为%d",min);
}
