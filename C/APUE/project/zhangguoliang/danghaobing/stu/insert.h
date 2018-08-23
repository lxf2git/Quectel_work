#ifndef _INSERT_H_
#define _INSERT_H_
#include "main.h"

int stu_in(struct student *);//学生输入函数
pStu InsertPosition(pStu,pStu);
int Insert(pStu,pStu,int (*)(pStu,pStu),pStu (*)(pStu,pStu));
int IDFind(pStu,pStu);
pStu Insert_pnew();


#endif
