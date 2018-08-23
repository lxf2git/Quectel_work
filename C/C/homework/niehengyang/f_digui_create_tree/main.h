#ifndef _MAIN_H_
#define _MAIN_H_
#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
        char data;	
        struct tree *lc;
        struct tree *rc;
}sTree,*pTree;

typedef struct stack_chain
{
	pTree *bottom;
	int top;
}sStack,*pStack;

void push(pStack sta,pTree ptmp);
void pop(pStack sta,pTree *data);
void init_stack(pStack sta);
#endif
