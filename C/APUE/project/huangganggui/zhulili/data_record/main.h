#ifndef _MAIN_H_
#define _MAIN_H_

#include<stdio.h>
#include<stdlib.h>
#include"judge.h"
#include"init.h"

typedef struct node
{
	int data;	
	struct node *prev;
	struct node *next;
}sNode,*pNode;

typedef struct dis_chain
{
	pNode record;
	struct dis_chain*next;
}sDis,*pDis;

#endif
