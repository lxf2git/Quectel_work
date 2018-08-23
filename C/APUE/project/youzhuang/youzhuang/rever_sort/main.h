#ifndef _MAIN_H_
#define _MAIN_H_
#include<stdio.h>
#include<stdlib.h>
#include<glob.h>
#include<string.h>
#define EMPTY -1
#define SUB 0
#define ROW 20
#define COL 26
#define WORD_LEN 20
enum {ADDFILE=1,FINDWORD,EXIT};
typedef struct label_list
{
		int file_no;
		int num;
		struct label_list *next;
}sLabel,*pLabel;
typedef struct word_list
{
		char *word;
		struct label_list *label;
		struct word_list *prev;
		struct word_list *next;
}sWord,*pWord;
typedef struct letter_hash
{
		struct word_list *letter[COL];
}sLetter,*pLetter;
typedef struct mod_hash
{
		struct letter_hash *mod[ROW];
}sMod,*pMod;
int menu(pMod hash);
int fun(int function,pMod hash);
void create_memory(void **p,int size);
void free_memory(void **p);
void file(pMod hash);
int judge_way(char ch[]);
void read_file(pMod hash,glob_t globres);
void insert_hash(pMod hash,char word[],int i);
int word_mod(char word[]);
int word_letter(char word[]);
void create_col(pMod hash,int hash_row);
void create_word_list(pMod hash,int hash_row,int hash_col);
void init_word_list(pWord *pnew);
void init_hash(pMod hash);
void init_label_list(pLabel *p);
void insert_word(pWord phead,pWord pnew);
void insert_label(pLabel phead,pLabel pnew);
pWord find_word(pWord phead,char word[]);
pLabel find_label(pLabel phead,int file_no);
void copy_word(char **dest,char src[]);
void find(pMod hash);
void output_word(pWord pword);
#endif
