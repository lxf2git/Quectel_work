#ifndef _STACK_H_
#define _STACK_H_
typedef struct stack
{
		int *bottom;
		int top;
}sStack,*pStack;
#include<stdlib.h>
#include<stdio.h>
#define SIZE 50
#define SUC 0
#define EMPTY -1
#define FULL  -2
 void greate_memory(int **p);
 void init_stack(pStack pS);
  int push(pStack ps,int mod);
  int pop(pStack ps,int *pop_data);

#endif
