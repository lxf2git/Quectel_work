#include"calculate.h"

void calculate(int num)
{
	int i,count=0,plus=0;
	for(i=2;i<num;i++)
	{
		if(0 == num % i)
		{
			plus += i;
			count ++;
			printf("%d\n",i);
		}
	}

	printf("There are %d divisors.\n",count);
	printf("The sum of them is %d.\n",plus);
}
