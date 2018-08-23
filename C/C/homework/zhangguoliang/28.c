#include<stdio.h>
#define N 4
int main()
{
	int a[N][N];
	int b[N];
	int i,j,max=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{	printf("输入数组:");
			scanf("%d",&a[i][j]);
			printf("%2d ",a[i][j]);
			if(max<a[i][j])
				max=a[i][j];
		}
		b[i]=max;
		max=0;
		printf("max=%2d ",b[i]);
		printf("\n");
		if(b[0]>b[i])
			b[0]=b[i];

	}
	printf("min=%d\n",b[0]);
	
	return 0;	
}
