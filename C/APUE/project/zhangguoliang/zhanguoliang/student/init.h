#ifndef _INIT_H_
#define _INIT_H_

#include<stdlib.h>
#include"struct.h"

void init_sta(pStu *p);
void init_list(pList *p);

void sprint(pStu);
int sinput(pStu);
int IDFind(pStu pHead,pStu pnew);
pStu pHead;
int Insert(pStu,pStu,int(*)(pStu,pStu),pStu(*)(pStu,pStu));
int Del(pStu,pStu(*)(pStu,int));
void Print(pStu);
int Search(pStu,int (**)(pStu,int));
int Save(pStu,FILE*);


#endif
