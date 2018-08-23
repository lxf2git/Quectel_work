
#ifndef QUEUE_H
#define QUEUE_H

#define  SIZE   (5)
#define  TURE   (1) 
#define  FALSE  (-1) 
#define  FULL    (1)
#define  EMPTY   (0)
#include<stdio.h> 
#include<stdlib.h> 

//循环队列先进先出， 后进后出
typedef struct Queue
{
	char arr[SIZE];
	int pw; // 指向队尾的下一个元素
	int pr; // 指向队头元素

}Squeue, *Pqueue;

 int init_queue(Pqueue pque);
int push_queue(Pqueue pque, char data);
int  pop_queue(Pqueue pque, char* pop_data);
int judge_queue(Pqueue pque);
		

#endif 
