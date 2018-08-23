#ifndef _SAVE_H_
#define _SAVE_H_
#include<stdio.h>
#include"struct.h"
void init_file(pStu pHead,pList plist);
void open_file(pStu pHead,pList plist);
int save_chain(pStu pHead,FILE *fp);
int read_chain(pStu pHead,FILE *fp);
#endif
