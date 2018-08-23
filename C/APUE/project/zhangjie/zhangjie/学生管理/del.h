#ifndef _DEL_H_
#define _DEL_H_


#include "main.h"
void del(pStu p);
int del2(pStu p,pStu (*pDelPosition)(pStu pNode,int age));
pStu del3(pStu p,int n);

#endif
