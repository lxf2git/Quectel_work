

#include<stdio.h>

char *strcpy(char *dest, const char *src);

int main() 
{
	char arr[64];
	char* src = "hello linux";
	printf("%s\n", strcpy(arr, src));
	printf("%s\n", arr);

}

char *strcpy(char *dest, const char *src)
{
	__asm__ __volatile__(
					"mov r1, %0;"//dest
					"mov r2, %1;"//src
					"mov r1, #0;"
					"loop:;"
					"ldrb r3, [r2], #1;"
					"strb r3, [r1],#1;"
					"cmp  r3, #0;"
					"bne loop;"
					:
					:"r"(dest),"r"(src)
					:"memory", "r1", "r2","r3"
					);
	return dest;
}
