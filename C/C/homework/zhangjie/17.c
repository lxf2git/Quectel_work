#include<stdio.h>

int main()
{
	int i,k,h=0,l;
	int a[5];
	scanf("%d",&a[0]);
	k=a[0];
	for(i=1;i<5;i++)
	{
	scanf("%d",&a[i]);
		if(k<a[i])
		{
			k=a[i];
			h=i;
		}
	}	
	l=a[h];
	a[h]=a[4];
	a[4]=l;
	k=a[0];
	h=0;
	for(i=1;i<5;i++)
	{
		if(k>a[i])
		{
			k=a[i];
			h=i;
		}
	}	
	l=a[h];
	a[h]=a[0];
	a[0]=l;
	for(i=0;i<5;i++)
	{
		printf("%d  ",a[i]);
	}
	return 0;
}
