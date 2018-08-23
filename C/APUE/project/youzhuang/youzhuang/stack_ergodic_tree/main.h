#ifndef _MAIN_H_
#define _MAIN_H_
#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
		char data;
		struct tree *pa;
		struct tree *lc;
		struct tree *rc;
}sTre,*pTre;
typedef struct link
{
		struct tree *tree_node;
		struct link *prev;
		struct link *next;
}sLink,*pLink;
typedef struct stack
{
		struct link *bottom;
		struct link *top;
}sSta,*pSta;
void mid(pSta ps,pTre p,pLink phead);
void create_tree(pTre *p);
void init_stack(pSta *p,pTre root,pLink phead);
void init_node(pTre *p);
void free_memory(void **p);
void create_memory(void **p,int size);
void push(pSta ps,pTre p,pLink phead);
void pop(pSta ps,pLink phead);
void init_link(pLink *p);
void pre(pSta ps,pTre p,pLink phead);
void last(pSta ps,pTre p,pLink phead);
#endif
