#include<stdio.h>

void calculate();
int main()
{
	calculate();
	return 0;
}
void calculate()
{
	int a,i;
	i=1;
	printf("请输入一个正数：");
	scanf("%d",&a);
	for(;a/10!=0;)
	{
	a=a/10;
	i++;
	} 
	printf("%d",i);
}
