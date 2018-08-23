#include<stdio.h>
#define N 5
void input(int x[][N]);
void right_min(int x[][N]);
void left_max(int x[][N]);
int main()
{
	
	int a[N][N];
	input(a);
    right_min(a);
    left_max(a);	
	return 0;
}
void input(int x[][N])
{
	int i,j;
	printf("please input matrix 5*5 :\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d",&x[i][j]);
		}
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%3d ",x[i][j]);
		}
       printf("\n");
	}
}
void right_min(int x[][N])
{
 	int i,j,mi;
	mi=x[0][0];
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(i<=j)
			{   
				
				if(mi>x[i][j])
				{
				   mi=x[i][j];
				}
			
			}
		}
     }
	printf("right_min : %d\n",mi);
}
void left_max(int x[][N])
{
 	int i,j,ma;
	ma=x[1][0];
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(i>j)
			{   
				
				if(ma<x[i][j])
				{
				   ma=x[i][j];
				}
			
			}
		}
     }
	printf("left_max : %d\n",ma);
}
