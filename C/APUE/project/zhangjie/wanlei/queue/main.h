#ifndef _MAIN_H_
#define _MAIN_H_

#include<stdio.h>
#include<stdlib.h>

#define SUC   0
#define FULL -1

typedef struct Tree
{
	char data;
	struct Tree *lc;
	struct Tree *rc;
}sTree,*pTree;

#endif
