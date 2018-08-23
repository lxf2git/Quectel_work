#include<stdio.h>
int main()
{
	int data1,data2;
	char op;
	scanf("%d,%d",&data1,&data2);
	getchar();
	scanf("%c",&op);
	if(op=='+')
	{
	printf("表达式计算结果为:%d\n",data1+data2);
	}
	if(op=='-')
	{
	printf("表达式计算结果为:%d\n",data1-data2);
	}
	if(op=='*')
	{
	printf("表达式计算结果为:%d\n",data1*data2);
	}
	if(op=='/')
	{
	printf("表达式计算结果为:%d\n",data1/data2);
	}
    return 0;
}
