#ifndef DEL_H_
#define  DEL_H_
#include "main.h"
pStu DelPosition(pStu pNode,int age);
void destory_chain(pStu ppdel);
int del(pStu pHead,pStu(*pDelPosition)(pStu pNode,int age));
//void print(pStu pHead);
//int Del(pList ppp);
#endif
