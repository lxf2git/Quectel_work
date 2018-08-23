#include<stdio.h>
int main()
{	
	int n,i,j;
	scanf("%d",&n);
	int a[n][n];
	for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
	{
	if(i>j)
	{
	a[i][j]=i-j+1;
	}
	else
	{
	a[i][j]=1;
	}
	printf("%d ",a[i][j]);
}
	printf("\n");
}
return 0;
}
