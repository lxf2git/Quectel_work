#include"queue.h"
void create_memory(void **p,int size)
{
		*p =  malloc(size);
		if(NULL==*p)
		{
				printf("mallocerror\n");
				exit(-1);
		}
}
void init_node(pNode *ps)
{
		create_memory((void **)ps,sizeof(sNode));
		(*ps)->prev = *ps;
		(*ps)->next = *ps;
}
pQueue init_queue(int size)
{
		pQueue ppp=NULL;
		create_memory((void **)&ppp,size);
		init_node(&ppp->bottom);
		ppp->pw = ppp->bottom;
		ppp->pr = ppp->bottom;
		return ppp;
}
int push(pQueue ps,pTree root)
{
		if(root==NULL)
		{
				return FULL;
		}
		pNode pnew = NULL;
		init_node(&pnew);
		pnew->data = root;
		pnew->next = ps->bottom;
		pnew->prev = ps->bottom->prev;
		ps->bottom->prev->next = pnew;
		ps->bottom->prev = pnew;
		ps->pw = pnew;
		ps->pr = ps->bottom->next;
		return SUC;
}
pTree pop(pQueue ps)
{
		if(ps->bottom == ps->pr)
		{
				return NULL;
		}
		pNode pdel= NULL;
		pdel = ps->pr;
		pTree da = pdel->data;
		ps->bottom->next = ps->pr->next;
		ps->pr->next->prev = ps->bottom;
		if(pdel !=NULL)
		{
				free(pdel);
				pdel = NULL;
		}
		ps->pr = ps->bottom->next;
		return da;
}

