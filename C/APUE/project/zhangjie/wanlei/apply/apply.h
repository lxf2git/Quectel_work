#ifndef _APPLY_H_
#define _APPLY_H_

#include"main.h"
#define YES 1
#define NO  0

int apply_mem(pMem phead_app,pMem phead_free,pRec phead_rec);
int creat_apply_mem(pMem memory_phead,pMem free_phead,pRec rec_phead,int mem);
void delete_(pMem p,pMem phead_free);
pMem find_max_app(pMem phead);
pMem find_same(pMem phead,int size);


#endif
