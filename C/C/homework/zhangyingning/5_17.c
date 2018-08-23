#include<stdio.h>
#define N 5

int in_put(int arr[5])
{
	int w;
	printf("请输入一个数");
	for(w = 0;w < N;w++)
	{
		scanf("%d",&arr[w]);
	}
	return 0;
}
int bijiao(int arr[5])
{
	int w;
	int max, min,max1 = 0,min1 = 0;
	max = arr[0];
	min = arr[0];
	for (w = 1;w < N;w++)
	{
		if(max < arr[w])
		{
			max = arr[w];
			max1 = w;
		}
		if(min > arr[w])
		{
			min = arr[w];
			min1 = w;
		}
	}
		printf("%d  %d  %d  %d\n",max,max1,min,min1);
		if(max1 == 0)
		{
			arr[min1] = arr[N - 1];
			arr[max1] =arr[0];
		}
		else
		{
		arr[max1] = arr[N - 1];
		arr[min1] = arr[0];
		}
		arr[N -1] = max;
		arr[0] = min;
	
}

void put_(int arr[])
{
	int w;
	for(w = 0;w <= N;w++)
	{
		printf(" %d ",arr[w]);
	}
}

int main ()
{
	int arr[5];
	in_put(arr);
	bijiao(arr);
	put_(arr);

}
