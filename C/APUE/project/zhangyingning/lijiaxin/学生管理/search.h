#ifndef  SEARCH_H_
#define  SEARCH_H_
#include"main.h"
int fun_ID(pStu pHead,int num);
int fun_AGE(pStu pHead,int age);
int search_(pStu pHead,int (*pFun_search[2])(pStu pHead,int num));
#endif
