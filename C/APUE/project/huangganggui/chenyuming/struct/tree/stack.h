#ifndef _STACK_H_
#define _STACK_H_

#include "pub.h"


typedef struct{
	unsigned int size;
	struct list *top;
	struct list _list;
}sStack, *pStack;

pStack InitStack();
void Push(pStack, struct list *);
struct list *Pop(pStack);


#endif
