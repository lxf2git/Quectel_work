#ifndef _INIT_H_
#define _INIT_H_
#include"total.h"
void getmemory(void **p,int size);
void init_Stu(pStu *p,int size);
void init_Node(pList p,int size);
void chain_del(pStu *pHead);
void destory(pStu del);

#endif
