#ifndef _CHAIN_H_
#define _CHAIN_H_
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
		int id;
		char name[20];
		int age;
		char gender;
		struct node *next;
}sSode,*pSode;
enum en_name
{
		INPUT=1,
		INSERT,
		SAVE,
		PRINTF,
		EXIT,

};
void menu_chain(pSode p_head);
void chain_init(pSode *p);
void create_memory(pSode *p,int size);
int create_chain(pSode p_head);
int insert_chain(pSode p_head,pSode p_insert);
int find_repet(pSode p_head,int id);
int search_chain(pSode p_head);
int save_chain(pSode p_head);
void output_chain(pSode p_head);
void findtiall(pSode *p_pro);
void myfree(pSode *p);
void get_file();
int integer(int ch);
void exit_chain(int save,pSode p_head);
#endif
