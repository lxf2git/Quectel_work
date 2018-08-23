#include<stdio.h>
#define N 5
void out_put(int a[N]);
void int_put(int a[N]);

compare(int b[N])
{
	int i,first,last,max,min;
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

	//		last = b[i];
			printf("last:%d\n",last);
			printf("first:%d\n",first);
		}
		if(b[i] <= min)
		{
			min = b[i];
			m = i;
	//		first = b[i];
		}
	}
	if(n == 0)
	{
			b[n] = b[N-1];
			b[m] = b[0];
	//	b[n] = last;// 若是这样传值时，会出现把中间的某个数给覆盖
	//	b[m] = first;//
	}
	else
	{
			b[m]=b[0];
			b[n]=b[N-1];
	}
	b[0] = min;
	b[N-1] = max;

			printf("last:%d\n",last);
			printf("first:%d\n",first);
	out_put(b);
	printf("该数组的最大值是：%d\n",max);
	printf("该数组的最小值是：%d\n",min);
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
