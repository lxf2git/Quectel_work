#ifndef _MAIN_H_
#define _MAIN_H_
#include<stdio.h>
#include<stdlib.h>
#define EMPTY 0
#define SUB 1
typedef struct tree
{
		char data;
		struct tree *pa;
		struct tree *lc;
		struct tree *rc;
}sTree,*pTree;
typedef struct link
{
		struct tree *tree;
		struct link *next;
		struct link *prev;
}sLink,*pLink;
typedef struct queue
{
		struct link *pw;
		struct link *pr;
}sQueue,*pQueue;
void create_memory(void **p,int size);
void free_memory(void **p);
void init_queue(pQueue *queue);
void init_link_node(pLink *link);
void init_tree_node(pTree *tree);
void create_tree(pTree *root);
void add_link_node(pLink phead,pLink pnew);
void del_link_node(pLink phead,pLink pdel);
void push(pQueue queue,pTree tree);
void pop(pQueue queue,char *data);
int queue_empty(pQueue queue);
void output(pTree root);
#endif
