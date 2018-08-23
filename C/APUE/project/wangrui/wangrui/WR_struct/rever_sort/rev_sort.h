#ifndef _REV_SORT_H_
#define _REV_SORT_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<glob.h>
typedef struct data
{
	char *file_name;//文件名
	int num;//次数
	struct data *prev;
	struct data *next;
}sData,*pData;

typedef struct word
{
	char *chword;//单词
	pData data;
	struct word *prev;
	struct word *next;
}sWord,*pWord;

typedef struct _and
{
	struct word *_and[10];//长度%10
}sAnd,*pAnd;

typedef struct mod
{
	struct _and *mod[26];//首尾字母相加%26
}sMod,*pMod;

//main
void search_word(pMod pmod);
void print_data(pWord pHead,char *iword);
void print(pMod pmod);
void print2(pWord pHead);

//init
void creat_memory(void **p,int size);
void init_data(pData *p);
void init_word(pWord *p);
void init_and(pAnd *p);
void init_mod(pMod *p);
//hash
void creat_hash_list(FILE *fp,char *fname,pMod pmod);
void insert_word(char *fname,pMod pmod,char *org_word);
void insert_new_word(pWord pHead,char *fname,char *new_word);
void insert_old_word(pData pdh,char *fname);
void get_word(char **new_word,int *len,char *org_word);
void get_head(pWord *pHead,pMod pmod,char *new_word,int len);
pWord judge_repeat(pWord pHead,char *new_word);
void convert_char(char *ch);
void insert_data_back(pData pdh,pData pdata);
void insert_word_back(pWord pHead,pWord pword);

#endif
