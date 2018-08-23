#include<stdio.h>
void deal(int a[][100],int n);
void output(int a[][100],int n);

int main()
{
	int n;
	int a[100][100];
	printf("How many do you want(1~99):");
	scanf("%d",&n);
	if (n>1&&n<100)
	{
	deal(a,n);
	output(a,n);
	}else
	{
	printf("input err !");
	}
	return 0;
}

void deal(int a[][100],int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			a[i][j] = 1;
			if(i > j)
				a[i][j] = i - j + 1;
		}
}

void output(int a[][100],int n)
{
	int i,j;
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
			printf("%-2d ",a[i][j]);
		printf("\n");
	}

}
