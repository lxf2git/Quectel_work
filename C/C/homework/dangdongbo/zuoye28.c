#include<stdio.h>
#define N 3
int main()
{
		int a[N][N]={},i,j,max=0,min=99999999999999;
		for(i=0;i<N;i++)
		{		
		for(j=0;j<N;j++)
		{
			scanf("%d",&a[i][j]);
	//		printf("%3d",a[i][j]);
			if(max<a[i][j])
					max=a[i][j];
		}
			printf("%d",max);
			if(min>max)
					min=max;
			max=0;
			printf("\n");
		}
		printf("%d",min);
}
