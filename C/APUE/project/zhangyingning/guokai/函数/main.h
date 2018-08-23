#ifndef _MAIN_H_
#define _MAIN_H_
#include<stdio.h> 
#include<stdlib.h> 
typedef struct student
{
	int id;
	int age;
	struct student *next;
//	void (*stu_print)(struct student *);
//	int (*stu_input)(struct student *);
}sStu,*pStu;

typedef struct list
{
	 pStu head;
	 int (*pInsert)(pStu pHead,pStu pInsert,int(*pINDFind)(pStu pHead,pStu pInsert),
					 pStu(*pInsertPosition)(pStu pHead,pStu pInsert));
	 int (*pDel)(pStu pHead, pStu (*pDelPosition)(pStu pHead, int age));
	 void (*pPrint)(pStu pHead);
	 int (*pSearch)(pStu pHead,int (*pFun_Search[2])(pStu pHead, int num));
	 int (*pStu_Save)(pStu pHead, FILE *fp);		 
}sList,*pList;
/*
#include"init.h" 
#include"insert.h"
#include"save.h"
#include"del.h"
#include"print.h"
#include"search.h"
*/
#endif
