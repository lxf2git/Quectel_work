#ifndef _MAIN_H
#define _MAIN_H
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
		int data;
		struct node *prev;
		struct node *next;
}sNode,*pNode;

typedef struct and_
{
		struct node * and_[8];
}sAnd,*pAnd;
typedef struct mod
{
		struct and_*mod[5];
}sMod,*pMod;
void menu(pMod pClass);
void mod_init(pMod *p);
void and_init(pAnd *p);
void chain_init(pNode *p);
void create_memory(void**p,int size);
void create_chain(pMod pClass);
void insert_chain(pNode pHead,pNode pInsert);
void find_number(pMod pClass);
void find_fun(pNode pHead,int number);
void output(pNode pHead);
void deal_mod(pMod pClass,void (*p)(pNode pHead));
void myfree(pNode pHead);
#endif
