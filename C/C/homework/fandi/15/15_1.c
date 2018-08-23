#include"15_1.h"



int yueshu(int x)
{
	int i,sum=0;
	for(i=2;i<x;i++)
	{
	if(x%i==0)
	{
	printf("约数为:%d\n",i);
	sum=sum+i;
	}
	}
	printf("约数和为:%d\n",sum);
	return x;
}
