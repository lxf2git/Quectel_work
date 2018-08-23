#ifndef _INIT_H_
#define _INIT_H_
#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
		char ch;
		struct tree *tr_lc;
		struct tree *tr_rc;
}sTree,*pTree;

typedef struct stack
{
		pTree paar;
		struct stack *prev;
		struct stack *next;
}sStack,*pStack;

		
#endif
