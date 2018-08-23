#include<stdio.h>

void divisors();
int main()
{
	divisors();
	return 0;
}
void divisors()
{
	int a,b,c,i,count,sum;
	count=0;
	sum=0;
	printf("请输入一个100～500之间的整数：");
	scanf("%d",&a);
	for(i=2;i<a;i++)
	{
	b=a%i;//b是a除以i的余数
	c=a/i;//c是a除以i的商
	if(b==0)
	{
	count++;
	sum=sum+c;
	printf("%d\n",c);
	}
	}
	count=count-2;
	//sum=sum+c;
	printf("约数的个数为：%d\n",count);
	printf("约数和为：%d\n",sum);
}
