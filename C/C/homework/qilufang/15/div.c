#include"./div.h"

void div()
{
	int n=500,shuru,count=0,sum=0;
	printf("输入一个数字（100-500）:\n");
	scanf("%d",&shuru);
	for(n=500;n>0;n--)
	{
		
	
		if(shuru%n==0&&shuru>0&&shuru<501&&n!=1&&n!=shuru)
		{
			printf("约数：%d\n",n);
			count+=1;
			sum+=n;
		}
		
		
		
	}
	printf("约数的个数是：%d\n",count);
	printf("约数总和是：%d\n",sum);
	
}
