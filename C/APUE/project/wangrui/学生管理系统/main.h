#ifndef _MAIN_H_
#define _MAIN_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"insert.h"
#include"init.h"
#include"del.h"
#include"save.h"
#include"search.h"


typedef struct student
{
	int num;
	int age;
	struct student *next;
	void (*stu_print)(struct student *);
	int (*stu_input)(struct student *);
}sStu,*pStu;

typedef struct list
{
	pStu head;
	int (*pInsert)(pStu pHead,pStu pIn,
					int (*pIDFind)(pStu pHead,pStu pIn),
					pStu (*pInsertPosition)(pStu pHead,pStu pIn));
	int (*pDel)(pStu pHead,pStu (*pDelPosition)(pStu pNode,int age));
	void (*pPrint)(pStu pHead);
	int (*pSearch)(pStu pHead,int (*pFun_Search[2])(pStu pHead,int n));
	int (*pStu_Save)(pStu pHead,FILE*fd);
}sList,*pList;


pStu (*pDelPosition)(pStu pNode,int age);
int (*pFun_Search[2])(pStu pHead,int n);
pStu (*pInsertposition)(pStu pHead,pStu pnew);
int (*pIDFind)(pStu pHead,pStu pnew);
int pStu_Save(pStu pHead,FILE*fd);
int pSearch(pStu pHead,int (*pFun_Search[2])(pStu pHead,int num));
int pDel(pStu pHead,pStu (*pDelPosition)(pStu pNode,int age));
int pInsert(pStu pHead,pStu pIn,int (*pIDFind)(pStu pHead,pStu pIn),pStu (*pInsertPosition)(pStu pHead,pStu pIn)); 
void stu_print(struct student *);
int stu_input(struct student *);
void del_chain(pStu pHead);
void search_chain(pStu pHead);
void pPrint(pStu pHead);
void save_chain(pStu pHead);
#endif
