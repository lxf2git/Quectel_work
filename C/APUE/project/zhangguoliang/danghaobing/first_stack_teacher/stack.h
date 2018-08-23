#ifndef _STACK_H_
#define _STACK_H_
#include<stdio.h>
#include<stdlib.h>
#include"struct.h"
typedef struct node
{
		pTree data;
		struct node *prev;
		struct node *next;
}sNode,*pNode;
typedef struct stack_chain
{
		pNode bottom;
		pNode top;
}sStack,*pStack;

#define SUC 0
#define FULL -1
#define EMPTY -2


#endif
