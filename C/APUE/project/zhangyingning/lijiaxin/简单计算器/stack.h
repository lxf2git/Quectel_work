#ifndef STACK_H_
#define STACK_H_
typedef struct stack
{
		int top;
		int *bottom;
}sStack,*pStack;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50
#define SUC 0
#define EMPTY -1
#define FULL -2	
int record;
void get_memory(void **p,int size);
void init_stack(pStack *pp);
int push(pStack pp,int inter);
int pop(pStack pp);
int mul(pStack p_data);
int del(pStack p_data);
void deal(pStack p_data,pStack p_oper);
void print(pStack p_data,pStack p_oper);
#endif
