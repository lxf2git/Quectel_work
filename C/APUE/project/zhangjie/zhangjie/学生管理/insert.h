#ifndef _INSERT_H_
#define _INSERT_H_

#include<stdio.h>
#include"main.h"

int find(pStu p,pStu pn);
pStu max(pStu p,pStu pn);
int insert(pStu p,pStu pn,int (*pIDFind)(pStu pHead,pStu pInsert),pStu (*pInsertPosition)(pStu pHead,pStu pInsert));
int stu_inp(pStu p);
void stu_pri(pStu p);

#endif
