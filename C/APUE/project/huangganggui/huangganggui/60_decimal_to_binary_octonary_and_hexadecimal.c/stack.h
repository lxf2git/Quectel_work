#ifndef _STACK_H
#define _STACK_H

#include"main.h"
#include"bin.h"
int init_stack(pSta ps);
void create_memory(void **p, int size);
int pull(pSta ps,int data);
int pop(pSta ps, int *result);

#endif
