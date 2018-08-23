#ifndef MAIN_H_
#define MAIN_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
		int (*pInsert)(pStu pHead,pStu pInsert,int (*pIDFind)(pStu pHead,pStu pInsert),pStu (*pInsertPosition)(pStu pHead,pStu pInsert));
		int (*pDel)(pStu pHead,pStu(*pDelPostion)(pStu pNode,int age));
		void (*pPrint)(pStu pHead);
		int (*pSearch)(pStu pHead,int (*pFun_Search[2])(pStu pHead,int num));
		int (*pStu_Save)(pStu pHead,FILE *fd);
}sList,*pList;
#include"insert.h"
#include"del.h"
#include"search.h"
#include"save.h"
#include"init.h"
int Insert(pList ppp);
int Del(pList ppp);
int Search(pList ppp);
int Print(pList ppp);
int Save(pList ppp);
#endif
