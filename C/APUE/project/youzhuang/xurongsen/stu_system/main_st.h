#ifndef _MAIN_ST_H_
#define _MAIN_ST_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student
{
	int num;//学生的id
	int age;//学生的年龄
	struct Student *next;
	void (*stu_print)(struct Student *);//单个学生的输出函数
	int (*stu_input)(struct Student *);//单个学生的输入函数
}sStu,*pStu;

typedef struct List
{
	pStu phead;
//插入函数，
	int (*pInsert)(pStu phead,pStu pin,
					int (*pidfind)(pStu phead, pStu pin),//查找id是否存在
					pStu (*pinposite)(pStu phead,pStu pin));//查找插入的位置
	
//删除函数：按照符合年龄要求所有的数据删除
	int (*pDel)(pStu phead, pStu (*pdelsite)(pStu pnode, int age));
	//打印函数
	void (*pPrint)(pStu phead);
	//查找函数：id，age
	int (*pSearch)(pStu phead, int (*pfun_search[2])(pStu phead, int num));
	//保存函数 文件
	int (*pStu_Save)(pStu phead, FILE *fd);
}sList,*pList;

enum Type
{
	INSERT=1,
	DELETE,
	SEARCH,
	PRINT,
	SAVE,
	EXIT
	
};

enum Return
{
	FAILED=-1,
	SUC = 0
};

void interface();              //登录界面           
void sear_face();              //查找界面，按id或年龄
void choose(sList sFun,pStu pin);                 //选择登录
void judge(int n);
void print(pStu phead);


#endif
