#include<stdio.h>
#define N 16
int main()
{
	int integer,m=0,a[N];
	int i;
	scanf("%d",&integer);
	for(i=0;;i++)
	{		
		if(integer%2==1)
		{
			a[i]=1;
			m+=1;
		}
		if(integer%2==0)
		{
			a[i]=0;
			m+=1;
		}
		if(integer==0)
			break;
		integer/=2;
	}
	for(i=0;i<m-1;i++)
		printf("%d ",a[i]);
	return 0;

}
