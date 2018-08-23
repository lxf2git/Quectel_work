#ifndef _TOTAL_H_
#define _TOTAL_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum comand
{
	INSERT=1,
	DEL,
	SEARCH,
	PRINT,
	SAVE,
	EXIT,
};

typedef struct Student 
{
	char name[10];
	int age;
	int id;
	struct Student *next;
	void (*stu_print)(struct Student *);
	int (*stu_input)(struct Student *);
}sStu,*pStu;
pStu pHead;

#endif
