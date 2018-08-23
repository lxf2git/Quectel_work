#ifndef _HASH_H_
#define _HASH_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 7

typedef struct data
{
	int data;
	struct data *prev;
	struct data *next;
}sData,*pData;
typedef struct  _and
{
	struct data *_and[8];
}sAnd,*pAnd;
typedef struct mod
{
	struct _and *mod[5];
}sMod,*pMod;


void show_chain(pData phead);
void creat_memory(void **p,int size);
void init_node(pData *pnode);
void creat_org_chain(pData phead);
void insert_back(pData phead,pData pnew);
void init_mod(pMod *pmod);

void creat_hash_list(pData phead);
void search_data(pMod pmod);

#endif
