#include<stdio.h>
void output(int *a);
void deal(int *a);
void input(int *a);
#define N 4     //N >= 3;
int main()
{
	int a[N];
	input(a);
	deal(a);
	output(a);
	return 0;
}

void input(int *a)
{
	int i;
	printf("input your score:");
	for(i = 0;i < N;i++)
	{
		scanf("%d",&a[i]);
	}
	
}

void deal(int *a)
{
	int i;
	int max = a[0],min=a[1];
	int max_num = 0,min_num = 0;

	for(i = 1;i < N;i++)
	{
		if(max < a[i])
		{
			max = a[i];
			max_num = i;
		}
		if(min > a[i] )
		{
			min = a[i];
			min_num = i;
		}
	}
	printf("max:%d\n",max);
	printf("min:%d\n",min);
	a[max_num] = a[min_num] = 0;
	
	printf("a[2]:%d\n",a[2]);
}

void output(int *a)
{
	int sum = 0;
	float average;
	int i;
	printf("a[2]%d\n",a[2]);
	for(i = 0;i < N;i++)
	{
		sum += a[i];
//		printf("%d ",a[i]);	
	}
	
	if(N > 2)
	average = sum / (N - 2);
	printf("The average is %f\n",average);
}
