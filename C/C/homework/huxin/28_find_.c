#include<stdio.h>
#include<time.h>
#define N  5
void input(int x[][N]);
void find(int x[][N]);
int main()
{
	int a[N][N];
	input(a);
	find(a);
	return 0;
}
void input(int x[][N])
{
	int i,j;
	srand(time(NULL));
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			x[i][j]=(rand()%100);
		}
    }
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%3d ",x[i][j]);
		}
		printf("\n");
    }
	
}
void find(int x[][N])
{
	int i,j,m,n;
    for(i=0;i<N;i++)
	{  
		m=0;
		for(j=0;j<N;j++)
		{
	        if(m<x[i][j])
			m=x[i][j];	
		}
	    printf("a[%d]:max:%d\n",i,m);
		if(n>m)
		{
			n=m;
		}
     }
   printf("min : %d\n",n);
}
/*srand(time(NULL))
 * a[][]=(rand()%100);*/
