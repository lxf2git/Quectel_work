#include"14_divisors.h"

void divisors(int x)
{
		int i,count=0,sum=0;
		for(i=2;i<x;i++)
		{
				if(x%i==0)
				{
						printf("%d ",i);
						count++;
						sum+=i;
				}
		}
		printf("\n约数个数：%d\n",count);
		printf("约数和：%d\n",sum);
}
