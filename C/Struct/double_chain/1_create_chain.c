#include<stdio.h>
#include<stdlib.h>
/*
 *空链表状态（有头）
 phead->next = phead;
 phead->pre = phead;

 头结点的前驱指向最后一个结点 最后一个结点的后继指向头结点
 * */
typedef struct st
{
	int data;
	struct st *prev;
	struct st *next;
}sStu,*pStu;

void create_memory(pStu *pnode)
{
	*pnode = (pStu)malloc(sizeof(sStu));
	if(NULL==*pnode)
	{
		printf("malloc fail");
		exit(-1);
	}
}

void init_node(pStu *pnode)
{
	create_memory(pnode);
	(*pnode)->next = *pnode;
	(*pnode)->prev = *pnode;
}

void creat_head_chain(pStu pHead,int num)
{
	int i;
	pStu pnew=NULL;
	for(i=0;i<num;i++)
	{
		init_node(&pnew);
		pnew->data = i+1;
		pHead->next->prev = pnew;
		pnew->prev = pHead;
		pnew->next = pHead->next;
		pHead->next  = pnew;
	}
}
void creat_tail_chain(pStu pHead,int num)
{
	int i;
	pStu pnew=NULL;
	for(i=0;i<num;i++)
	{
		init_node(&pnew);
		pnew->data = i+1;
		pnew->prev = pHead->prev;
		pHead->prev->next = pnew;
		pHead->prev = pnew;
		pnew->next = pHead;
	}
	
}


void show_chain(pStu pHead)
{
	pStu ptmp=NULL;
	for(ptmp=pHead->next;ptmp!=pHead;ptmp=ptmp->next)
	{
		printf("%d ",ptmp->data);
	}
	printf("\n");
}

int main()
{
	pStu pHead=NULL;	
	init_node(&pHead); 
#ifdef _TAIL_CHAIN
	creat_tail_chain(pHead,10);
#else
	creat_head_chain(pHead,10);
#endif
	show_chain(pHead);
	return 0;

}
