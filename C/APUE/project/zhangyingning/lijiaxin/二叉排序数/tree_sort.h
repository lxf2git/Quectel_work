#ifndef TREE_SORT_H_
#define TREE_SORT_H_
typedef struct tree
{
		char tr_data;
		struct tree *tr_lc;
		struct tree *tr_rc;
}sTree,*pTree;
pTree *p;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50
void get_memory(void **p,int size);
void init_tree(pTree *p);
void creat_tree_chain(pTree root,pTree pnew);
void creat_tree(pTree pHead,char *str,int n);
int creat_(pTree pHead);
void show_tree(pTree root);
int print_(pTree pHead);
pTree mid_find(pTree root,char ch,pTree *parent,int *flag);
pTree remake_tree_chain(pTree root,pTree *parent1,int *flag1);
void remake_tree(pTree root,pTree parent,int flag);
int delete_(pTree pHead);
#endif
