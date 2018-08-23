#ifndef _DELETE_H
#define _DELETE_H
#include"main.h"

int delete(pStu pHead, pStu (*pDelPosition)(pStu pNode,int age));
pStu find_node_with_id(pStu pHead, int id);
pStu find_node_with_age(pStu pHead, int age);
void delete_node(pStu pHead, pStu *pDelNode);
void free_node(pStu *pNode);


#endif
