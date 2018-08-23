#include"queue.h"
#include"insert.h"

void  init_node(pNode *p,int size)
{
	creat_memory((void **)p,size);
	(*p)->prev=(*p);
	(*p)->next=(*p);
}

void init_queue(pQue pq)
{
	init_node(&pq->bottom,sizeof(sNode));
	pq->pw=pq->bottom;
	pq->rw=pq->bottom;
}

int push(pQue pq,pTree pdata)
{
	pNode pnew=NULL;
	init_node(&pnew,sizeof(sNode));
	pnew->data=pdata;
//	printf("%p ",pq->bottom->prev);
	pnew->next=pq->bottom;
	pnew->prev=pq->bottom->prev;
	pq->bottom->prev->next=pnew;
	pq->bottom->prev=pnew;
	pq->pw=pnew;
	pq->rw=pq->bottom;
	//printf("1:%c ",pnew->data->data);
	return SUC;
}

int pop(pQue pq,pTree *data)
{
	if(pq->rw->next==pq->bottom)
	{
		return EMPTY;
	}
	*data=pq->rw->next->data;
	//printf("2:%c ",pq->rw->next->data->data);
	pNode pdel=pq->rw->next;
	pq->bottom->next=pdel->next;
	pdel->next->prev=pq->bottom;
	pdel->prev=NULL;
	pdel->next=NULL;
	i_free((void**)&pdel);
	return SUC;
}
