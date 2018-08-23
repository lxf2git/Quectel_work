#ifndef _MAIN_H_
#define _MAIN_H_
#include<stdio.h>
#include<stdlib.h>
#define NUM 1
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
	int (*pInsert)(pStu pHead,pStu pInserT,int (*pIDFind)(pStu pHead,
	  pStu pInsert),pStu (*pInsertPosition)(pStu pHead,pStu pInsert));
	int (*pDel)(pStu phead,pStu (*pDelPosition)(pStu pNode, int age));
	void (*pPrint)(pStu pHead);
	int (*pSearch)(pStu pHead,int (*pFun_Search[2])(pStu pHead,int num));
	int (*pStu_Save)(pStu pHead,FILE *fd);
}sList,*pList;
enum function
{
	INSERT=1,
	DEL,
	SEARCH,
	PRINT,
	SAVE,
	EXIT,
};
#include"init.h"
#include"insert.h"
#include"del.h"
#include"search.h"
#include"print.h"
#include"save.h"
void read_file(pStu phead,FILE *fp);
#endif 
