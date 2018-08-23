#include<stdio.h>

int main()
{
	int arr[10];
	int max, min, max1 = 0, min1 = 0, xun, he = 0;
	float chu = 8;
	printf("请输入十组成绩以空格间隔");
	for(xun = 0; xun < 10;xun++)
	{
		scanf("%d",&arr[xun]);
		if(arr[xun] < 0)
		{
		printf("请重新输入");
		scanf("%d",&arr[xun]);
		}
	}
	max = arr[0]; 
	min = arr[0];
	for(xun =1 ;xun < 10;xun++)
	{
			if(max < arr[xun])
		{
			max = arr[xun];
			max1 = xun;
		}
		if(min >= arr[xun])
		{
			min = arr[xun];
			min1 = xun;
		}

	}
	arr[min1] = 0;
	arr[max1] = 0;
	for(xun = 0;xun < 10;xun++)
	{
		he += arr[xun];
		printf("%d\n",he);
	}
	printf("平均分为%.2f",he / chu);



}
