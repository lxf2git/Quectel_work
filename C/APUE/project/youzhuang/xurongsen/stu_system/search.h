#ifndef _SEARCH_H__
#define _SEARCH_H_

#include"main_st.h"

int search(pStu phead,int (*pfun_sear[2])(pStu phead, int num));
int (*fun_sear[2])(pStu,int);
int sear_age(pStu phead,int num);
int sear_id(pStu phead,int num);






#endif
