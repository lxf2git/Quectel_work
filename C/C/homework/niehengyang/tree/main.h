#ifndef _MAIN_H_
#define _MAIN_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct tree
{
	int data;
	struct tree *parent;
	struct tree *lc;
	struct tree *rc;
}sTr,*pTr;

#endif
