#ifndef _JOSEPH_H_
#define _JOSEPH_H_
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
typedef struct node
{
	int data;
	struct node *next;
}sNode,*pNode;

void init_node(pNode *p);
void creat_memory(pNode *p,int size);

void create_node_ring(pNode phead);
void insert_back(pNode phead , int n);

void free_node(pNode *p);
void kill_and_free(pNode *phead);
		
#endif
