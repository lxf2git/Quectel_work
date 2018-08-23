#ifndef _INSERT_H_
#define _INSERT_H_

#include"main_st.h"


//函数指针的声明
int (*pinfind)(pStu phead, pStu pin);
pStu (*pinposite)(pStu phead, pStu pin);

//函数定义
//查找id是否重复
int find_id(pStu phead, pStu pinsert);
//查找插入的位置
pStu posite_in(pStu phead, pStu pin);
int insert(pStu phead,pStu pin,int (*pidfind)(pStu phead,pStu pin),
						pStu (*pinposite)(pStu phead,pStu pin));

//在pos之后插入pin
int insert_back(pStu pos,pStu pin);
//输入信息
void stu_in(struct Student * pin);
//调用指针
pStu pfun_in();

#endif
