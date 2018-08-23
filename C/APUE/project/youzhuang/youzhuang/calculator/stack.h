#ifndef _STACK_H_
#define _STACK_H_

#define SUCCESS 0
#define FULL -1
#define EMPTY -2
#define SIZE 50
#include<stdio.h>
#include<stdlib.h>
typedef struct number
{
		int *bottom;
		int top;
}sNum,*pNum;
typedef struct sign
{
		char *bottom;
		int top;
}sSig,*pSig;
void create_memory(void **p);
void init_stack(pNum num,pSig sig);
int push_num(pNum num,int value);
int push_sig(pSig sig,char value);
int pop_num(pNum num,int *value);
int pop_sig(pSig sig,char *value);

#endif
