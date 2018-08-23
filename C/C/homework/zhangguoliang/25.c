#include<stdio.h>
#define N 4
int main()
{
	int a[N][N];
	int i,j;	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(i<=j)
				printf(" %d",1);
			if(i>j)
				printf(" %d",i-j+1);
		}
		printf("\n");
	}
	return 0;
}
