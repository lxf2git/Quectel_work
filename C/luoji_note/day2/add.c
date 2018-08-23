
#include <stdio.h>


int main() 
{	
	int num, num1=1, num2=2;
		__asm__ __volatile__(
						"mov r0, %1;"
						"mov r1, %2;"
						"add %0, r0, r1;"
						:"=r"(num)
						:"r"(num1),"r"(num2)
						:"memory", "r0","r1");
	printf("add:num %d\n" , num);
}
