#include<stdio.h>
#define N 5
#define R 4
#define C 4

	output2(int a[N][N])
	{
		int i, j,t;
		t=a[1][0];
		for(i=0;i<N;i++)
		{
			for(j=0;j<i;j++)
			{
				if(a[i][j] >= t)
				{
					t = a[i][j];
				}
			}
		}
		printf("max=%d\n",t);
	}
	output1(int a[N][N])
	{
	//	int a[N][N]={0};
		int i, j,t;
		t=a[0][0];
		for(i=0;i<N;i++)
		{
			for(j=i;j<N;j++)
			{
			//	printf("%5d",a[i][j]);
				if(a[i][j] <= t)
				{
					t = a[i][j];
				}
			}
		//	printf("\n");
		}
		printf("min=%d\n",t);
	}

	input(int a[N][N])
	{
//		int a[N][N]={0};
		int i, j;
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				scanf("%5d",&a[i][j]);
			}
			
		}
	}
int main()
{
//	int arr[R][C];
//	printf("请输入矩阵的介数：");
//	int n;
//	scanf("%d",&n);
	printf("请输入一个5介的方正：\n");
	int a[N][N]={0};
	input(a);
	output1(a);
	output2(a);
	return 0;

}
