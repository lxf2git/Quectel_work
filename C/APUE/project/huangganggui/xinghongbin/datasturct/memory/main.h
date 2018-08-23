#ifndef _MAIN_H
#define _MAIN_H
#include<stdlib.h>
#include<stdio.h>
typedef struct Memory
{
		int index;
		int size;
		struct Memory *next;
		struct Memory *prev;
}sMem,*pMem;
typedef struct Record
{
		struct Memory *pdata;
		struct Record *next;
		struct Record *prev;
}*pRec,sRec;
void Meun(pMem pApply,pMem pFree,pRec *pFreenumber);
void free_init(pRec*p,int size);
void chain_init(pMem *p,int size);
void create_memory(pMem *p,int size);
void create_apply(pMem pHead);
void Insert_chain(pMem pHead,pMem pInsert);
void delete_chain(pMem pHead,pMem pDel);
void connect_free(pMem pHead,pMem pInsert);
void chain_freehead(pRec pHead,pMem pFree,pMem pApply);
void record_freechain(pRec pHead,pMem pInsert);
void separate_memory(pMem pHead,pRec pFhead,pMem pFree);
pMem deal_memory(pMem pHead,int size);
void output(pMem pHead);
void output_rec(pRec phead);
void free_arr(pRec *p,int size);
void freefree(pRec *p,pMem pHead,pMem pFree);
void delete_free(pRec pHead,pRec pDel,pRec prev);
#endif		
