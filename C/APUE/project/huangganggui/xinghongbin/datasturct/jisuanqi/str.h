#ifndef _STR_H
#define _STR_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Sign
{
		char sign;
		int number;
		int bf;
		int af;
		struct Sign *next;
		struct Sign *prev;
}sSig,*pSig;
void sort_char(char **argv,int *p,pSig pHead);                                   //分检命令行参数
void deal_figure(char **argv,int i,int number,int *p);                         //字符数字化
int num_or_sign(char **argv,int i);			//字符范围确定				
int ten_power(int i);                                           // 10的次方
void create_memory(void ** p,int size);
void deal_sign(char **argv,int i,int number,pSig pHead,int *arr);
int sign_priority(char sign);
void chain_init(pSig *p);
#endif
