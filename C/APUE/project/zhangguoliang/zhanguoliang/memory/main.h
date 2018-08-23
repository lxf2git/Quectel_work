#ifndef _MAIN_H_
#define _MAIN_H_

#include<stdio.h>
#include<stdlib.h>
#define N 10
enum
{
	 APPLY=1,
	 FREE,
	 PRINT,
	 EXIT=0
};

typedef struct memory
{
	int index;
	unsigned int mem_size;
	struct memory *prev;
	struct memory *next;
}sMem,*pMem;

typedef struct record
{
	pMem *pdata;
	struct record *prev;
	struct record *next;
}sRec,*pRec;

#endif
