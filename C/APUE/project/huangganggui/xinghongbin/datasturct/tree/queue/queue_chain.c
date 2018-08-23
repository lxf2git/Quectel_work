#include"queue.h"
void init_queue(pQueue *p)
{
		create_queue_memory( (void**) p, sizeof(sQueue));
		init_node((&(*p)->pw));	
		(*p)->pr = (*p)->pw;
}
void init_node(pNode *p)
{
		create_queue_memory( (void**)p, sizeof(sNode));
		(*p)->next = (*p);
		(*p)->prev = (*p);
}
void create_queue_memory(void**p,int size)
{
		*p = malloc(size);
}
int push(pQueue p,struct tree* pTemp)
{
		pNode pNew;
		init_node(&pNew);
		p->pw = p->pr->prev;
		pNew->pdata = pTemp;
		pNew->next = p->pw->next;
		pNew->prev = p->pw;
		p->pw->next->prev = pNew;
		p->pw->next = pNew;
		p->pw = pNew;
		return 0;

}

int pop(pQueue p,struct tree **pTemp)
{
		pNode pDel=p->pr->next;
		if(p->pr->next == p->pr)
		{
				printf("queue is empty\n");
				return -1;
		}
//		p->pw = p->pr->next;
		*pTemp = pDel->pdata;
		pDel->prev->next = pDel->next;
		pDel->next->prev = pDel->prev;
		if(pDel != NULL)
		{
				free(pDel);
				pDel = NULL;
		}
		return 0;

}













