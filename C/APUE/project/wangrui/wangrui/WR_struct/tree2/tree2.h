#ifndef _TREE2_H_
#define _TREE2_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 30
#define SUC 1
#define EMPTY -1
typedef struct tree
{
	char data;
	struct tree *left;
	struct tree *right;
	struct tree *parent;
}sTree,*pTree;
typedef struct node
{
	pTree pdata;
	struct node *prev;
	struct node *next;
}sNode,*pNode;
typedef struct stack
{
	pNode bottom;
	pNode top;	
}sStack,*pStack;
typedef struct queue
{
	pNode qhead;
	pNode write;
	pNode read;
}sQueue,*pQueue;
void creat_tree(pTree *p);
void init_tree(pTree *p);
void creat_memory(void **p,int size);
void free_memory(void **p);
void show_tree(pTree proot);

//print
int pre_tree(pStack psta,pTree proot);
int mid_tree(pStack psta,pTree proot);
int last_tree(pStack psta,pTree proot);
int is_empty(pStack ps);
pTree get_top(pStack ps);
int is_queue_empty(pQueue pque);
int queue_tree(pQueue pque,pTree proot);

//stack
void init_stack(pStack *ps);
void init_node(pNode *pnode);
int push(pStack ps,pTree pmod);
int pop(pStack ps,pTree *pop_tree);
//queue
void init_queue(pQueue *pq);
int push_queue(pQueue pq,pTree pmod);
int pop_queue(pQueue pq,pTree *pop_tree);


#endif
