#ifndef _STACK_H
#define _STACK_H
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
		int data;
		struct node *prev;
		struct node *next;
}sNode,*pNode;

typedef struct stack_chain
{
		pNode bottom;
		pNode top;
}sSta,*pSta;
void get_memory(void **p,int size);
void node_init(pNode *p);
void stack_init(pSta *p);
int push(pSta p,int data);
int pop(pSta p,int *data);
#endif
