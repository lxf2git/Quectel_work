#include<stdio.h>

int a=90;
extern int e;

void fun1()
{
	int a=1001;	
	printf("fun1_a:%d\n",a);
	printf("fun1_e:%d\n",e);
}


int e=100;

void fun2()
{
	printf("fun_2 a:%d\n",a);	
	printf("fun2_e:%d\n",e);
}
int main()
{
	printf("main_a:%d\n",a);
	printf("main_e:%d\n",e);
	//a++;
	fun1();	
	fun2();
	return 0;
}
