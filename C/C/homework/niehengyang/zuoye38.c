#include<stdio.h>
int fun(int *number,int *count);
int main()
{
	int ys;
	int a,b;
	int *number=&a;
	int *count=&b;
	printf("please input number:");
	scanf("%d",&a);
	printf("please input count:");
	scanf("%d",&b);
	ys=fun(number,count);
	printf("%d\n",ys);

}

int fun(int *number,int *count)
{
	int ys;
	int i,c;
	c=*number;
	for(i=0;i<*count;i++)
	{
		*number=*number*c;
	}
	ys=*number%1000;	
	return ys;

}
