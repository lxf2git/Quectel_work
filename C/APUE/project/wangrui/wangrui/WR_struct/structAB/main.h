#ifndef _MAIN_H_
#define _MAIN_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 5
typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}sNode,*pNode;


void show_chain(pNode pHead);

void init_node(pNode *pnode);
void creat_memory(pNode *p);
void creat_chain(pNode pHead);
void free_node(pNode *p);


void deal_chain(pNode pHeadA,pNode pHeadB);
int Destory_node(pNode pPos,pNode *pdel);



#endif
