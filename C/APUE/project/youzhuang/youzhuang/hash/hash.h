#ifndef _HASH_H_
#define _HASH_H_
#include<stdio.h>
#include<stdlib.h>
typedef struct data
{
		int data;
		struct data *prev;
		struct data *next;
}sData,*pData;
typedef struct and_
{
		struct data *and_[8];
}sAnd,*pAnd;
typedef struct mod
{
		struct and_ *mod[5];
}sMod,*pMod;

void create_node(pData *p);
void create_memory(void **p,int size);
void create_hash(pMod mod_5);
void insert_node(pData phead, pData pnew);
void output(pData phead);
void print(pMod mod_5);
void create_hash(pMod mod_5);
void find(pMod mod_5);
#endif
