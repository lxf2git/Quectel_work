#ifndef _DEL_H_
#define _DEL_H_

#include"main.h"

pStu pdel(pStu pNode,int age);
int delet(pStu pHead,pStu(*pDelPosition)(pStu pNode,int age));
void Del(sList slist,pStu pHead);

#endif
