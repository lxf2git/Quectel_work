
#include <stdio.h>


int main() 
{
	int num = 0, num1 = 1, num2=2;
	printf("bic----%#x\n", num);

	__asm__ __volatile__(
				//	"mov r1, %1;" //选择寄存器
				//	"mov r2, %2;" //选择寄存器
				//	"mul %0,%1,%2;" //
					"mov r1, %1;"
					"lsl %0, r1, #4;"
					:"=r"(num)
					:"r"(num1)//"r"(num2)
					:"memory","r0","r1"
					);
	printf("bic----%d\n", num);

}
