#ifndef _MAIN_H_
#define _MAIN_H_

#include<stdio.h>
#include<stdlib.h>

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
	int (*pInsert)(pStu pHead,pStu Insert,int (*pINFind)(pStu pHead,pStu pInsert),pStu (*pInsertPosition)(pStu pHead,pStu pInsert));
	int (*pDel)(pStu pHead, pStu (*pDelPosition)(pStu pNode, int age));
	void (*pPrint)(pStu pHead);
	int (*pSearch)(pStu pHead,int (*pFun_Search[2])(pStu pHead, int num));
	int (*pStu_Save)(pStu pHead, FILE*fd);	
}sList, *pList;

enum 
{
	INSERT=1,
	DEL,
	SEARCH,
	PRINT,
	SAVE,
	EXIT
};

int menu(pStu pHead,FILE *fd);
#endif
