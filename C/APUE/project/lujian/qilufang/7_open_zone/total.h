#ifndef _TOTAL_H_
#define _TOTAL_H_
#include<stdio.h>
#include<stdlib.h>
#define N 10
enum Node
{
	APPLY=1,
	FREE,
	PRINT,
	EXIT,
	ALLPUT,
};
typedef struct memory
{
	int index;
	unsigned int mem_size;
   struct memory *prev;
	struct memory *next;   
}sMem,*pMem;
typedef struct record
{
	pMem pdata;
	struct record *prev;
	struct record *next;
}sRec,*pRec;
void init_chain(pMem *p,int size);
void getmemory(void **p,int size);
void init_chain_rec(pRec *p,int size);
void chain_back(pMem pHead,pMem pnew);
void output(pMem pHead);
void all_mem(pMem *pHead);
void destory(pMem *p);
void chain_back_rec(pRec pnew,pRec pHead_rec);
void output_rec(pRec pHead);
void change(pMem del,pMem pnew);
void destory_rec(pRec *p);
#endif
