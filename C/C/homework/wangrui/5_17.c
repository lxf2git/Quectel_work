#include<stdio.h>
#define N 5

int main()
{
	int i,max,min,n,m;
	int a[N];
	i=0;
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	max=a[0];
	min=a[0];
	for(i=0;i<N;i++)
	{	
		if(a[i]>=max)
		{
			max=a[i];
			m=i;
		}
		 if(a[i]<=min)
		{
			min=a[i];
			n=i;
		}
	}
	if(m==0)
	{
		a[m]=a[N-1];
		a[n]=a[0];
	}
	else
	{
		a[n]=a[0];
		a[m]=a[N-1];
	}
//	a[m]=a[N-1];
	a[0]=min;
//	a[m]=a[N-1];
	a[N-1]=max;

	for(i=0;i<5;i++)
	{
		printf("%d\n",a[i]);
	}
	printf("max:%d\nmin:%d\n",max,min);
	return 0;
}
