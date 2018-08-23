//输入三个数，并输出最大数和最小数，并算出最大数和最小数的差

#include<stdio.h>

int ch(int,int,int);

int main()
{
	int shu1, shu2, shu3;
	printf("请输入三个数每个数一空格间隔");
	scanf("%d %d %d",&shu1,&shu2,&shu3);
	ch(shu1,shu2,shu3);
	return 0;
}

int ch(int shu1,int shu2,int shu3)
{
	int max, min;
	if(shu1 >= shu2)
	{
		max = shu1;
		min = shu2;
	}
	else
	{
		max = shu2;
		min = shu1;
	}
	if(max <= shu3)
	{
		max = shu3;
	}
	if(min >= shu3)
	{
		min = shu3;
	}
	printf("最大数%d最小数%d差%d",max,min,max - min);
	return 0;
}
