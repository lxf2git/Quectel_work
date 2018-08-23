#include<stdio.h>
int min(int a1[5][5]);
int max(int a2[5][5]);

int main()
{
	int i,j,input[5][5];
	int a=0,b=0;
	printf("输入一个五阶方阵：\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			scanf("%d",&input[i][j]);
		}
	}
	a=min(input);
	b=max(input);
	printf("min:%dmax:%d\n",a,b);
	return 0;

}
int min(int a1[5][5])
{
	int i,j,min;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(j>=i)
			{
				if(a1[i][j]<min)
				{
					min=a1[i][j];
				}
			}
		}
	}
	return min;
}
int max(int a2[5][5])
{
	int i,j,max=0;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(j<i)
			{
				if(a2[i][j]>max)
				{
					max=a2[i][j];
				}
			}
		}
	}
	return max;
}
