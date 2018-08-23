#include<stdio.h>
int main()
{
	int m,n;
	int i,j,k;
	int a[10];
	for(i=0;i<10;i++)
	{
		a[i]=i+1;
	}
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	printf("请输入指定位置：");
	scanf("%d",&m);
	printf("请输入需要逆序的位数：");
	scanf("%d",&n);
	j=m+n-2;
	for(i=0;i<10;i++)
	{
		if(i>=m-1&&i<=m+n-2)
		{
			
			a[i]=j+1;
			j=j-1;
				
		}
		printf("%d ",a[i]);
	}
		printf("\n");
	
}
