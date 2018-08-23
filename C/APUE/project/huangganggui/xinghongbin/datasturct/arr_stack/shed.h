#ifndef _SHED_H
#define _SHED_H
#include<stdio.h>
#include<stdlib.h>
#define FULL -1
#define EMPTY -2
#define SIZE 50
typedef struct stack
{
		int *bottom;
		int top;
}sSta,*pSta;
void create_memory(int **p);
void stack_init(pSta p);
int push(pSta p,int data);
int pop(pSta p,int *result);
#endif
