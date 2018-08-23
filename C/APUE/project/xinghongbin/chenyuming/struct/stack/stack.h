#ifndef _STACK_H_
#define _STACK_H_

#include "pub.h"

typedef struct Stack_node{
	type data;
	struct list  _list;
}sSKNode, *pSKNode;


pStack InitStack();
void Push(pStack, type element);
type Pop(pStack);


#endif
