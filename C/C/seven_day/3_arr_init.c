#include<stdio.h>
#define R 2
#define C 3

int main()
{
	int i,j;
	//int a[M][N]={1,2,3,4};
	int a[][4]={{1,2,3},{4,5,6,7}};
	int a1[2][3];	

	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			scanf("%d",&a[i][j]);	
			printf("a[%d][%d]:%d  ",i,j,a[i][j]);
		}
		printf("\n");
	}

	return 0;


}

