#include<stdio.h>
#include<string.h>
#define N 32
int main()
{
	int n,i,j,x,k=0;;
	int a[N];
	scanf("%d",&n);
	for(i=0;;i++)
	{
		if(n%2==1)
		{
			a[i]=1;
			k+=1;
		}
		if(n%2==0)
		{
			a[i]=0;
			k+=1;
		}
		if(n/2==0&&n%2==1)
		{
			a[i]=1;
			k+=1;
			break;
		}
		n=n/2;
	}
	for(i=0;i<k-1;i++)
		printf("倒序为:%d\t",a[i]);
	return 0;
}
