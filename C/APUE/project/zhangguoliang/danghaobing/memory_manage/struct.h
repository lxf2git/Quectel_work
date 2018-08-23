#ifndef _STRUCT_H_
#define _STRUCT_H_

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
}sRc,*pRc;

#endif
