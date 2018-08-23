#ifndef _DEL_H_
#define _DEL_H_

#include"main.h"

int pDel(pStu pHead,pStu (*pdelp)(pStu,int));
pStu pdelp(pStu pHead,int age);
#endif
