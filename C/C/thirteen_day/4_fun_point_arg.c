#include<stdio.h>
/*int a;
 *int *p=&a;  char *ch; float * f; 
 *函数指针：本质是指针 存函数入口地址 指向一类函数
  1、定义
  2、赋值
  3、调用
 * */
int add(int a,int b)
{
	return a+b;
}
#if 0
int div(int a,int b)
{
	return a-b;
}
#endif

void func(int (*p)(int,int),int m,int n)//1 定义 2 赋值 p=add;
{
	int ret = p(m,n);//add(m,n)  3 调用
	printf("result:%d\n",ret);
}
int main()
{
	int a=10,b=20;	
	func(add,a,b);

	return 0;

}



