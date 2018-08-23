#ifndef QUEUE_H_
#define QUEUE_H_
typedef struct tree
{
		char tr_data;
		struct tree *tr_lc;
		struct tree *tr_rc;
}sTree,*pTree;
typedef struct node
{
		pTree data;
		struct node *next;
		struct node *prev;
}sNode,*pNode;
typedef struct queue
{
		pNode bottom;
		pNode pw;
		pNode pr;
}sQueue,*pQueue;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SUC 0
#define FULL -1
#define EMPTY -2
void create_memory(void **p,int size);
void init_node(pNode *ps);
pQueue init_queue(int size);
int push(pQueue ps,pTree root);
pTree pop(pQueue ps);

#endif


