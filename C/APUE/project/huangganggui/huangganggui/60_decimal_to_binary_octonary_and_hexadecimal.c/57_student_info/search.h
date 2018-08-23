#ifndef _SEARCH_H
#define _SEARCH_H
#include"main.h"
int search_by_age_print(pStu pHead,int num);
int search_by_id_print(pStu pHead,int num);
int search(pStu pHead, int (*pFun_Search[2])(pStu pHead,int num));

#endif
