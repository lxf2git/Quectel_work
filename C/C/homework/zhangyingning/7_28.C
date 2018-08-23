#include<stdio.h>

int main()
{
	int aa[5][5] = 
       {1,2,3,4,5,
	6,7,8,9,0,
	1,2,3,4,5,
	6,7,8,9,0,
	1,2,3,4,5};
	int max = 0,max1 = 0,min = 0,a,b,c,d;
	for(a = 0;a < 5;a++)
	{
		max1 = aa[a][0];
		for(b = 0;b < 4;b++)//判断4次
		{
			if(max1 < aa[a][b + 1])
			{
				max1 = aa[a][b + 1];
			}
			if(min > aa[a][b])
			{
				min = aa[a][b];
			}
		}
		if(min > aa[a][b + 1])
		{
			min = aa[a][b + 1];
		}
		if(max < max1)
		{
			max = max1;
		}
		printf("第%d列 最大算%d\n",a,max1);
	}
	printf("最大数%d最小数%d\n",max,min);
}
