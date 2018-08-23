#ifndef INIT_H
#define INIT_H
#include<stdlib.h>
#include<stdio.h>
#include"struct.h"
int insert_node(pStu pHead, pStu pInsert,int (*pIDFind)(pStu pHead, pStu pInsert),pStu (*pInsertPosition)(pStu pHead, pStu pInsert) );
int del_node(pStu pHead,pStu(*pDelPosition)(pStu pNode,int age));
int find(pStu pHead,int (*pFun_Search[2])(pStu pHead, int num));
void print(pStu pHead);
int save_stu(pStu pHead, FILE*fd);
int input_stu(pStu p);
void print_stu(pStu pHead);
void create_memory(pStu *p);
void loading(pStu pHead);
int idfind(pStu pHead,pStu pInsert);
pStu insertposition(pStu pHead,pStu pInsert);
void free_memory(pStu *p);
#endif
