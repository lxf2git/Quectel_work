#ifndef _SEARCH_H_
#define _SEARCH_H_
#include"total.h"
void pFun_Search(pStu pHead,sList slist);
int search_age(pStu pHead,int num);
int search_id(pStu pHead,int num);
int search(pStu pHead, int (*pFun_Search[2])(pStu pHead, int num));



#endif
