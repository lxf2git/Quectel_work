#include<stdio.h>
void fun1()
{
	printf("%d\n",a);
	//int d;
	//printf("fun1_d:%p\n",&d);
}

int main()
{
	int a=9;
	int b;
	char c;
	printf("&a:%p\n",&a);	
	//printf("&b:%p\n",&b);	
	//printf("&c:%p\n",&c);	
	//printf("fun2_d:%p\n",&d);
	fun1();

	return 0;
}
