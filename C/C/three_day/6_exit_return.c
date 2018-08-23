#include<stdio.h>
#include<stdlib.h>
void fun1();
int fun2();
int main()
{
	fun1();	
	printf("main 我回来了\n");
	return 0;
}

void fun1()
{
	printf("i am fun1\n");
	fun2();
	printf("fun1 我回来了\n");
}

int fun2()
{
	printf("i am fun2\n");
	//return 0;
	exit(0);
	printf("**************8\n");

}
