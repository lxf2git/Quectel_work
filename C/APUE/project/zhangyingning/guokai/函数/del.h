#ifndef _DEL_H_
#define _DEL_H_
#include"main.h"
int del_age(pStu pHead, pStu(*pDelPosition)(pStu pHead,int age));
pStu (*pDelPosition)(pStu pNode, int age);
#endif
