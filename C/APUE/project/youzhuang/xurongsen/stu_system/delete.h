#ifndef _PRINT_H_
#define _PRINT_H_

#include"main_st.h"

int del(pStu phead, pStu(*pdelsite)(pStu pnode,int age));

pStu(*pdelsite)(pStu pnode, int age);
pStu del_age(pStu pnode,int age);








#endif
