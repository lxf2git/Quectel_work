#include"n_power.h"

void power(int *p,int n)
{
		int i;
		int k=0;
		k = *p;
		for(i=1;i<n;i++)
		{
			*p = *p * k;	
		}
}
