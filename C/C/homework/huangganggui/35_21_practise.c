#include<stdio.h>

int main()
{
	int x,i;
	int a[32]={0};

	scanf("%d",&x);

	for(i=0;x!=0;i++)
	{
		a[i]=x%2;
		x /= 2;
	}
	i--;
	printf("%d\n",i);
	for(;i>=0;i--)
	{
		printf("%d ",a[i]);
	}
}
