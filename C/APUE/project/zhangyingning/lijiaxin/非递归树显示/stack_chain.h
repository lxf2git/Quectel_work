#ifndef STACK_CHAIN_H_
#define STACK_CHAIN_H_
typedef struct tree
{
	char tr_data;
	struct tree *tr_lc;
	struct tree *tr_rc;
}sTree,*pTree;
typedef struct node
{
		pTree data;
		struct node *prev;
		struct node *next;
}sNode,*pNode;
typedef struct stack_chain
{
		pNode top;
		pNode bottom;
}sStack,*pStack;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SUC 0
#define FULL -1
#define EMPTY -2
#define SIZE 50
void create_memory(void **q,int size);
void init_stack(pStack ps);
int push(pStack ps,pTree mod);
int is_empty(pStack ps);
pTree pop(pStack ps);
void init_node(pNode *ps);
pTree get_stack_top(pStack ps);
#endif
