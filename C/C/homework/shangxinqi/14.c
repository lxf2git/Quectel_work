#include<stdio.h>
void calculate();

main()
{
	calculate();
	return 0;
}
void calculate()
{
	int a,i;
	i = 1;
	printf("请输入一个正数:\n");
	scanf("%d",&a);
while(a>10)
{
	++i;
	a=a/10;
}
printf("该数是一个:%d位数\n",i);

}
