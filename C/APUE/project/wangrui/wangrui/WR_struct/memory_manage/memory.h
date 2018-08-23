#ifndef _MEMORY_H_
#define _MEMORY_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 10
#define FAIL -1
#define SUC 1
enum operate
{
	EXIT,
	APPLY,
	FREE,
	PRINT	
};
typedef struct memory
{
	int index;
	int size;
	struct memory *prev;
	struct memory *next;
}sMem,*pMem;

typedef struct record
{
	pMem pdata;
	struct record *prev;
	struct record *next;
}sRec,*pRec;


//main
int Menu();
//init_free
void creat_memory(void **p,int size);
void init_mem_node(pMem *pnode);
void init_rec_node(pRec *pnode);
void creat_mem_chain(pMem);
void insert_mem_back(pMem pHead,pMem pnew);
void delete_mem_node(pMem *pnode);
void free_memory(void **p);
void insert_rec_back(pRec pHead,pRec pnew);
void delete_rec_node(pRec *pnode);
int exit_free(pMem pHapp,pMem pHfre);

//print
void print(pMem pHapp,pMem pHfre);

//apply
int apply_mem(pMem pHapp,pMem pHfre);
void deal_area(pMem pHapp,pMem pHfre,int area);
void search_distribute(int size,pMem pHapp,pMem pHfre);
void insert_free_chain(pMem pHfre,pMem pnew);
void insert_record(pMem pnew);
int judge_area(pMem pHapp);
pMem traversal_mem_size(pMem pHapp,int size);
int traversal_mem_max(pMem pHapp);

//free
int free_mem(pMem pHapp,pMem pHfre);
void return_mem(pMem pHapp,pMem pHfre,pRec phrec);
int insert_mem_apply(pMem pHapp,pMem pnew);



#endif
