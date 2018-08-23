#ifndef _MAIN_H_
#define _MAIN_H_
#include<stdio.h>
#include"struct.h"

enum {APPLY=1,PRINT,FREE,EXIT=0};
void init_node(pMem *);
void init_Memory(pMem);
void show_chain(pMem);
void init_Rnode(pRc*);
void init_Node(pMem *,int,int);
void apply(pMem,pMem,pRc);
void Free(pMem,pMem,pRc);
void clean_data(pMem,pMem,pRc);

#endif

