#ifndef _STUSYS_H_
#define _STUSYS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FAIL 0
#define SUCCESS 1
#define FIND 1
#define NOFIND 2
#define EXIST 1
#define SIZE_CHAR 1024

typedef struct student
{
	unsigned int num;
	int age;
	struct student *next;
	void (*pStu_print)(struct student *);
	void (*pStu_input)(struct student *);
}sStu, *pStu;


typedef struct list
{
	pStu head;

	int (*pFun_stu[6])(struct list *pStusys);

	int (*pIDFind)(pStu pHead, unsigned int num);
	pStu (*pInsertPosition)(pStu pHead, pStu InsertNode);
//	int (*pInsert)(struct list *pStusys);

	pStu (*pDelPosition)(pStu pHead, unsigned int num);
//	int (*pDel)(struct list *pStusys);
	
	int (*pFun_search[2])(pStu pHead);
	int (*pSearch)(struct list *pStusys);

//	int (*pPrint)(struct list *pStusys);

	int (*pSave)(struct list *pStusys);
	int (*pLoad)(struct list *pStusys);

//	int (*pQuit)(struct list *pStusys);

}sList, *pList;


void get_memory(void **, void **);
int create_memory(void **, unsigned int);
void init(pList);

int interface();

void Stu_input(pStu);
void Stu_print(pStu);

int IDFind(pStu, unsigned int);
pStu InsertPosition(pStu, pStu);
int Insert(pList);


int Del(pList);
pStu DelPosition(pStu, unsigned int);

int num_search(pStu);
int age_search(pStu);
int Search(pList);

int Save(pList);
int Load(pList);

int Print(pList);

int Quit(pList);
#endif
