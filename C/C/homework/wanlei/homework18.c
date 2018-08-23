#include<stdio.h>

int max(int arr[]);
int min(int arr[]);

int main()
{
	int i,c,b,av,total;
	int a[10];
	printf("please input ten number\n");
	for(i=0;i<10;i++)
			scanf("%d",&a[i]);
	c=max(a);
	b=min(a);
	total=0;
	for(i=0;i<10;i++)
	{
		total=total+a[i];
	}
	av=(total-c-b)/8;
	printf("average:%d\n",av);
	return 0;
}

int max(int arr[])
{
	int i,Max;
	Max=arr[0];
	for(i=0;i<10;i++)
	{
		if(Max<arr[i])
			Max=arr[i];
	}
	return Max;
}

int min(int arr[])
{
	int i,Min;
	Min=arr[0];
	for(i=0;i<10;i++)
	{
		if(Min>arr[i])
			Min=arr[i];
	}
	return Min;
}
