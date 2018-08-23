#ifndef _INIT_H_
#define _INIT_H_

#include<stdio.h>
#include<stdlib.h>
#include "main.h"
void getmemory(void **p,int size);
void prepare(pStu *p,int size);
int change(pStu pOs,pStu pIn);
void load(pStu p);
int create(pStu p,pList q);
void free_m(pStu *p);



#endif
