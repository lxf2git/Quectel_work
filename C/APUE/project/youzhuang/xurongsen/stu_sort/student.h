#ifndef _STUDENT_H_
#define _STUDENT_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Student
{
	char name[20];
	int age;
	int id;
	struct Student *next;
}sStu,*pStu;

enum Menu
{
	INPUT=1,
	FIND,
	SAVE,
	PRINT,
	QUIT
};

void openfile(FILE **pin);
void create_memory(void **p, int size);
void init_node(pStu *pp,int size);
void input_message(pStu *pstu,FILE **pin);
void show_node(pStu pHead);
void save_file(pStu pHead,FILE *pin);
void find_age(int age,FILE *pin,pStu pHead);
void close_release(FILE **pin, pStu *ppHead);
void Destory_node(pStu *pp);
int id_look(pStu pHead,int id);
void choose(FILE **pin);

int insert_back(pStu pPos, pStu pIn);
pStu find_first_max(pStu pHead, pStu pnew);
#endif
