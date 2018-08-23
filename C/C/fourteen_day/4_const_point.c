#include<stdio.h>
int main()
{
	
	int n=90;	
	int m=100;
	int *const a=&n;  //const a 
	/*cosnt修饰a a代表指针地址 因为不能给a赋其他地址值 
	 但可以修改a指向的空间上的值
	 * */
	//a = &m;
	*a = 200;
	printf("*a:%d\n",*a);

	return 0;

}
