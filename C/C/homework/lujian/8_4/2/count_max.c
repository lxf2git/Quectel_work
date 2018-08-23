#include"main.h"
int count_max(int a[][N])
{
	int i, j,max;
	max = a[0][0];
	
	for(i=0; i<N; i++)
	{
		for (j =0; j<N; j++)
		{
				if (max<a[i][j])
						max =a[i][j];
		}
		
	}

	return max;;

}
