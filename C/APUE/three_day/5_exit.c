
#include"../apue.h"
#include<stdio.h>
#include<stdlib.h>

int  fun()
{
	printf("hello");	
	_exit(0);
}
int main()
{
	fun();
	printf("i am main!\n");	
	exit(0);//return 0;
}
