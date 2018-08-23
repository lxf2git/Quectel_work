#ifndef _STACK_H_
#define _STACK_H_
#include<stdlib.h>
#include<stdio.h>

typedef struct stack_in
{
		int *data_head;
		int top;
}sStack_in,*pStack_in;


typedef struct stack_ch
{
		char *bottom;
		int top;
}sStack_ch,*pStack_ch;

#define FULL -2
#define SCU 0
#define EMPTY -1
#endif
