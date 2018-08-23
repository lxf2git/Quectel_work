#ifndef _MAIN_H_
#define _MAIN_H_

#include<stdlib.h>
#include<stdio.h>


typedef struct node
{
	int id;
	char name[100];
	int age;
	struct node *next;
	
}sNode,*pNode;

void create_memory(pNode *p,int size);
void init_node(pNode *p,int size);
int insert_back(pNode pPos,pNode pIn);
pNode find_front(pNode pHead,pNode pnew);
void find_age(pNode p);
void Destory_Node(pNode *p);
void Destory_list(pNode *pHead);
pNode insert_chain(pNode pHead);
void save_file(pNode ptmp);
void print_information(pNode pHead);
void load(pNode p);
#endif


