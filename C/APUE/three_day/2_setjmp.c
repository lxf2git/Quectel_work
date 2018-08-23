#include"../apue.h"
jmp_buf jmp;
void fun2()
{
	printf("fun2-start...\n");
	printf("fun2-end...\n");
}
void fun1()
{
	printf("fun1-start...\n");
	//longjmp(jmp,5);
	printf("fun1-end...\n");
}
void fun()
{
	printf("fun-start...\n");
	printf("fun-end...\n");
}
int main()
{
	int ret;	
	 ret = setjmp(jmp);
	 //1 setjmp 顺序调用 返回0
	// 2 longjmp：返回longjmp第二个参数值(val非0)
	 if(ret==0)
	 {
	 	fun();
		fun1();
	 }
	 else
	 {
		printf("ret:%d\n",ret);	 
	 	fun2();
	 }
	return 0;

}

