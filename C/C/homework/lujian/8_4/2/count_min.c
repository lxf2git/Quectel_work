#include"main.h"
int count_min(int a[][N])
{
		int i, j, min;
		min = a[0][0];
		for (i=0; i<N; i++)
		{

				for (j = 0; j < N; j++)
				{
						if (min > a[i][j])
						{
								min = a[i][j];
						}

				}

		}



		return min; 
}


