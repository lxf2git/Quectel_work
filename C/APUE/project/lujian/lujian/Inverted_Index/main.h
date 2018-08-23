
#ifndef MAIN_H
#define  MAIN_H

#include"creat_hash_lib.h"
enum Menu
{
	indexword =1,
	print,
	breakout,

};

int read_word(FILE* fp, Pfirst pf_hash, int file_id);

int index_word(Pfirst pf_hash);

#endif 
