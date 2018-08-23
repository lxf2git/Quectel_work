#ifndef _INIT_H
#define _INIT_H
#include<stdio.h>
#include<stdlib.h>

#include"main.h"

void init_node(pStu *);
void create_memory(void **, int);
void insert_behind(pStu pPosition,pStu pnew);
pStu find_bigger_position(pStu pHead,pStu pNew);

#endif
