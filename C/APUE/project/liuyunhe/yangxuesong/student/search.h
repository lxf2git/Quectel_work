#ifndef _SEARCH_H_
#define _SEARCH_H_

#include"main.h"

int mun(pStu pHead,int num);
int age(pStu pHead,int num);
int psearch(pStu pHead,int(*pFun_Search[2])(pStu pHead,int num));
void Search(sList slist,pStu pHead);

#endif
