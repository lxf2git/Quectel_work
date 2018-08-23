#include<stdio.h>
#define N 5
void input(int a[N][N]);
void output(int a[N][N]);

int main()
{
	int a[N][N];
	input(a);
	output(a);
	return 0;
}
void input(int a[N][N])
{
	int i,j;
	for(i=0;i<N;i++)
	{		for(j=0;j<N;j++)
			{
					scanf("%d",&a[i][j]);
			}
	}
	
}
void output(int a[N][N])
{
		int minj=a[0][0],maxi=0;
		int i,j;
		for(i=0;i<N;i++)
		{
				for(j=0;j<N;j++)
				{
						printf("%2d ",a[i][j]);
						if(i<=j)
						{
								minj=minj<a[i][j]?minj:a[i][j];

						}
						if(i>j)
						{
								maxi=maxi>a[i][j]?maxi:a[i][j];
						}

				}
				printf("\n");
		}
		printf("右上最小元素：%d\n左下最大元素：%d\n",minj,maxi);
}
