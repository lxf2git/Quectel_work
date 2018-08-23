#ifndef _INIT_H_
#define _INIT_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Ch
{
		char ch[20];
		int word;
		int time;
		struct Ch *prev;
		struct Ch *next;
}sCh,*pCh;

typedef struct and
{
		struct Ch *and[26];
}sAnd,*pAnd;

typedef struct mod
{
		struct and *mod[26];
}sMod,*pMod;
#endif
