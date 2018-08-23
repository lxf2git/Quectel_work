#ifndef _SHOW_H_
#define _SHOW_H_
#include<stdio.h>
#include"struct.h"
#include"stack.h"
void init_stack(pStack);
int push(pStack,pTree);
int pop(pStack,pTree *);
#endif
