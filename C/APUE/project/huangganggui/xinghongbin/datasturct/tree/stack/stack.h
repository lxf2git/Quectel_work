#ifndef _STACK_H
#define _STACK_H
#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{

	char data;
	int parent;//结构体_成员在结构体中的作用
	struct tree *prev;
	struct tree *plc;
	struct tree *prc;	
}sTree,*pTree;
typedef struct node
{
		struct tree *pdata;
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
int push(pSta p,struct tree *data);
int pop(pSta p,struct tree **data);
#endif
