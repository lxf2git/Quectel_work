#ifndef _INSERT_H_
#define _INSERT_H_

#include"main.h"

int pInsert(pStu pHead,pStu pnew,int (*pIDFind)(pStu,pStu),
				pStu (*pInsertPosition)(pStu,pStu));
int pidfind(pStu pHead,pStu pnew);
pStu pinsertposition(pStu pHead,pStu pnew);
int insert_back(pStu p1,pStu p2);
void init_stu(pStu *p,int size);
int stu_input(pStu pnew);
int file_chain_insert(pStu pHead,FILE *fd);

#endif
