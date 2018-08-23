#include<stdio.h>

void input(int a[][5]);
int max(int a[][5]);
int min(int a[][5]);

int main()
{
	int i,j;
	int m,n;
	int a[5][5];
	input(a);
	m=max(a);
	n=min(a);
	printf("左下最大值：%d右上最小值：%d\n",m,n);
	return 0;
}

void input(int a[][5])
{
	int i,j;
	printf("请输入一个五级数组\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			scanf("%d",&a[i][j]);	
		}
	}
}

int max(int a[][5])
{
	int i,j;
	int Max;
	Max=a[1][0];
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(i>j)
			{
				if(Max<(a[i][j]))
					Max=a[i][j];
			}
		}
	}
	return Max;
}

int min(int a[][5])
{
	int i,j;
	int Min;
	Min=a[0][0];
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(i<=j)
			{
				if(Min>(a[i][j]))
					Min=a[i][j];
			}
		}
	}
	return Min;
}
