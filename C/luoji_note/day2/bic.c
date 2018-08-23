
#include <stdio.h>


int main() 
{
	int num = 0xff, num1, num2;
	printf("bic----%#x\n", num);

	__asm__ __volatile__(
					"bic %0, #0xff;"
					:"=r"(num)
					:
					:"memory"
					);


	printf("bic----%#x\n", num);

}
