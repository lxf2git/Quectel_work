#ifndef _MAIN_H_
#define _MAIN_H_


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define EMPTY -1
#define SUC 1
#define FAILED 0

typedef struct Tree
{
	int tr_data;
//	int tr_parent;
//	int tr_lt;
//	int tr_rt;
	struct Tree *tr_parent,*tr_lt,*tr_rt;
}sTree,*pTree;

//------------数组实现----------------------------
void create_memory(void **p,int size);
void init_tree(sTree str[],int num);
//void init_tree(pTree pstr);
void init_node(pTree *pstr);
void create_tree(sTree *pstr, int *parr, int num);
void add_node(pTree pstr,pTree pnew);
void mid_tree(pTree proot,int num);
void show_tree(pTree proot,int num);
void add_node_arr(pTree pstr, int *parr,int root,int n);

//-------------链表实现--------------------------
void creat_link_tree(pTree *pht,int *parr,int num);
void add_link_node(pTree ptr,pTree pnew);
void show_link_tree(pTree pht);

//-----删除------
void delete_link_node(pTree pht,int da);
int search_link(pTree pht,pTree pchange,pTree pnew);
int delete_node(pTree pht,pTree pnew,int b);
void replace_node(pTree *pdelh,pTree pnew, int a);
void free_memory(pTree *p);
//---------------------------------------


#endif
