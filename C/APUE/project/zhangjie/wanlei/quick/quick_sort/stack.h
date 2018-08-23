#ifndef _STACK_H_
#define _STACK_H_

#include"main.h"

#define EMPTY -2
#define SIZE   5
#define FULL  -1
#define SUC    0

typedef struct Stack
{
	int low[SIZE];
	int high[SIZE];
	int top;
}sSta,*pSta;

void creat_memory(int **p,int size);
void init_stack(pSta ps);
int push(pSta ps,int low,int high);
int pop(pSta ps,int *low,int *high);

#endif
