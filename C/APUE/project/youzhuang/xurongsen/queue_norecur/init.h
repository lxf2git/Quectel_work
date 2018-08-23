#ifndef _INIT_H_
#define _INIT_H_

#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

typedef struct Tree
{
	char data;
	struct Tree *lc,*rc,*parent;
}sTree,*pTree;

typedef struct Node
{
	pTree pdata;
	struct Node *prev,*next;
}sNode,*pNode;

typedef struct Stack
{
	pNode bottom;
	pNode top;
}sStack,*pStack;

enum TYPE
{
	EMPTY=-1,
	FAILED=0,
	SUC=1,
	FULL=2
};

//-----main---------
void create_tree(pTree *proot);
void init_tree(pTree *ptroot);
void prev_show(pTree root);
void last_show(pTree root);
void show_tree(pTree root);

//---------init_tree.c--------
void create_memory(void **p,int size);
void free_memory(void **P);

void init_node(pNode *pnode);
void init_stack(pStack *pstack);
int push(pStack pst,pTree ptree);
int pop(pStack pst,pTree *ptr_del);

int push_queue(pStack pst,pTree ptree);
int pop_queue(pStack pst,pTree *ptree);
//-----------mid_out.c------------
int first_tree(pStack pst,pTree ptroot);
int  mid_tree(pStack pst,pTree ptroot);
int last_tree(pStack pst,pTree ptroot);

void queue_show(pStack pst,pTree ptroot);

//-----------
#endif
