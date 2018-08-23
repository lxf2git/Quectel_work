#ifndef _STACK_H_
#define _STACK_H_
typedef struct Stack
{
	int *bottom;
  int top;
}sStack,*pStack;

#include<stdio.h>
#include<stdlib.h>
#define SIZE 50
#define FULL -1
#define EMPTY -2
#define SUC 0
void creat_memory(int **p);
void init_memory(pStack ps);
int push(pStack ps,int mod);
int pop(pStack ps,int *pop_data);
#endif

