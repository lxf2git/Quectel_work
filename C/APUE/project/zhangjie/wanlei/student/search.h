#ifndef _SEARCH_H_
#define _SEARCH_H_

#include"main.h"

int pSearch(pStu pHead,int (*pFun[2])(pStu ,int));
int find_id(pStu pHead,int id);
int find_age(pStu pHead,int age);

#endif
