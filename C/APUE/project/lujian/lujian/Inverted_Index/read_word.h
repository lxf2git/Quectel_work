

#ifndef READ_WORD_H
#define READ_WORD_H

#include<strings.h>
#include"creat_hash_lib.h"

int judge_ch(char ch);
Ppost find_post_ptail(Ppost phead);
Pword find_same_word(Pword phead, char* word);
Ppost find_same_post_file_id(Ppost phead, int file_id);
Pword find_word_ptail(Pword phead);
int add_post_back(Ppost pos, Ppost pin);
int add_word_back(Pword pos, Pword pin);

#endif 
