#include"main.h"

void init_stack(pStack *psta)
{
	creat_memory((void**)psta,sizeof(sStack));
	init_node(&(*psta)->bottom);
	(*psta)->top = (*psta)->bottom;
}

int push(pStack ps,int mod)
{
	pNode pnew;
	init_node(&pnew);
	pnew->data = mod;
	ps->top->next = pnew;
	ps->bottom->prev = pnew; 
	pnew->prev = ps->top;
	pnew->next = ps->bottom;
	ps->top = pnew;
}

int pop(pStack ps,int *pop_data)
{
	pNode pdel = NULL;
	if(ps->top == ps->bottom)
	{	
		return EMPTY;
	}
	pdel = ps->top;
	*pop_data = ps->top->data;
	ps->top = ps->top->prev;
	
	ps->bottom->prev = ps->top;
	ps->top->next = ps->bottom;
	pdel->prev = NULL;
	pdel->next = NULL;
	free_memory((void**)&pdel);
}
