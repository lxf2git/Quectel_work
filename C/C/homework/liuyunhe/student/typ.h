#ifndef _TYP_H_
#define _TYP_H_

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
		pStu pHead;

		int (*pInsert)(pStu pHead,pStu pInsert,
						int (*pIDFind)(pStu pHead,pStu pInsert),
					pStu (*pInsertPosition)(pStu pHead, pStu pInsertty));
		int (*pDel)(pStu pHead, pStu (*pDelPosition)(pStu pNode, int age) );
		void (*pPrint)(pStu pHead);
		int (*pSearch)(pStu pHead,
						int (*pFun_Search[2])(pStu pHead, int num));
		int (*pStu_Save)(pStu pHead, FILE*fd);

}sList, *pList;
#endif
