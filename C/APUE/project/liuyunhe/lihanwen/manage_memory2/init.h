#ifndef _INIT_H_
#define _INIT_H_
#include<stdlib.h>

typedef struct memory
{
	int index;
	int mem_size;
	struct memory *prev;
	struct memory *next;
}sMem,*pMem;

typedef struct record
{
	pMem *pdata;
	struct record *prev;
	struct record *next;
}sRec,*pRec;

void creat_memory(pMem *p);
void init_memory(pMem *p);

#endif

