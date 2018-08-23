#ifndef _MAIN_H_
#define _MAIN_H_

#include<stdio.h>
#include<stdlib.h>

enum {APPLY=1,FREE,PRINT,EXIT};

typedef struct memory
{
		int index;
		unsigned int mem_size;
		struct memory *prev;
		struct memory *next;
}sMem,*pMem;

typedef struct record
{
		pMem *pdata;
		struct record *prev;
		struct record *next; 
}sRec,*pRec;

pMem find_mem_index(pMem memory_phead,int num);
pMem find_max(pMem phead);
pMem find_equal(pMem phead,int mem);
void exchange(pMem dest,pMem node,pMem (*pfun)(pMem phead,pMem pnew));
void menu(pMem memory_phead,pMem free_phead,pRec rec_phead);
void print_(pMem memory_phead,pMem free_phead);
void free_(pMem memory_phead,pMem free_phead,pRec rec_phead);
void apply(pMem memory_phead,pMem free_phead,pRec rec_phead);
void create_memory(void **p,int size);
void free_memory(void **p);
void create_mem_node(pMem *p);
void create_rec_node(pRec *p);
void delete_mem_node(pMem p);
void delete_rec_node(pRec p);
pMem find_size_insert(pMem phead,pMem pnew);
pMem find_index_insert(pMem phead,pMem pnew);
void insert_mem_chain(pMem phead,pMem (*pfun)(pMem phead,pMem pnew),pMem pnew);
void create_mem_chain(pMem phead);
void output_mem_chain(pMem phead);
void create_rec_chain(pRec phead);
void unload_mem_chain(pMem *phead);
void unload_rec_chain(pRec *phead);
#endif
