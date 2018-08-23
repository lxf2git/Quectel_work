#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10
#define C 10

void input(int a[][C]);
int search(int a[][C]);

int main()
{
	int a[N][C];
	input(a);
	search(a);
}

void input(int a[][C])
{
	printf("I will give you enough interger by chance ! \n");
	int i=0,j=0;
	srand(time(NULL));
	for(i=0;i<N;i++)
	{
		for(j=0;j<C;j++)
		{
			a[i][j]=rand()%100;
			printf("%-2d ",a[i][j]);
		}
		printf("\n");
	}
}

int search(int a[][C])
{
	int b[N];
	int i,j,max,min;
	printf("the max of every line:");
	for(i=0;i<N;i++)
	{
		int max = a[i][0];
		for(j=0;j<C;j++)
		{
			if(max < a[i][j])
				max = a[i][j];
			
		}		
		b[i]= max;
		printf("%d ",max);
	}
	printf("\n");
	min=b[0];
	for(i=0;i<N;i++)
	{
		if(min>b[i])
			min=b[i];
	}
	printf("the min of those is:%d\n",min);
	
}

