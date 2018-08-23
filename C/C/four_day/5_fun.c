#include<stdio.h>


void fun2()
{
	printf("i am fun2\n");
	char ch;
}

void fun1()
{
	printf("i am fun1\n");
	int a;
	int b;
	fun2();
}
int main()
{
	printf("i am main\n");	
	fun1();	
	return 0;
}
