#ifndef _DEL_H_
#define _DEL_H_
#include"main.h"
#include"init.h"
pStu DelPosition(pStu pNode,int age);
void del_(pStu p_Del);
int Del(pStu pHead,pStu (*pDelPosition)(pStu pnode,int age));
void s_del(pStu pHead);

#endif
