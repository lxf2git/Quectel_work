#ifndef HASH_H_
#define HASH_H_
struct data
{
		int data;
		struct data *prev;
		struct data *next;
};
struct and_
{
		struct data *and[8];
};
struct mod
{
		struct and_ *mod[5];
};
#include<stdio.h>
#include<stdlib.h>
void get_memory(void **q,int size)
{
		*q = malloc(size);
		if(*q==NULL)
		{
				printf("malloc error\n");
				exit(-1);
		}
}
void my_free(void **q)
{
		if(*q!=NULL)
		{
				free(*q);
				*q = NULL;
		}
}
#endif
