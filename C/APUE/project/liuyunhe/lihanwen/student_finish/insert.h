#ifndef _INSERT_H_
#define _INSERT_H_
#include<stdio.h>
#include"init.h"

int id_find(pStu pHead,pStu p_stu_new);
int _Insert(pStu pHead,pStu pInsert,int(*pIDFind)(pStu pHead,pStu pInsert),pStu (*pInsertPosition)(pStu pHead,pStu pInsert));
int input(pStu p_stu_new);
void s_insert(pStu pHead);

#endif

