#ifndef _MAIN_H_
#define _MAIN_H_

#include<stdio.h>
#include<stdlib.h>
#include<glob.h>
#include<string.h>

#define M     26
#define N     10
#define L     20
#define SUC   0
#define FULL -1

typedef struct label_list
{
	int file_no;
	int num;
	struct label_list *next;
}sLabel,*pLabel;

typedef struct word_list
{
	char word[L];
	pLabel label;
	struct word_list *next;
}sWord,*pWord;

typedef struct And
{
	pWord and_[M];
}sAnd,*pAnd;

typedef struct Mod
{
	pAnd mod[N];
}sMod,*pMod;


#endif
