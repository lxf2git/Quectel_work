#ifndef CREAT_HASH_LIB_H
#define  CREAT_HASH_LIB_H

#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
#include<glob.h>
#define  LEN    (256)
#define  N 		(52)
#define  TURE   (1) 
#define  FALSE  (-1) 

typedef struct Postinglist
{
	int file_id;
	int word_f;
	struct Postinglist* prev;
	struct Postinglist* next;

}Spost, *Ppost;

typedef struct Word_list
{
	char word[LEN];
	int word_id;
	Ppost phead_post;
	
	struct Word_list* prev;
	struct Word_list* next;	

}Sword, *Pword;

typedef struct Sechash
{
	Pword pword_last[N];

}Ssec, *Psec;

typedef struct Firsthash
{
	
	Psec pword_one[N];

}Sfirst, *Pfirst;

int creat_memory(void ** q, int size);
int init_post_node(Ppost* p);
int init_word_node(Pword* p);
int hash1(char* word);
int hash2(char* word);

#endif 
