#ifndef _MAIN_H_
#define _MAIN_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct tree
{
		char tr_data;
		struct tree *tr_parent;
		struct tree *tr_lc;
		struct tree *tr_rc;

}sTree,*pTree;

#endif
