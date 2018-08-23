#ifndef _MAIN_H_
#define _MAIN_H_
#include<stdio.h>
#include"struct.h"
enum { CREATE=1,DELETE,PRINT,EXIT=0};
void create(pTree);
void init_tree(pTree *);
void print(pTree);
void delete_Node(pTree);

#endif
