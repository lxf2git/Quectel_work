#ifndef _STACK_H_
#define _STACK_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 50
#define SUC 0
#define FULL -1
#define EMPTY -2


typedef struct stack
{
	int *bottom;
	int top;
}sStack,*pStack;

enum Choose
{
	TWO=1,
	EIGHT,
	SIXTEEN
};

void create_memory(void **q);
void init_stack(pStack ps);
int push(pStack ps, int mod);
int pop(pStack ps, int *pop_data);
void choose(sStack sta,sStack stb,sStack stc,int chos);
void show_two(sStack sta);
void show_eig(sStack sta);
int recur(int n);
void show_six(sStack sta);

#endif
