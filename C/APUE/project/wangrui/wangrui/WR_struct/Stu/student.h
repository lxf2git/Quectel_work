#ifndef _STUDENT_H_
#define _STUDENT_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	int id;
	char name[20];
	int age;
	struct node *next;
}sNode,*pNode;
enum
{
	INPUT=1,
	FIND,
	SAVE,
	PRINT,
	EXIT
};
void load_file(pNode phead);

void Init_node(pNode *p);
char Menu();
void creat_memory(pNode *p,int size);

void creat_input_chain(pNode phead);
void Input_chain(pNode phead,pNode pnew);
int judge(pNode phead,int nid);
void Insert_chain(pNode phead,pNode pnew);
pNode Find_pos(pNode phead,pNode pnew);

void show_chain(pNode phead);

void Destory_list(pNode *phead);
void Destory_node(pNode *p);

void find_age(pNode phead);

void save_file(pNode phead);

#endif
