#ifndef _STACK_H_
#define _STACK_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100

typedef struct stack
{
	int *bottom;
	int top;
}sStack,*pStack;


void init_stack(pStack ps);
void creat_memory(void **p,int size);
int pop(pStack ps,int *data);
int push(pStack ps,int mod);

void print_num(pStack psta);
int ten_two(pStack psta,int data);


#endif
