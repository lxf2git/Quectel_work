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
void create_memory(void **q,int size);
pStack init_stack(int size);
int push(pStack ps,void *);
 int is_empty(pStack ps);
void * pop(pStack ps);
 void init_node_stack(pNode *ps);
#endif
