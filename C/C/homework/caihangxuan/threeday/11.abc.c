#include<stdio.h>
int main()
{
	int a,b,c,max,min,j;
	printf("请输入三个数，以逗号断开");
	scanf("%d,%d,%d",&a,&b,&c);
//	if(a>=b>=c)
	if(a>=b&&a>=c&&b>=c)
	{
	printf("1");
		max=a;
		min=c;
	}
//	else if(a>=c>=b)
	else if(a>=b&&a>=c&&c>=b)
	{
	printf("2");
		max=a;
		min=b;
	}
//	else if(b>=a>=c)
	else if(b>=a&&b>=c&&a>=c)
	{
	printf("3");
		max=b;
		min=c;
	}
//	else if(b>=c>=a)
	else if(b>=a&&b>=c&&c>=a)
	{
	printf("4");
		max=b;
		min=a;
	}
//	else if(c>=a>=b)
	else if(c>=a&&c>=b&&a>=b)
	{
	printf("5");
		max=c;
		min=b;
	}
//	else if(c>=b>=a)
	else if(c>=a&&c>=b&&b>=a)
	{
	printf("6");
		max=c;
		min=a;
	}
	printf("最大的数为%d，最小的数为%d，差为%d。\n",max,min,max-min);
}
