#include"tree2.h"


void init_queue(pQueue *pq)
{
	creat_memory((void**)pq,sizeof(sQueue));
	init_node(&(*pq)->qhead);
	(*pq)->write = (*pq)->qhead->prev;
	(*pq)->read = (*pq)->qhead->next;
}

int push_queue(pQueue pq,pTree pmod)
{
	pNode pnew = NULL;
	init_node(&pnew);
	pnew->pdata = pmod;
	
	pnew->prev = pq->write;
	pnew->next = pq->qhead;
	pq->write->next = pnew;
	pq->qhead->prev = pnew;
	pq->write = pnew;
	pq->read = pq->qhead->next;
	return SUC;
}
int pop_queue(pQueue pq,pTree *pop_tree)
{
	pNode pdel = NULL;
	if(pq->read == pq->qhead)
	{
		return EMPTY;
	}
	*pop_tree = pq->read->pdata;
	pdel = pq->read;
	pdel->next->prev = pq->qhead;
	pq->qhead->next = pdel->next;
	pdel->next = NULL;
	pdel->prev = NULL;

	pq->read = pq->qhead->next;
	pq->write =pq->qhead->prev;
	free_memory((void**)&pdel);
	return SUC;
}
