#ifndef _MAIN_H_
#define _MAIN_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef	struct  memory
{
	int index;
	unsigned int mem_size;
	struct memory *prev;
	struct memory *next;
}sMem,*pMem;

typedef struct record
{
	pMem pdata;//记录申请下来的结点的地址
	struct record *prev;
	struct record *next;
}sRec,*pRec;


#endif
