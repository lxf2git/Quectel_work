#ifndef _STACK_H_
#define _STACK_H_
#include<stdio.h>
#include<stdlib.h>
enum Jinzhi
{
	TWO=1,
	EIGHT,
	SIXTEEN,
	EXIT,
};
typedef struct Stack
{
	int *bottom;
	int top;
}sStack,*pStack;
#define SUC 0
#define FULL -1
#define EMPTY -2
#define SIZE 50
int push(pStack ps,int mod);
int pop(pStack ps,int *pop_data);
void getmemory(int **p);
void init_stack(pStack p);
void func(int in,int data,pStack sta);
void myfree(pStack ps);
#endif
