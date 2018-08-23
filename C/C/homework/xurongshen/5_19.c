#include<stdio.h>
#define N 10
void out_put(int a[N]);
void int_put(int a[N]);

compare(int b[N])
{
	int i,t;
	printf("请输入一个与数组比较的数：");
	scanf("%d",&t);
	for(i=0;i<N;i++)
	{
		if(t == b[i])
		{
			printf("相等的数是%d\n",b[i]);
			printf("该数的下标是%d\n",i);
			break;
		}
		else
		{
			printf("sorry,not found\n");
			break;
		}
	}
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
	out_put(arr);
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
