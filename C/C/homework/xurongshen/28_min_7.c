#include<stdio.h>
#define N 20
#define R 4
#define C 4
extern int n;

	compare(int arr[N][N],int bn[N])
	{
		int i, j,t;
		for(i=0;i<n;i++)
		{
			bn[i]=arr[i][0];
			for(j=0;j<n;j++)
			{
				if(arr[i][j] >= bn[i])
				{
					bn[i] = arr[i][j];
				//	printf("--->%d\n",bn[i]);
				}
			}
		}
	}
	output(int bn[N])
	{
		int min;
		int i;
		min = bn[0];
		for(i=0;i<n;i++)
		{
			printf("第%d行的最大值是%d\n",i,bn[i]);
			if(bn[i] < min)
			{
				min = bn[i];
			}
		}
	printf("min=%d\n",min);
	}
void input(int brr[N][N])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&brr[i][j]);
		}
	}
}

	int n;
int main()
{
	printf("请输入矩阵的介数：");
	scanf("%d",&n);
	int arr[N][N]={};
	int b[N]={};
	input(arr);
	compare(arr,b);
	output(b);
	return 0;

}
