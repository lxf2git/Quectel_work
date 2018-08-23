#ifndef _MAIN_H_
#define _MAIN_H_
#include<stdio.h>
#include<stdlib.h>
#define N 10
#define EMPTY 0
#define SUB 1
typedef struct data
{
		int *arr;
		int low;
		int high;
		struct data *prev;
		struct data *next;
}sData,*pData;
typedef struct stack
{
		struct data *bottom;
		struct data *top;
}sSta,*pSta;
void output(int arr[N]);
void pop(pSta ps,int arr[N],int *low,int *high);
void push(pSta ps,int arr[N],int low,int high);
void init_stack(pSta *ps);
void init_node(pData *p);
void create_memory(void **p,int size);
void free_memory(void **p);
void quick_sort(int arr[N],int low,int high);
int sort(int arr[N],int low,int high);
void swap(int arr[],int low,int high);
int stack_empty(pSta ps);
#endif
