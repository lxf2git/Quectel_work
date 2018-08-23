#ifndef _DEL_H_
#define _DEL_H_
#include<stdio.h>
#include<stdlib.h>

#include"struct.h"
pStu DelPosition(pStu,int);
int Del(pStu,pStu(*)(pStu,int));
void dele(pStu);


#endif
