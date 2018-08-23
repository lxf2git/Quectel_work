#include<stdio.h>

void calculate(int a,int b,int c);
int main()
{

	int a,b,c;
	printf("a: b: c: \n");
	scanf("%d%d%d",&a,&b,&c);
	calculate(a,b,c);
	return 0;
}


void calculate(int a,int b,int c)
{
	int max,min,i;
	if(a>=b)
	{
		max=a;
		min=b;
		if(c>=max)max=c;
		if(c<=min)min=c;
	}
	else
	{
		max=b;
		min=a;
		if(c>=max)max=c;
		if(c<=min)min=c;
	}
	printf("最大值:%d\n最小值:%d\n差:%d\n",max,min,max-min);
}
