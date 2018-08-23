#ifndef _STRUCT_H_
#define _STRUCT_H_

typedef struct tree
{
	char tr_data;
	struct tree *tr_lc;
	struct tree *tr_rc;
}sTree,*pTree;

#endif
