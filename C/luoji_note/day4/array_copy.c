

#include<stdio.h>

int main()
{
	int arr[6]={1,2,3,4,5,6};
	int arrcp[7];
	__asm__ __volatile__(
					"mov sp, %0;"
					"ldmfd sp!, {r0-r5};"//f
					"mov sp, %1;"
					"stmfd sp!, {r0-r5};"
					:
					:"r"(arr),"r"(arrcp+6)
					:"memory", "r0","r1","r2","r3","r4","r5"
					);

	int i=0; 

	for(; i<6; i++)
	{
		printf("arrcp[%d] = %d \n",i, arrcp[i]);	
	}
}




