#ifndef STACK_H_
#define STACK_H_
typedef struct stack
{
		int top;
		int *bottom;
}sStack,*pStack;
pStack skt;
#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
#define SUC 0
#define FULL -1
#define EMPTY -2
void get_memory(void **p,int size);
int push(pStack skt,int data);
int pop(pStack skt,int *data);
//int a;
#endif
