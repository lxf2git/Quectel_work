#include"stack_chain.h"
void create_memory(void **p,int size)
{
	*p = malloc(size);
	//if 
}

void init_node_stack(pNode *p)
{
	create_memory((void **)p,sizeof(sNode));
	(*p)->prev = *p;
	(*p)->next = *p;
		
}
pStack init_stack(int size)
{
	pStack ps = NULL;
	create_memory((void **)&ps,size);
	init_node_stack((&ps->bottom));
	ps->top = ps->bottom;
	return ps;
}

int push(pStack ps,void *tr)
{
	pNode pnew=NULL;
	init_node(&pnew);
	pnew->data = tr;

	pnew->next = ps->top->next;
	pnew->prev = ps->top;
	ps->top->next->prev = pnew;
	ps->top->next = pnew;
	ps->top = pnew;
	return SUC;
}

int is_empty(pStack ps)
{
	
	if(ps->bottom->next==ps->bottom)
	{
		return EMPTY;
	}
	return SUC;
}

void * pop(pStack ps)
{
	if(is_empty(ps))
	{
		return NULL;
	}

	pNode pdel=NULL;	
	void *da = NULL;
	da = ps->top->data;
	pdel = ps->top;
	ps->top->prev->next = ps->bottom;
	ps->bottom->prev = ps->top->prev;
	if(pdel!=NULL)
	{
		free(pdel);
		pdel = NULL;
	}

	ps->top = ps->bottom->prev;
	return da;
	
}









