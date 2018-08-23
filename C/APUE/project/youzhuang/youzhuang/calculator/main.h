#ifndef _MAIN_H_
#define _MAIN_H_
#include"stack.h"
int add(int a,int b);
int sub(int a,int b);
int div_(int a,int b);
int mul(int a,int b);
int calc(pNum num,pSig sig,char data[SIZE]);
void operation(char ch,pNum num);
int judge_priority(char ch1,char ch2);
int judge_ch(char ch);
#endif
