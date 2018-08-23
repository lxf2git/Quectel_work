#include"main.h"
int count_max(int a[])
{
	int i, max;
	max = a[0];
	
	for(i=0; i<n; i++)
	{
		if (max<a[i])
			max =a[i];
	}

	return max;

}
