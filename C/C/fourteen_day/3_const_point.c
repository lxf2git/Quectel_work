#include<stdio.h>
int main()
{
	
	int n=90;	
	int m=100;
	const  int *a=&n;
	/**a所指向的对象的值不能通过*a来修改 但可以给
	  a赋值，使其指向不同的对象
	*/
	a = &m;  //*a  m
	//*a = 200;
	m = 200;
	printf("*a:%d\n",*a);

	return 0;

}
