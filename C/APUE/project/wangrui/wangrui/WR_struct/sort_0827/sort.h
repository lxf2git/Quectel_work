#ifndef _SORT_H_
#define _SORT_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}sNode,*pNode;

typedef struct chain
{
	pNode record;
	struct chain *next;
	struct chain *prev;
}sChain,*pChain;

//main
void init_node(pNode *pnode,int size);
void init_chain(pChain *pnode,int size);
void creat_memory(void **p,int size);

void creat_chain(pNode pHead);
void creat_chain_chain(pChain pFrist);
void insert_back(pNode pHead,pNode pnew);

void show_chain(pNode pHead);
void show_chain_chain(pChain pFrist);

//judge
int judge_num(pNode pHead);
int judge_deal(int n);


void distribute(pNode pHead,pChain pFrist,int num,int i);
int deal_data(int a,int n,int i);
int deal_num(int n);
void insert_node(pChain pFrist,int num,pNode pIn);
pNode head_des(pNode pHead,pNode ptmp);
void collected(pNode pHead,pChain pFrist);


#endif
