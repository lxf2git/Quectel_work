#ifndef _STRUCT_H_
#define _STRUCT_H_
#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
		int id;
		int age;
		struct student *next;
		void (*stu_print)(struct student *);
		int (*stu_input)(struct student *);
}sStu,*pStu;
typedef int (*pIDFind)(pStu pHead, pStu pInsert);
typedef pStu (*pInsertp)(pStu pHead, pStu pInsert);
typedef pStu (*pDelp)(pStu pNode, int age);
typedef int (*pFun_Search[2])(pStu pHead, int num);
typedef struct list
{
		pStu head;
		int (*pInsert)(pStu , pStu , pIDFind, pInsertp );
		int (*pDel)(pStu  , pDelp);
		void (*pPrint)(pStu );
		int (*pSearch)(pStu  , pFun_Search);
		int(*pStu_Save)(pStu ,FILE*);

}sList,*pList;
enum en_name
{
		INPUT=1,
		DEL,
		SEARCH,
		PRINTF,
		SAVE,
		EXIT,

};
#endif
