#ifndef _MAIN_H_
#define _MAIN_H_
#include"total.h"
int file_get(char **all_file,char *argv);
int input_word(pMod hash,int file_nb);
void file_open(pMod hash,int file_nb,char **file_name,int word_nb);
void word_cmp(pMod hash,char **arr,int file_nb,int word_nb);
void func_sort(pMod hash,int word_nb,int file_nb);
void all_output(pMod hash,int word_nb,int file_nb);
void chance_output(pMod hash,int word_nb,int file_nb);
void word_output(pMod hash,int word_nb,int file_nb);
void file_output(pMod hash,int word_nb,int file_nb);

#endif
