#ifndef _STRUCT_H_
#define _STRUCT_H_

typedef struct data
{
	int data;
	struct data *prev;
	struct data *next;
}sData,*pData;

typedef struct and
{
	struct data *and[8];
}sAnd,*pAnd;

typedef struct mode
{
	struct and *mod[5];
}sMode,*pMode;

#endif
