
#include <stdio.h>


int main() 
{
	int num = 0, num1 = 112, num2=2;
	printf("bic----%#x\n", num);

	__asm__ __volatile__(
				//	"mov r1, %1;" //选择寄存器
				//	"mov r2, %2;" //选择寄存器
					"mul %0,%1,%2;"        //
					:"=r"(num)		      //汇编语言的数据写到C语言数据中
					:"r"(num1),"r"(num2) //C语言数据写到汇编数据中
					:"memory","r0","r1","r2"
					);
	printf("bic----%d\n", num);

}
