#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#define COMPRESS z
//#define UNCOMPRE x
#define FAIL -1
#define REPEAT -2
#define EMPTY -3
#define SUC 1
typedef struct node
{
	char data;
	int weight;
	struct node *parent;
	struct node *next;
	struct node *lc;
	struct node *rc;
}sNode,*pNode;
typedef struct stack
{
	pNode bottom;
	pNode top;
}sStack,*pStack;
//stack
void init_stack(pStack *ps);
int push(pStack ps,int b);
int pop(pStack ps,int *pop_b);
//main
void show_tree(pNode proot);
void mid_tree(pNode pnode);
void show_chain(pNode pHead);
//init_free
void init_node(pNode *pnode);
void creat_memory(void **p,int size);
void free_node(pNode *pnode);
void free_memory(void **p);
void insert_back_chain(pNode pHead,pNode pnew);//尾插
void head_del(pNode pHead,pNode ptmp);//头删

//compress
int compress_file(char *fname);
void do_compress(FILE *pnf,FILE *pof,pNode pHead,pNode proot);
int push_data_node(pNode pHead,char ch,pStack ps);
char bin8_rev(char bt);
void save_huffman_tree(FILE * pnf,pNode pnode);
//deal_chain
void creat_chain(pNode pHead,FILE * fp);
void sort_chain(pNode *proot,pNode pHead);
void insert_sort_tree(pNode pnode,pNode pin);
void mid_sort_tree(pNode pnode,pNode pHead);
void break_chain(pNode pnode,pNode pHead);
//creat_huffman
pNode creat_huffman_tree(pNode pHead);
void connect_leaf(pNode pHead,pNode pnode);

//uncompress
int uncompress_file(char *fname);
void do_uncompress(FILE *phm,FILE *pc,pNode proot);

//read_huffman
void read_huffman_tree(pNode *pnode,FILE *fp);


#endif
