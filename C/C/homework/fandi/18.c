#include<stdio.h>
#include<time.h>
int main()
{
	int a[10],i;
	srand(time(NULL));
	float max,min,sum=0;
	for(i=0;i<10;i++)
	{
		a[i]=rand()%100;
		if(i==0)
		{
			max=a[0];
			min=a[0];
		}
		printf("%d\t",a[i]);
		if(max<a[i])
		{
			max=a[i];
		}
		if(min>a[i])
		{
			min=a[i];
		}
		sum=sum+a[i];
	}
	printf("\n");
	printf("最大值为:%f\n",max);
	printf("最小值为:%f\n",min);
	printf("平均分为:%f\n",(sum-max-min)/10);
	return 0;
}
