#ifndef _MAIN_H_
#define _MAIN_H_

#include<stdio.h>
#include<stdlib.h>

#define M 10
#define N 10
#define FULL -1
#define SUC   0

typedef struct memory
{
	int index;
	unsigned int mem_size;
	struct memory *prev;
	struct memory *next;
}sMem,*pMem;

typedef struct record
{
	pMem *p;
	struct record *prev;
	struct record *next;
}sRec,*pRec;

enum fun_name
{
	EXIT,
	APPLY,
	FREE,
	PRINT
};

int menu(pMem phead_app,pMem phead_free);

#endif
