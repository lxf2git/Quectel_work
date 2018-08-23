#ifndef _INIT_H_
#define _INIT_H_
#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	int num;
	int age;
	struct student *next;
	void (*stu_printf)(struct student *);
	int(*stu_input)(struct student *);
}sStu,*pStu;

typedef struct list
{
	pStu head;//学生链表头
	int (*pInsert)(pStu pHead,pStu pInsert,
									int(*pIDFind)(pStu pHead,pStu pInsert),pStu(*pInsertPosition)(pStu pHead,pStu pInsert));//插入函数 参数查找插入id是否重复 找到待插入地址
	int (*pDel)(pStu pHead,pStu(*pDelPosition)(pStu pNode,int age));//删除函数 确定删除地点
	void (*pPrint)(pStu phead);//打印链表函数
	int (*pSearch)(pStu pHead,int (*pFun_Search[2])(pStu pHead,int num));//查找函数 按年龄 id两种方式
	int (*pStu_Save)(pStu pHead,FILE *fd);
}sList,*pList;
void creat_memory(pStu *p);
void init_memory(pStu *p);
void init_memory_list(pList *p);

#endif
