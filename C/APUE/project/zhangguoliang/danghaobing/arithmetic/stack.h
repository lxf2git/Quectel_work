#ifndef _STACK_H_
#define _STACK_H_
#include<stdio.h>
#include<stdlib.h>
typedef struct stackx
{
	char *bottom;
	int top;
}sStackx,*pStackx;
typedef struct stackn
{
	int *bottom;
	int top;
}sStackn,*pStackn;
#define FULL -1
#define EMPTY -2
#define	SIZE 50 
#define SUC 0

void init_stackx(pStackx);
void init_stackn(pStackn);
int pushx(pStackx,char);
int popx(pStackx,char *);
int pushn(pStackn,int);
int popn(pStackn,int *);

#endif
