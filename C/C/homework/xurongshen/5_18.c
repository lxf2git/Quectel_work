#include<stdio.h>
#define N 5
void out_put(int a[N]);
void int_put(int a[N]);

compare(int b[N])
{
	int i,first,last,max,min,sum =0;
	float average=0;
	int m=0,n=0;
	first = b[0];
	last = b[N-1];
	max = b[0];
	min = b[0];
	for(i=0;i<N;i++)
	{
		if(b[i] >= max)
		{
			max = b[i];
			n = i;
		}
		if(b[i] <= min)
		{
			min = b[i];
			m = i;
		}

		sum += b[i];
	}
	sum = sum-max-min;
	average = (sum*1.0)/(N-2);

	out_put(b);
	printf("该数组的最大值是：%d\n",max);
	printf("该数组的最小值是：%d\n",min);
	printf("该数组的总值是：%d\n",sum);
	printf("该数组的平均值是：%f\n",average);
}

void int_put(int a[N])
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("请输入数组的第%d个数：",i);
		scanf("%d",&a[i]);
		//printf("\n");
	}

}

void out_put(int a[N])
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("输出的数组的第%d个数:%d",i,a[i]);
		printf("\n");
	}

}
int main()
{
	int arr[N],i;
	int_put(arr);
/*
	for(i=0;i<N;i++)
	{
		printf("main--->输出的数组的第%d个数：%d",i,arr[i]);
		printf("\n");
	}
*/
	compare(arr);
	//out_put(arr);
	return 0;
}
