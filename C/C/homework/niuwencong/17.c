#include<stdio.h>
int main()
{	
	int a[5];
	int i,t,p,f,min,max;
	printf("请输入5个数：\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n");
	min=a[0];
	max=a[4];
	for(i=0;i<5;i++)
	{
		if(a[i]<min)
		{
			min=a[i];
			f=i;
		}
		if(a[i]>max)
		{
			max=a[i];
			p=i;
		}
	}
	t=a[0];
	a[0]=a[f];
	a[f]=t;
	t=a[4];
	a[4]=a[p];
	a[p]=t;
	for(i=0;i<5;i++)
	{
		printf("%d\n",a[i]);
	}
return 0;
}
