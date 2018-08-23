#ifndef _INSERT_H_
#define _INSERT_H_

#include"main.h"

void creat_memory(void **p,int size);
void init_memory(pMem *p,int size);
void init_rec(pRec *p,int size);
void creat_chain(pMem phead,int x);
int  insert_(pMem p1,pMem p2);
void show(pMem phead);
int  insert_free(pMem phead,pMem pnew);
pMem find_max(pMem phead,pMem pnew);
pMem find_index_max(pMem phead,pMem pnew);
int  all_size(pMem phead);
int insert_apply(pMem phead,pMem pnew);
int insert_cent(pMem p1,pMem p2);
int insert_rec(pRec p1,pRec p2);

#endif
