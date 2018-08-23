#ifndef _INSERT_H_
#define _INSERT_H_

#include"main.h"

int find(pStu pHead,pStu pInsert);
pStu max_(pStu pHead,pStu pInsert);
int stuinput(pStu p);
void Insert(sList slist,pStu pHead);
int insert_w(pStu pHead,pStu pInsert,
			int (*pIDFind)(pStu pHead,pStu pInsert),
			pStu (*pInsertPosition)(pStu pHead,pStu pInsert));

#endif
