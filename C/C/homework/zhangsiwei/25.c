#include<stdio.h>
#define N 5
int main()
{
	int arr[N][N];
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(i-j+1>0)
				printf("%d  ",i-j+1);	//	a[i][j]=i-j+1;
			else
				printf("1  ");	//	a[i][j]=1;	
		}
			printf("\n");
	}
	return 0;
}
