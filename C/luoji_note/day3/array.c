

#include<stdio.h>



int main() 
{
	int arr[6]={1,2,3,4,5,6};

	int arr1[6];

	int i=0; 
	for (; i<6; i++)
	{
		printf("arr[%d] =%d\n",i, arr[i]);
	}
	printf("+++++++++++++++++++++++++++++\n");
	__asm__ __volatile__(
					"mov r3, #0;"
					"mov r1, %0;"
					"mov r2, %1;"
					"loop:;"
					"ldr r0, [r1];"
					"str r0, [r2];"
					"add r3, #1;"
					"cmp r3, #6;"
					"addne r1, #4;"
					"addne r2, #4;"
					"bne loop"
					:
					:"r"(arr),"r"(arr1)
					:"memory","r0","r1","r2","r3"
					);

	for (i=0; i<6; i++)
	{
		printf("arr1[%d] =%d\n",i, arr1[i]);
	}
}
