
#include <stdio.h>


int main() 
{
	int num, num1 = 0x0f, num2=0xff;
	printf("bic----%#x\n", num);

	__asm__ __volatile__(
					"mov r1, %1;"
					"mov r2, %2;"
					"and r1,r2;"
					"mov %0, r1;"
					:"=r"(num)
					:"r"(num1),"r"(num2)
					:"memory","r0","r1","r2"
					);


	printf("bic----%#x\n", num);

}
