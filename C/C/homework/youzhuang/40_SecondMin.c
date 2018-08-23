#include<stdio.h>
#include<stdlib.h>

void create_memory (void **p, int size);
int secondmin (int **p, int x, int y);
void input (int **p, int x, int y);
void free_memory (int **p);

int main()
{
		int **p = NULL;
		int x, y,j, i;

		printf ("please input row:\n");
		scanf ("%d", &x);
		printf ("please input col:\n");
		scanf ("%d", &y);
		create_memory ((void **)&p,x*sizeof(int *));
		for (i=0;i<x;i++)
		{
				create_memory ((void **)(p+i), y*sizeof(int));
		}

		printf ("please input data:\n");
		input (p, x, y);

		printf("second min is:%d\n",secondmin(p,x,y));
		
		for(i=0;i<x;i++)
		{
				free_memory(p+i);
		}
		free_memory(p);

		return 0;
}

int secondmin (int **p, int x, int y)
{
		int smin, min, i, j;
		min = p[0][0];
		if (y > 1)
		{
				smin = p[0][1];
		}
		else
		{
				smin = p[1][0];
		}
		for (i=0;i<x;i++)
		{
				for (j=0;j<y;j++)
				{
						if (p[i][j] < min)
						{
								min = p[i][j];
						}
				}
		}
		for (i=0;i<x;i++)
		{
				for (j=0;j<y;j++)
				{
						if (p[i][j] > min && p[i][j]<smin)
						{
								smin = p[i][j];
						}
				}
		}
		return smin;
}

void create_memory (void **p, int size)
{
		*p = malloc(size);
		if (*p == NULL)
		{
				printf ("create memory error!\n");
				return exit(-1);
		}
}

void input (int **p, int x, int y)
{
		int i, j;
		for (i=0;i<x;i++)
		{
				for (j=0;j<y;j++)
				{
						scanf ("%d",&p[i][j]);
				}
		}
}

void free_memory (int **p)
{
		free (*p);
}
