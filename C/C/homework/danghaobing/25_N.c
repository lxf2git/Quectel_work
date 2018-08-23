#include<stdio.h>
#define N 5

int main()
{
	int a[N][N];
	int i,j;
	for(i=0;i<N;i++)
	{		for(j=0;j<N;j++)
			{
					if(j>=i)
					{
							printf("1 ");
					}
					if(j<i)
					{
							printf("%d ",i-j+1);
					}
			}
			printf("\n");
	}
}
