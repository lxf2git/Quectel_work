#ifndef _INSERT_H_
#define _INSERT_H_
#include"main.h"
#include"init.h"
#define TURE 0
#define EXIST 1
int Idfind(pStu phead,pStu pInsert);
pStu InsertPosition(pStu pHead,pStu pInsert);
int Insert(pStu phead,pStu pInsert,int (*pIDFind)(pStu pHead,pStu pInsert),pStu(*pInsertPosition)(pStu pHead,pStu pInsert));
#endif
