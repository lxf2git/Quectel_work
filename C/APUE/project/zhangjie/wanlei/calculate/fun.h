#ifndef _FUN_H_
#define _FUN_H_

#include"main.h"

#define EQUAL    2
#define LESS    -1
#define MORE     1
#define LIFT     3
#define RIGHT   -3

int func(char ch,int x,int y);
int fun(int(*pf)(int,int),int x,int y);
int add(int x,int y);
int dec(int x,int y);
int mul(int x,int y);
int div_(int x,int y);

#endif
