#include<stdio.h>
int main()
{	
	int a[10],i,j,n,m,times,x;
	printf("输入一个10位的升数组：\n");
	for(i=0;i<10;i++)
	scanf("%d",&a[i]);
	printf("输入第几个数开始：");
	scanf("%d",&n);
	printf("逆序几个数:");
	scanf("%d",&m);

	j=n+m-2;
	times=m/2+n-1;
	
	for(i=n-1;i<times;i++)
	{
	x=a[i];
	a[i]=a[j];
	a[j]=x;
	j--;
	}
	for(i=0;i<10;i++)
	printf("%d ",a[i]);
	


	return 0;
}
