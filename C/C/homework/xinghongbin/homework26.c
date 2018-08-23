#include<stdio.h>
#define N 5
void input(int a[][N]);
void deal_rank(int a[][N]);
int main()
{
		int a[N][N];
		input(a);
		deal_rank(a);
		return 0;
}

void input(int a[][N])
{
		int i,j;

		for(i=0;i<N;i++)
		{
				for(j=0;j<N;j++)
				{
						scanf("%d",&a[i][j]);
				}
		}
}

void deal_rank(int a[][N])
{
		int i,j,min,max;
		min=a[0][0];
		max=a[1][0];
		for(i=0;i<N;i++)
		{
				for(j=0;j<N;j++)
				{

						if(j>=i)
						{
								if(min>a[i][j])
										min=a[i][j];
						}
						else 
						{
								if(max<a[i][j])
										max=a[i][j];
						}
								
						printf(" %5d",a[i][j]);
				}
				printf("\n");
				
		}
		printf("min:%d max:%d\n",min,max);
}
