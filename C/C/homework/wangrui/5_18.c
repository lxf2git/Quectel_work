#include<stdio.h>
#define N 10
//float input(float arr[N]);
//void compare(float a[N]);
int main()
{
	float a[N];
	int i;
	for(i=0;i<N;i++)
	{
		printf("grade:\n");
		scanf("%f",&a[i]);
	}
//	a[N]=input(a[N]);
	int j,k;
	float sum,ave,max,min;
	max=a[0];
	min=a[0];
	for(j=0;j<N;j++)
	{
		if(a[j]>=max)
		{
			max=a[j];
		}
		if(a[j]<=min)
		{
			min=a[j];
		}
	}
	sum=0;
	for(k=0;k<N;k++)
	{
		sum=sum+a[k];
	}
	ave=(sum-max-min)/(N-2);
	printf("mean value is :%f\n",ave);
//	compare(a[N]);
	return 0;	
}

/*float input(float arr[N])
{	
	int i;
	for(i=0;i<N;i++)
	{
		printf("grade:\n");
		scanf("%f",&arr[i]);
	}
	return arr[N];
}*/

/*void compare(float a[N])
{
	int j,k;
	float sum,ave,min,max;
	max=a[0];
	min=a[0];
	for(j=0;j<N;j++)
	{
		if(a[j]>=max)
		{
			max=a[j];
		}
		if(a[j]<=min)
		{
			min=a[j];
		}
	}
	sum=0;
	for(k=0;k<N;k++)
	{
		sum=sum+a[k];
	}
	ave=(sum-max-min)/(N-2);
	printf("mean value is :%f\n",ave);
}*/
