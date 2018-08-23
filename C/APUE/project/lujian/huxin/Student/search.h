#ifndef _SEARCH_H_
#define _SEARCH_H_
#include"main.h"
int Search(pStu phead,int(*pFun_Search[2])(pStu pHead,int num));
int Search_id(pStu phead,int num);
int Search_age(pStu phead,int age);
#endif
