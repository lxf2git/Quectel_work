#include<stdio.h>
#define N 4
int main()
{
	int aa[N][N] = {0}; 
	int a, b, b1, c, c1;
	for(a = 0;a < N;a++)
	{
		for(b = 0;b < N; b++)
		{
			scanf("%d",&aa[a][b]);
		}
	}
	c = aa[0][0];
	c1 = aa[1][0];
	for(a = 0;a < N;++a)
	{
		for(b = a;b < N;b++)
		{
			if(c < aa[a][b])
			{
				c = aa[a][b];
			}
		}
		for(b1 = N - a;b1 >= 0; b1--)
		{
			if(c1 > aa[a][b1])
			{
				c1 = aa[a][b1];
			}
		}
	}
	
	printf("\n最大数%d 最小数%d\n",c,c1);
}
