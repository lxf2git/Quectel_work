#include"../apue.h"
int main()
{
	puts("hello");	
	fork();
	puts("world");	
	printf("good\n");
	fork();
	printf("luck\n");
	return 0;

}
