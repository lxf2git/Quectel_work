#ifndef _INIT_H_
#define _INIT_H_
#include<stdio.h>
#include<stdlib.h>
#include"struct.h"
#include"save.h"
void chain_init(pStu *p);
void create_memory(pStu *p,int size);
void findtiall(pStu *p_pro);
void myfree(pStu *p);
void list_init(pList *p);
void init_file(pStu pHead,pList plist);
#endif
