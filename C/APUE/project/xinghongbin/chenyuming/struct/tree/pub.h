#ifndef _PUB_H_
#define _PUB_H_

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "tree.h"
#include "stack.h"
#include "createtree.h"

#define PRBG printf("[%s]debug.\n", __FUNCTION__);
#define PRINT(data) printf("[%s]%d\n", __FUNCTION__, data);
#define PRINTCHAR(data) printf("[%s]%c\n", __FUNCTION__, data);
#define PRINTSTR(data) printf("[%s]%s\n", __FUNCTION__, data);

typedef struct{
	unsigned char data;
	struct tree _tree;
}sTreeNode, *pTreeNode;


typedef struct{
	struct tree *_tree;
	struct list _list;
}sTree_stack, *pTree_stack;

extern pStack stack;

#endif
