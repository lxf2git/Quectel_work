#ifndef _INSERT_H_
#define _INSERT_H_
#include"main.h"
int max(pStu phead,pStu pInsert,int(*pIDFind)(pStu phead, pStu pInsert),
						pStu (*pInsertPosition)(pStu phead,pStu pInsert));
int(*pIDFind)(pStu phead, pStu pInsert);
pStu (*pInsertPosition)(pStu phead,pStu pInsert);
#endif
