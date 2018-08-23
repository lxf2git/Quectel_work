#include<stdio.h>
void calculate();

int main()
{
	calculate();
	return 0;
}
void calculate()
{
	int a,c,i,j;
	j = 0;
	c = 0;
	printf("请输入一个100~500之间的整数:\n");
	scanf("%d",&a);
	for (i=2;i<=500;i++)
	{
	if(a%i==0&&a!=i)
	{
	j++;
	c=c+i;
	printf("%d\n",i);
	}
	}
printf("约数的个数:%d\n约数的和为:%d\n",j,c);
}
