#ifndef _STUDENT_H_
#define _STUDENT_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct student
{
	int num;
	int age;
	struct student *next;
	void (*pstu_print)(struct student *);
	int (*pstu_input)(struct student *);
}sStu,*pStu;
typedef struct list
{
	pStu head;
	int (*pInsert)(
			pStu pHead,
			pStu pInsert,
			int (*pIDFind)(pStu pHead,
							pStu pInsert),
			pStu (*pInsertPosition)(pStu pHead,
									pStu pInsert)
			);
	int (*pDel)(
			pStu pHead,
			pStu (*pDelPosition)(pStu pNode,int age)
			);
	void (*pPrint)(pStu pHead);
	int (*pSearch)(
				pStu pHead,
				int (*pFun_Search[2])(pStu pHead,
									  int num)
				);
	int (*pStu_Save)(pStu pHead,FILE*fd);
}sList,*pList;

//init_free
void Init_Stu(pStu *p);
void creat_memory(pStu *p,int size); 
void Exit(pStu *pHead);
void Destory_Stu(pStu *p);

//load
int Stu_Load(pStu pHead,FILE *fp);
void Load_read(pStu pHead,FILE *fp);

//main
int Menu();
void Judge(int sus);

//insert
pStu input();
int stu_input(struct student *pIn);
int Insert(pStu pHead,pStu pIn,
				int (*pIDFind)(pStu,pStu),
				pStu (*pInsertPosition)(pStu,pStu));
pStu InsertPos(pStu pHead,pStu pIn);
int IDFind(pStu pHead,pStu pIn);

//delete
int Del(pStu pHead,pStu (*pDelPosition)(pStu,int));
pStu DelPos(pStu pHead,int years);

//searcha
int Search(pStu pHead,
				int (*pFun_Search[2])(pStu,int));
int Age_Search(pStu,int);
int ID_Search(pStu,int);
int (*Fun_Search[2])(pStu,int);


//print
void Print(pStu pHead);
void stu_print(pStu ps);

//save
int Stu_Save(pStu pHead,FILE *fp);
void Save_write(pStu pHead ,FILE *fp);

#endif
