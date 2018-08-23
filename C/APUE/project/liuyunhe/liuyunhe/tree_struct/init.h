#ifndef _INIT_H_
#define _INIT_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct tree
{
		int tr_data;
		struct tree *tr_parent;
		struct tree *tr_lc;
		struct tree *tr_rc;
}sTree,*pTree;

#endif
