#include<stdio.h>

int main()
{
	int a[5];
	int i,max,n,b,min,m,c;
	printf("please input five number\n");
	for(i=0;i<5;i++)
		scanf("%d",&a[i]);
	max=a[0];
	n=0;
	for(i=0;i<5;i++)
	{
		if(max<a[i])
		{
			max=a[i];
			n=i;
		}
	}
	b=a[n];
	a[n]=a[4];
	a[4]=b;
	min=a[0];
	m=0;
	for(i=1;i<5;i++)
	{
		if(min>a[i])
		{
			min=a[i];
			m=i;
		}
	}
	c=a[m];
	a[m]=a[0];
	a[0]=c;
	for(i=0;i<5;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;	
}
