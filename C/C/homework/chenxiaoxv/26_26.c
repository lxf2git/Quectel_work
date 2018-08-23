#include<stdio.h>
void fun(int arr[][5])
{
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
}
void min(int a[][5])
{
	int i,j,min;
	for(i=0;i<4;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(min>a[i][j])
				min=a[i][j];
		}
	}
	printf("min:%d\n",min);
}
void max(int a[][5])
{
	int i,j,max;
	for(i=1;i<5;i++)
	{
		for(j=0;j<i;j++)
		{
			if(max<a[i][j])
				max=a[i][j];
		}
	
	}

	printf("max:%d\n",max);
}
int main()
{
	int a[5][5];
	printf("input5X5:");
	fun(a);
	max(a);
	min(a);
return 0;
}

