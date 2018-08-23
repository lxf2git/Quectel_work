#include<stdio.h>
int main()
{
	int a[10],i;
	float sum=0,min,max;
	printf("十个数：\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
		sum=sum+a[i];
	}
	max=a[0];
	min=a[0];
	for(i=0;i<10;i++)
	{
		if(a[i]<min)
			min=a[i];
		if(a[i]>max)
			max=a[i];
	}
	sum=sum-min-max;
	printf("%0.1f\n",sum/8);
return 0;
}
