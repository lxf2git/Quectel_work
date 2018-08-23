#ifndef _MAIN_H_
#define _MAIN_H_
#include<stdio.h>
#include<stdlib.h>
#include"apply.h"
#include"free.h"
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
}sr,*pr;

#endif
