
#ifndef CHAIN_QUEUE_H
#define  CHAIN_QUEUE_H

#include<stdio.h> 
#include<stdlib.h>

#define  TURE   (1) 
#define  FALSE  (-1) 
#define  EMPTY   (0)

typedef struct Tree
{
	char data;

	struct Tree* lc;

	struct Tree* rc;
}Stree, *Ptree;

typedef struct Node
{
	Ptree data;
	
	struct Node* prev;
	
	struct Node* next;
	
}Snode, *Pnode;


int init_queue(Pnode phead);

int creat_memory(void** q, int size);

int enqueue(Pnode phead, Ptree en_data); //想当与尾插

int dequeue(Pnode phead, Ptree* de_data); // 想当与 头删

int judge_queue(Pnode phead);
int myfree(Pnode* pdel);
int delete_back(Pnode pos);
int add_back(Pnode pos, Pnode pin);

#endif 






