#ifndef _APPLY_H_
#define _APPLY_H_
#include"init.h"
#include<stdio.h>
#include"print.h"
int find_max(pMem pHead);
int same(int size,pMem pHead);
int sam_index(pMem ptmp,pMem pFree);
void insert(pMem ptmp,pMem pFree);
void insertc(pMem ptmp,pMem pFree);
void m_apply(pMem pApply,pMem pFree);

#endif
