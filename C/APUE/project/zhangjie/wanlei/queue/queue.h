#ifndef _QUEUE_H_
#define _QUEUE_H_

#include"main.h"

#define EMPTY -2

typedef struct Node
{
	pTree data;
	struct Node *prev;
	struct Node *next;
}sNode,*pNode;

typedef struct S_queue
{
	pNode bottom;
	pNode pw;
	pNode rw;
}sQue,*pQue;

void  init_node(pNode *p,int size);
void init_queue(pQue pq);
int push(pQue pq,pTree pdata);
int pop(pQue pq,pTree *data);

#endif
