#ifndef _SEARCH_H_
#define _SEARCH_H_
#include<stdio.h>
#include"struct.h"
void sprint(pStu);
void SEARCH(pStu,pList);
int Fun_Search2(pStu,int);
int Fun_Search1(pStu,int);
int Search(pStu,int (**)(pStu,int));

#endif
