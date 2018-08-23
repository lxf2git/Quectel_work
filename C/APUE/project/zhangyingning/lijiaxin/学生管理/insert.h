#ifndef INSERT_H_
#define INSERT_H_
#include"main.h"
//void init_S(pStu *pHead);
//void create_chain(pStu pHead,pStu pnew);
int stu_Input(struct student *pnew);
pStu InsertPosition(pStu pTrav,pStu pInsert);
int IDFind(pStu pHead,pStu pInsert);
void creat_chain(pStu pp,pStu pInsert);
int ppInsert(pStu pHead,pStu pInsert,int(*pIDFind)(pStu,pStu),pStu(*pInsertPosition)(pStu ,pStu ));
#endif
