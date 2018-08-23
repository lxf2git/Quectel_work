#ifndef _BASE_SORT_H_
#define _BASE_SORT_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 4
typedef struct Stu
{
	int data;
	struct Stu *prev;
	struct Stu *next;
}sSt,*pSt;

typedef struct Chain
{
	pSt record;
	struct Chain *prev;
	struct Chain *next;
}sChain,*pChain;


//init.c
void create_memory(void **p,int size);
void create_chain(pSt phead);
void create_chain_chain(pChain pFh);
void free_memory(void **p);
void init_node(pSt *pnode,int size);
void init_chain(pChain *pnode,int size);
void insert_back_head(pSt phead, pSt pnew);
void show_chain(pSt phead);
//---------------------------------
void distribute(pChain pFh,pSt phead,int num,int n);
pSt head_del(pSt phead,pSt pnode);
void insert_back(pChain pFh,int m,pSt pnode);
void insert_back_node(pSt phead,pSt pnode);
int deal_num(int data,int num, int n);
int deal_n(int n);
int judge_num(pSt phead);
int count(int data);
void collect(pChain pFh,pSt phead);
#endif
