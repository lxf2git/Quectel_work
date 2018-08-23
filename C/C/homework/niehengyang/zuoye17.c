#include<stdio.h>
int main()
{
	int i,max,j=0,min=0;
	int a[5],k=0;
	printf("请输入数组:");
	scanf("%d",&a[0]);
	min=max=a[0];
	for (i=1;i<5;i++)
	{	
	scanf("%d",&a[i]);
		if(max<a[i])
		{
			max=a[i];
			j=i;
		}
	}
		
			a[j]=a[4];
			a[4]=max;
		for(i=0;i<5;i++)
		{
		if(min>a[i])
		{
			min=a[i];
			k=i;
		}
		}
			a[k]=a[0];
			a[0]=min;
		for(i=0;i<5;i++)
		{	
		printf("%d ",a[i]);
		}
		printf("\n");	
	//	printf("最大值是:%d\n第%d个数!\n",max,j+1);
		for(i=0;i<5;i++)
		{	
			if(min>a[i])
			{
				min=a[i];
				k=i;
			}	
		}
	//	printf("最小值是：%d\n第%d个数！\n",min,k+1);
	
}
