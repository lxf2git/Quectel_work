#ifndef _SEARCH_H_
#define _SEARCH_H_
#include"main.h"
int find(pStu pHead,int (*pFun_Search[2])(pStu pHead, int num));
int(*pFun_Search[2])(pStu pHead, int num);
#endif
