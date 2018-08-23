#ifndef INSERT_H
#define INSERT_H
#include<stdio.h>
#include"struct.h"
int intsert_node(pStu pHead, pStu pInsert,int (*pIDFind)(pStu pHead, pStu pInsert),pStu (*pInsertPosition)(pStu pHead, pStu pInsert) );
int idfind(pStu pHead,pStu pInsert);
pStu insertposition(pStu pHead,pStu pInsert);
pStu create_node();
void free_memory(pStu *p);
#endif
