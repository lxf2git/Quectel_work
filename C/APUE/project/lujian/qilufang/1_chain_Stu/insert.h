#ifndef _INSERT_H_
#define _INSERT_H_
#include"total.h"
#include"init.h"
pStu loction(pStu pHead,pStu pnew);
int insert_back(pStu pHead,pStu pNew,int (*pIDfind)(pStu pHead,pStu pNew),
			pStu (*pInsertPosition)(pStu pHead,pStu pNew));
int id_find(pStu pHead,pStu pnew);
int make_chain(pStu pnew);
void insert(pStu pHead,sList slist);

#endif
