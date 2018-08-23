#include<stdio.h>
int main()
{	
	int i,j,n,u;
	printf("请输入矩阵数\n");
	scanf("%d",&n);
	printf("请输入数\n");
	int a[n][n];
	for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
	{
	scanf("%d",&a[i][j]);
	a[i][0]=a[i][0]>a[i][j]?a[i][0]:a[i][j];
	}
	u=u<a[i][0]?a[0][0]:a[i][0];
	}
	printf("%d",u);
return 0;
}
