#include"ass.h"



void digit(int num)
{
	int i,j,k;

	i=10;
	k=0;

	while(j != num)
	{	
		j=num%i;
		i=i*10;
		k++;
	}
	printf("%d\n",k);
}
