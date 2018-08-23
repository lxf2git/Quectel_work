#ifndef _STACK_H_
#define _STACK_H_

#include"main.h" 

#define SIZE  20
#define SUC    0
#define FULL  -1
#define EMPTY -2

typedef struct number
{
	int *num;
	int top;
}sNum,*pNum;

typedef struct Char
{
	char *ch;
	int top;
}sChar,*pChar;

void creat_memory(void **p,int size);
void init_num(pNum pn);
void init_ch(pChar pc);
int push_num(pNum pn,int num);
int push_char(pChar pc,char ch);
int pop_num(pNum pn,int *pop_num);
int pop_char(pChar pn,char *pop_ch);

#endif
