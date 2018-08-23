#ifndef _TOTAL_H_
#define _TOTAL_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum comand
{
	INSERT=1,
	DEL,
	SEARCH,
	PRINT,
	SAVE,
	EXIT,
};

typedef struct Student 
{
	char name[10];
	int age;
	int id;
	struct Student *next;
	void (*stu_print)(struct Student *);
	int (*stu_input)(struct Student *);
}sStu,*pStu;
typedef struct list
{
	pStu pHead;
	int (*pInsert)(pStu pHead, pStu pInsert,
				int (*pIDFind)(pStu pHead, pStu pInsert), 
				pStu (*pInsertPosition)(pStu pHead, pStu pInsert) );
	int (*pDel)(pStu pHead, pStu (*pDelPosition)(pStu pNode, int age) );
	void (*pPrint)(pStu pHead);
	int (*pSearch)(pStu pHead, int (*pFun_Search[2])(pStu pHead, int num));
	int (*pStu_Save)(pStu pHead,FILE* fd);
}sList, *pList;


#endif
