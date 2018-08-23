#ifndef _DEL_H_
#define _DEL_H_
#include"total.h"
void del(pStu pHead,sList slist);
pStu catch_1(pStu pHead, int age);
int del_1(pStu pHead, pStu (*pDelPosition)(pStu pHead, int age));

#endif
