#ifndef _DEL_H_
#define _DEL_H_
#define ZERO 0
#include"main.h"
void my_free(pStu *p);
void delete_list(pStu pdel);
pStu DelPosition(pStu pNode,int age);
int Delete(pStu phead,pStu (*pDelPosition)(pStu pNode,int age));
#endif
