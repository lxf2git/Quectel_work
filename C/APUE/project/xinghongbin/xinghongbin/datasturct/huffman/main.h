#ifndef _MAIN_H
#define _MAIN_H
#include<stdio.h>
#include<stdlib.h>
typedef struct data_node
{
		int data;
		int num;
		int sign;
		struct data_node*parent;
		struct data_node*lc;
		struct data_node*rc;
		struct data_node*prev;
		struct data_node*next;

}sData,*pData;
typedef struct Bin
{
		char bin ;
		int char_num;
		int tailbin;
}sBin,*pBin;
void read_file(pData pHead);
void create_struct(pData pHead,int ch);
void same_struct(pData pHead,pData pInsert);
void insert_chain(pData pHead,pData pInsert);
void delete_chain(pData pHead,pData pDel);
void init_data(pData *p);
void create_memory(pData *p,int size);
void output_chain(pData pHead);
pData create_tree(pData pHead);
void create_tree_unit(pData pHead_tree,pData pHead);
void mid_show(pData pRoot);
void show_tree(pData pHead);
//pData search_data(pData pRoot,char ch);
pData search_data(pData pTemp, pBin p,pData pRoot);
void stat_sign(pData p);
void create_huffman(pData pHead);
#endif
