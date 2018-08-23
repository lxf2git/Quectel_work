#ifndef _STACK_CHAIN_H_
#define _STACK_CHAIN_H_
typedef struct  node
{
	void* data;
	struct node *prev;
	struct node *next;
}sNode,*pNode;

typedef struct stack_chain
{
	pNode bottom;//phead
	pNode top;
}sStack,*pStack;
#include<stdlib.h>
#include<stdio.h>
#define SUC 0
#define FULL -1
#define EMPTY -2
#define SIZE 50
void create_memory(pNode *q,int size);
pStack init_stack(pStack ps);
int push(pStack ps,int mod);
 int is_empty(pStack ps);
void * pop(pStack ps,void*tr);
 void init_node(pNode *ps);
#endif
