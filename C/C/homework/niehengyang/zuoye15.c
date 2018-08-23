#include<stdio.h>
int main()
{
	int divisors,number,i;
	int sum=0,count=0;
	printf("请输入整数：");
	scanf("%d",&number);
	printf("%d的约数有：\n",number);
	for(i=2;i<=number;i++)
	{
		if(number/i>1&&number%i==0)
		{
		count=count+1;
		divisors=number/i;
		sum=sum+divisors;
		printf("%d,\n",divisors);
		}
		
	}

		printf("%d的约数有%d个，它们的和为：%d\n",number,count,sum);
}
