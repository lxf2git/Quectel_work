#ifndef _MAIN_H_
#define _MAIN_H_
#include<stdio.h>
#include<stdlib.h>
#include"struct.h"
enum {SAVE=1,FIND,EXIT=0};
void init_pMode(pMode *);
void save(pMode);
void find(pMode);
void Free_chain(pMode);
#endif
