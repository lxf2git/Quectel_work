#ifndef _SHOOT_22_H_
#define _SHOOT_22_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Shoot
{
	
	int life;
	int id;
	struct Shoot *next;
}sSot,*pSot;

enum Menu
{
	INPUT=1,
	SHOOT,
	PRINT,
	QUIT
};

void create_memory(void **p,int size);
void init_node(pSot *pshoot);
int insert_back(pSot phead,pSot pnew);
void init_chain(pSot *pp,int  num);
void delete_node(pSot pos, pSot pout);
void shoot_down(pSot *pphead, int num, int shoot);
void show(pSot phead);
void choose_type(pSot *pphead,int num,int shoot);
void choose(pSot *pphead);


#endif
