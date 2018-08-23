#ifndef _SATCK_H_
#define _SATCK_H_

#include<stdio.h>
#include<stdlib.h>

#define SIZE  10
#define FULL  -1
#define SUC    0
#define EMPTY -2

typedef struct Stack
{
	int *bottom;
	int top;
}sStack,*pStack;

void creat_memory(int **p,int size);
void init_stack(pStack p);
int  push(pStack ps,int mod);
int  pop(pStack ps,int *pop_data);

#endif
