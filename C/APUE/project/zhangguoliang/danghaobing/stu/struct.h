#ifndef _STRUCT_H_
#define _STRUCT_H_

typedef struct student
{
	int num;//学生ID
	int age;//学生年龄
	struct student *next;
	void (*stu_print)(struct student *);//单个学生的输出函数
	int (*stu_input)(struct student *);//单个学生的输入函数
}sStu,*pStu;

typedef struct list
{
		pStu head;//学生链表头结点
//插入函数的参数：pIDFind:查找插入的ID是否已经存在
//pInsertPosition:查找插入结点的位置
		int (*pInsert)(pStu pHead,pStu pInsert,
						int (*pIDFind)(pStu pHead,pStu pInsert),
						pStu (*pInsertPosition)(pStu pHead,pStu pInsert));
//删除函数：pDelPosition:确定删除结点的位置
		int (*pDel)(pStu pHead,pStu (*pDelPosition)(pStu pNode,int age));
		//打印函数：打印链表数据
		void (*pPrint)(pStu pHead);
		//查找函数：pFun_Search:查找函数数组
		//分别支持按年龄查找和按ID查找
		int (*pSearch)(pStu pHead,
						int (*pFun_Search[2])(pStu pHead, int num));
		//保存函数
		int (*pStu_Save)(pStu pHead,FILE *fd);
}sList, *pList;

#endif
