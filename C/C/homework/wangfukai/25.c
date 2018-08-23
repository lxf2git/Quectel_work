#include<stdio.h>

int main()
{
	int a[500][500],i,j,n;
	printf("请输入一个数：");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	for (j=0;j<n;j++)
	{
	if(i<=j)
	{
		a[i][j]=1;
		printf("%d",a[i][j]);
		if(j==n-1)
		{printf("\n");}
	}
	else
	{
		a[i][j]=i-j+1;
		printf("%d",a[i][j]);
	}
	}
	}
	return 0;
}
