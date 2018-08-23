#ifndef _CALCULATE_H_
#define _CALCULATE_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50
#define FULL -1
#define EMPTY -2
#define ERR -3
#define SUC 0
#define OVER 1

enum Operate
{
	SAVE_NUM,
	LOAD_NUM,
	DEAL_SIGN
};
typedef struct stack1
{
	int *bottom;
	int top;
}sStack1,*pStack1;

typedef struct stack2
{
	char *bottom;
	int top;
}sStack2,*pStack2;

int (*poperate[3])(pStack1,pStack2,char);
//stack
void creat_memory(void **p,int size);
void init_stack_int(pStack1 psd);
void init_stack_char(pStack2 psc);
int push_int(pStack1 psd,int num);
int push_ch(pStack2 psc,char sign);
int pop_int(pStack1 psd,int *pop_num);
int pop_ch(pStack2 psc,char *pop_sign);
//operate
int save_num(pStack1,pStack2,char);
int load_num(pStack1,pStack2,char);
int deal_sign(pStack1 psd,pStack2 psc,char data);
int cal_num(pStack1 psd,char pop_sign);
//deal
int deal(pStack1 psd,pStack2 psc);
int judge(char c1,char c2);

#endif
