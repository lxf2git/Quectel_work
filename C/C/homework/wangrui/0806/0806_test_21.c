#include<stdio.h>
#define N 100

int main()
{
	int i,j,k,x,n;
	int a[N]={};
	k=0;
	j=0;
	scanf("%d",&x);
	for(i=1;x>i;i=i*2)
	{
		k++;
	}
	n=k;
	for(;k>0;k--)
	{
		a[j]=x%2;
		x=x/2;
		j++;
	}
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	printf("\n");
}
