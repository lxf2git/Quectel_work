#ifndef _STACK_H_
#define _STACK_H_
typedef struct stack
{
		int *ret;
		int *low;
		int *high;
		int top;
}sStack,*pStack;
#include<stdlib.h>
#include<stdio.h>
#define SIZE 50
#define SUC 0
#define EMPTY -1
#define FULL  -2
#endif
