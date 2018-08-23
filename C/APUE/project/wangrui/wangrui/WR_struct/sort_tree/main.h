#ifndef _MAIN_H_
#define _MAIN_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 7
#define FAIL -1
typedef struct tree
{
	int data;
	struct tree *pa;
	struct tree *lc;
	struct tree *rc;
}sTree,*pTree;

void mid_tree(pTree pnode);
void show_tree(pTree proot);
void creat_tree(int *arr,pTree proot);
void insert(pTree pnode,int num);
void creat_arr(int *arr);
void init_node(pTree *pnode);
void creat_memory(void **p,int size);

void del_leaf(pTree pnode);
void del_limb(pTree pnode);
void del_root(pTree pnode);
pTree traversal_tree(pTree p,int num);
int deal_op(pTree proot,int num);
int delete_tree(pTree proot);
pTree find_left(pTree ptmp);

#endif
