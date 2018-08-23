#ifndef _STRUCT_H_
#define _STRUCT_H_
typedef struct tree
{
		char data;
		struct tree *lc;
		struct tree *rc;
}sTree,*pTree;

#endif
