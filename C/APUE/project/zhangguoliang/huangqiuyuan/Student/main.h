#ifndef _MAIN_H_
#define _MAIN_H_

#include<stdio.h>
#include<stdlib.h>
//#include"main.c"
//#include"show_age.c"
//#include"input.c"
typedef struct student
{
	int id;
	char name[10];
	int age;
	struct student *next;	
}Stu,*pStu;

#endif
