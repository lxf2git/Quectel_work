#ifndef _STACK_H_
#define  _STACK_H_
typedef struct stack
{
	int *bottom;//栈底指针
	int top;//数组下标
}sStack,*pStack;
#include<stdlib.h>
#include<stdio.h>
#define SUC 0
#define FULL -1
#define EMPTY -2
#define SIZE 50
void create_memory(int**q);
void init_stack(pStack ps);
int push(pStack ps,int mod);
int pop(pStack ps,int *pop_data);
#endif 
