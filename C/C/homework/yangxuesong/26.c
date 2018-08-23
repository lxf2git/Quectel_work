#include<stdio.h>
#define N 5
main()
{	int i,j,n,m=0;
	int a[N][N];
	for(i=0;i<N;i++)
	{
	for(j=0;j<N;j++)
	{
	scanf("%d",&a[i][j]);
	if(i>j)
	{
	m=m>a[i][j]?m:a[i][j];
	}
	else
	{
	n=n<a[i][j]?n:a[i][j];
	}
	}
	printf("\n");
	}
	printf("%d%d",m,n);
return 0;
}
