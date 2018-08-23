#include<stdio.h>
//int fun1(int);//声明：告诉编译器：参数个数和类型 函数的返回值类型

int fun1(int n)
{
	return n;
}
int main()
{
	int ret=fun1(4);
	printf("ret:%d\n",ret);
	return 0;
}

