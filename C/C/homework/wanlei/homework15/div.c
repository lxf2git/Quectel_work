#include "div.h"

int div(int x)
{
	int i,sum=0;
	for(i=2;i<x;i++)
	{
		if(x%i==0)
		{
		sum+=i;
		printf("%d ",i);
		j++;
		}
	}
	return sum;
}
