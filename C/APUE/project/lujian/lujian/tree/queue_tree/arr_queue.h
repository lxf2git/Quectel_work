
#ifndef ARR_QUEUE_H
#define  ARR_QUEUE_H

#include<stdio.h> 
#include<stdlib.h>
#define  SIZE   (100)
#define  EMPTY (0)
#define  FULL   (1)
#define  TURE   (1) 
#define  FALSE  (-1) 

typedef struct Tree
{
	char data;	
	
	struct Tree* lc;

	struct Tree* rc;
}Stree, *Ptree;

typedef struct Queue
{

	Ptree arr[SIZE];

	int pw;

	int pr;

}Squeue, *Pqueue;

int init_queue(Pqueue pque);
int push_queue(Pqueue pque, Ptree pnode);
int pop_queue(Pqueue pque, Ptree* pop_pnode);
int judge_queue(Pqueue pque);


#endif 

