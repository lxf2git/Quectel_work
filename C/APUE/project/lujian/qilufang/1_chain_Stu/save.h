#ifndef _SAVE_H_
#define _SAVE_H_
#include"total.h"
void output(pStu stmp);
void save_pStu(pStu pHead,sList slist);
void put_chain(pStu pHead);
int save(pStu pHead,FILE *fp);
void print(pStu pHead,sList slist);
#endif
