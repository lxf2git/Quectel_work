#ifndef _MAIN_H_
#define _MAIN_H_

#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
	int *bottom;//定义栈底指针
	int top; //指针下标
}sStack,*pStack;

void two_jinzhi(pStack ps,int data,int mod,int *pop_data);
void ten_jinzhi(pStack ps,int data,int mod,int *pop_data);
void sixteen_jinzhi(pStack ps,int data,int mod,int *pop_data);
void init_stack(pStack stack);
int push(int mod,pStack ps);
int pop(pStack ps,int *pop_data);

#define SIZE 30
#define FULL -1
#define EMPTY -2
#define SUC 0


#endif

