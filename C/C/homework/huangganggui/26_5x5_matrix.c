#include<stdio.h>
void input(int a[][5]);
void output(int a[][5]);
void deal(int a[][5]);

int main()
{
	int a[5][5];
	
	
	input(a);
	output(a);
	deal(a);
	return 0;
}

void input(int a[][5])
{
	int i,j;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			scanf("%d",&a[i][j]);
}

void output(int a[][5])
{
	int i,j;
	for(i = 0;i < 5;i++)
	{
		for(j = 0;j < 5;j++)
			printf("%-2d ",a[i][j]);
		printf("\n");
	}

}

void deal(int a[][5])
{
	int i,j;	
	int max=a[1][0],min=a[0][0];
	for(i=0;i< 5;i++)
			for(j=0;j < 5;j++)
			{
				if(i>j)
				{
					if (max < a[i][j])
						max = a[i][j];
				}else
				{
					if (min > a[i][j])
						min = a[i][j];
				}
			}
	printf("max:%d\nmin:%d\n",max,min);
}
