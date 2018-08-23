#ifndef _INSERT_H_
#define _INSERT_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Student 
{
	char name[10];
	int age;
	int id;
	struct Student *next;
}sStu,*pStu;
pStu pHead;

pStu find_max(pStu pnew);
int inser_back(pStu pIn,pStu pPos);
void inser();

#endif
