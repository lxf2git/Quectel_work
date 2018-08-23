#ifndef _SEARCH_H_
#define _SEARCH_H_
#include"main.h"

int Fun_search_id(pStu pHead,int id);
int Fun_search_age(pStu pHead,int age);
int search(pStu pHead,int (*pFun_Search[2])(pStu pHead,int num));
void s_search(pStu phead);

#endif

