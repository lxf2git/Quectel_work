#ifndef _QUEUE_H
#define _QUEUE_H
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
		
		struct node *next;
		struct node *prev;
}sNode,*pNode;
typedef struct queue_chain
{
		struct node *pw;
		struct node *pr;
}sQueue,*pQueue;
void init_queue(pQueue *p);
void init_node(pNode *p);
void create_queue_memory(void**p,int size);
int push(pQueue p,struct tree* pTemp);
int pop(pQueue p,struct tree **pTemp);
#endif
