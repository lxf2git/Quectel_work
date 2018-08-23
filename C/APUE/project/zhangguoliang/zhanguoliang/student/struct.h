#ifndef _STRUCT_H_
#define _STRUCT_H_
#include<stdio.h>

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
	pStu Head;
	int (*pInsert)(pStu pHead,pStu pInsert,int (*pINFind)(pStu pHead,pStu pInsert),pStu(*pInsertPosition)(pStu pHead,pStu pInsert));
	int (*pDel)(pStu pHead,pStu(*pDelPosition)(pStu pNode,int age));
	void (*pPrint)(pStu pHead);
	int (*pSearch)(pStu pHead,int(**pFun_Search)(pStu pHead,int num));
	int (*pStu_Save)(pStu pHead,FILE*fd);
}sList,*pList;

#endif
