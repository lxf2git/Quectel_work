#include<stdio.h>

void fun(int b)//b=a  b=100
{
	printf("b:%p",&b);
}
int main()
{
	int a=100;
	printf("a:%p\n",&a);
	fun(a);
}
