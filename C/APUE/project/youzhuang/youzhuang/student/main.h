#ifndef MAIN_H
#define MAIN_H
#include<stdio.h>
#include"struct.h"
void insert(pStu pHead);
enum {INSERT=1,DEL,SEARCH,PRINT,SAVE,EXIT};
int menu();
int judge(int function,pStu pHead);
void create_memory(pStu *p);
void init(pStu pHead);
pStu create_node();
#endif
