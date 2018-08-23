#ifndef _FREE_H_
#define _FREE_H_

#include"main.h"

#define YES  2
#define NO  -2

int free_mem(pMem phead_app,pMem phead_free,pRec phead_rec);
pMem find_index(pMem phead,int x);
void delete_free(pMem pdel_free,pMem phead_app);
void i_free(void **p);
int destory(pRec phead_rec);
int judge(pRec phead_rec);
void free_free(pRec p);

#endif
