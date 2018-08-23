#include<stdio.h>
#define N 10
int main()
{
	float max,min,average,sum=0;
	int a[N],i;
	
	for(i=0;i<N;i++)
	scanf("%d",&a[i]);
	max=a[0];
	min=a[0];
	for(i=1;i<N;i++)
	{
		if(max<a[i])
		{
			max=a[i];
			
		}
		if(min>a[i])
		{
			min=a[i];
			
		}
	}
	printf("最大值：%f\n",max);
	printf("最小值：%f\n",min);
	for(i=0;i<10;i++)
	{
		sum=sum+a[i];	
		
	}
	sum=sum-max-min;
	average=sum/8;
	printf("总和：%f\n",sum);
	printf("平均数：%f\n",average);
	return 0;
}

