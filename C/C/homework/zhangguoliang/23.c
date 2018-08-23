#include<stdio.h>
int main()
{
	int i,j,k,m,n,x;
	int a[10];
	printf("输入十个升序排列的数:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("要求从第m个数开始的n个数逆序排列\n");
	scanf("%d%d",&m,&n);
	k=m+n-2;
	for(j=m-1;j<m-1+n/2;j++)
	{
		x=a[j];
		a[j]=a[k];
		a[k]=x;
		k--;
	}
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");

}
