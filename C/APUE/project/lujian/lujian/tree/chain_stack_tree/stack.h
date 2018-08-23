
#ifndef STACK_H
#define  STACK_H

#include<stdio.h> 
#include<stdlib.h>

#define  EMPTY  (0)
#define  FALSE  (-1) 
#define  TURE   (1) 

typedef struct Tree
{
	char data;
	struct Tree* lc;
	struct Tree* rc;
}Stree, *Ptree;

typedef struct Node
{	
	Ptree data;
	struct Node *prev;
	struct Node *next;

}Snode, *Pnode;

typedef struct Stack
{
	Pnode bottom;
	Pnode top;

}Ssta, *Psta;

int myfree(Pnode* pdel);
int delete_back(Pnode pos);
int pop(Psta ps, Ptree* pop_data);
int add_back(Pnode pos, Pnode pin);
int push(Psta ps, Ptree tr_node);
int creat_memory(void** q, int size);
static int init_node(Pnode* psnode);
int init_stack(Psta ps);

#endif 


