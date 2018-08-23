#include"deal.h"
int deal(int num)
{
	int tmp=1,i=1,j=0;
	
	while(tmp!=0)
	{
		j++;
		i *= 10;
		tmp=num / i;
	}
	return j;
}
