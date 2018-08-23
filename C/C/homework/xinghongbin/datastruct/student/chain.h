#ifndef _CHAIN_H_
#define _CHAIN_H_
#include<stdio.h>
#include<stdlib.h>
#include"struct.h"

void create_chain(pStu pHead,pList plist);
int input_fun(pStu p);
int chain_insert ( pStu pHead , pStu pInsert , pIDFind pid, pInsertp pspiont);
int id_find ( pStu pHead , pStu pInsert );
pStu insert_position( pStu pHead , pStu pInsert);
void chain_output(pStu pHead);
void output_fun(pStu p);
#endif
