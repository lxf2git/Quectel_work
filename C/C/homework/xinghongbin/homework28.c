#include<stdio.h>
#define N 4
void input(int a[][N]);
void deal_rank(int a[][N]);
int main()
{
		int a[N][N];
		input(a);
		deal_rank(a);
		return 0;
}
void input(int a[][N])
{
		int i,j;
		printf("input arr\n");
		for(i=0;i<N;i++)
		{
				for(j=0;j<N;j++)
				{
						scanf("%d",&a[i][j]);
				}
		}
}
void deal_rank(int a[][N])
{
		int i,j,min,max;
		for(i=0;i<N;i++)
		{
				max=a[i][0];
				for(j=0;j<N;j++)
				{

						if(max<a[i][j])
								max=a[i][j];
								
						printf(" %5d",a[i][j]);
				}
				if(i==0)
						min=max;
				else if(min>max)
						min=max;

				printf("\n");
		}

		printf("max_min:%d\n",min);

}
				
