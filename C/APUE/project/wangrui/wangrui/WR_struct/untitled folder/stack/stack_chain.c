#include"stack_chain.h"
void create_memory(pNode *p)
{
	*p = (pNode)malloc(sizeof(sNode));
	//if 
}

void init_node(pNode *ps)
{
	create_memory(ps);
	(*ps)->prev = *ps;
	(*ps)->next = *ps;
		
}
void init_stack(pStack ps)
{
	init_node((&ps->bottom));
	ps->top = ps->bottom;
}

int push(pStack ps,int mod)
{
	pNode pnew=NULL;
	init_node(&pnew);
	pnew->data = mod;

	pnew->next = ps->top->next;
	pnew->prev = ps->top;
	ps->top->next->prev = pnew;
	ps->top->next = pnew;
	ps->top = pnew;
	return SUC;
}

int pop(pStack ps,int *pop_data)
{
	pNode pdel=NULL;	
	if(ps->bottom->next==ps->bottom)
	{
		return EMPTY;
	}
	 
	*pop_data = ps->top->data;
	
	pdel = ps->top;
	ps->top->prev->next = ps->bottom;
	ps->bottom->prev = ps->top->prev;
	if(pdel!=NULL)
	{
		free(pdel);
		pdel = NULL;
	}

	ps->top = ps->bottom->prev;
	
	return SUC;
}









