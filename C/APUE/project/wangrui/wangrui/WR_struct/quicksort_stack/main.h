#ifndef _MAIN_H_
#define _MAIN_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}sNode,*pNode;
typedef struct stack
{
	pNode bottom;
	pNode top;
}sStack,*pStack;

//stack
void init_stack(pStack *psta);
int push(pStack ps,int mod);
int pop(pStack ps,int *pop_data);

#endif
