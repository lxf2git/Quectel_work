#include<stdio.h>
#define N 5

void  compare(int arr[][N])
{
	int m,i,j;
	int z;
	int b[N];
	int k=0,max;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(k<arr[i][j])	
			{
				m=arr[i][j];
				arr[i][j]=k;
				k=m;
				b[i]=k;
				
			}			
		}		
				max=0;
				max=k;
				printf("max:%d\n",max);
				k=0;
	}
		k=b[0];
		for(i=0;i<N;i++)
		{
				z=k<b[i]?k:b[i];
		}
		printf("输出这几个数中的最小数：%d\n",z);
}

int main()
{
	int a[N][N],t;
	int i,j;
	printf("请输入5*5的方阵：\n");
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		scanf("%d",&a[i][j]);
	compare(&a[0]);
	return 0;

}
