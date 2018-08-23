#include<stdio.h>
//void fun1();//声明：告诉编译器：参数个数和类型 函数的返回值类型

void  fun1()
{
	printf("i am fun1\n");
}
int main()
{
	printf("i am main\n");
	fun1();
	printf("goodbye main!\n");
	return 0;
}

