#ifndef _TOTAL_H_
#define _TOTAL_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<glob.h>
#define N 20			//单词最大数
#define M 10			//文件最大数
typedef struct Data
{
	char word[N];
	int nb;
}sData,*pData;
typedef struct Word
{
	pData *an;
}sAnd,*pAnd;
typedef struct File
{
	pAnd *mod;
}sMod,*pMod;
enum Node
{
	CHANCE_OUTPUT=1,
	ALL_OUTPUT,
	EXIT,
};
void getmemory(void **p,int size);
void init_data(pData *p,int size);

#endif
