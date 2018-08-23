#ifndef MAIN_H_
#define MAIN_H_
typedef struct node
{
		int index;
		unsigned int mem_size;
		struct node *prev;
		struct node *next;
}sNode,*pNode;
typedef struct record
{
		pNode pdata;
		struct record *prev;
		struct record *next;
}sRecord,*pRecord;
#include<stdio.h>
#include<stdlib.h>
#define N 100
void get_memory(void **q,int size);
void my_free(void **qq);
int count;
pNode free_begin;
pRecord ppp[N];
void init (pNode *pHead,int size);

#endif
