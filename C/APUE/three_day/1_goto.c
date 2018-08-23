#include"../apue.h"

void fun()
{
	puts("fun-start..");
	puts("fun-end..");
}
void fun1()
{
	puts("fun1-start..");
	puts("fun1-end..");
}
void fun2()
{
	puts("fun2-start..");

	puts("fun2-end..");
}



int main()
{
	fun();
	fun1();
	goto FLAG;
	fun2();	
FLAG:
	puts("flag......");
	return 0;

}
