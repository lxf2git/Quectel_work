
# include<stdio.h>


int main() 
{
	int num =0xff, num1 = 0x08;
	__asm__ __volatile__(
					"mov r1, %1;"
					"lsr %0, r1, #1;"
					:"=r"(num)
					:"r"(num1)
					:"memory","r0","r1"
					);
	printf("%d\n", num);

}
