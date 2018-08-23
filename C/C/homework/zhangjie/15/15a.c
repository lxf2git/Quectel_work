#include "divisors.h"

int divisors(int x)
{
	int j;
	scanf("%d",&x);
	for(j=2;j<x;j++)
	{
		if(x%j==0)
		{
			c++;
			s+=j;
			printf("%d ",j);
		}
	}
	return j;
}
